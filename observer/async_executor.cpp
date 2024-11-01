#include "async_executor.hpp"

namespace DesignPattern 
{
    namespace Observer
    { 
        AsynchronousExecutor::AsynchronousExecutor(const std::size_t dispatchers)
        {
            std::size_t n = dispatchers < std::thread::hardware_concurrency() / 2U ? dispatchers : std::thread::hardware_concurrency() / 2U;
            n = n > 0U ? n : 1U;
            
            _running = true;
            for (std::size_t i = 0U ; i < n; i++)
            {
                _pool.emplace_back(std::thread(&AsynchronousExecutor::thread_proc, this));
            }
        }

        AsynchronousExecutor::~AsynchronousExecutor()
        {
            if (!_pool.empty())
            {
                _running =false;
                    _cv.notify_all();

                for (std::thread& t : _pool)
                {
                    if (t.joinable()) t.join();
                }
            }

            AsynchronousExecutionBase* p = nullptr;                
            const std::lock_guard<std::mutex> lock(_mu_q);
            while (!_q.empty())
            {
                p = _q.front();
                delete p;
                _q.pop();
            }
        }

        bool AsynchronousExecutor::enqueue(AsynchronousExecutionBase* p)
        {
            bool ret(false);
            if (p != nullptr)
            {
                {
                    const std::lock_guard<std::mutex> lock(_mu_q);
                    _q.push(p);
                }
                _cv.notify_one();
                ret = true;
            }
            return ret;
        }

        AsynchronousExecutionBase* AsynchronousExecutor::get()
        {
            AsynchronousExecutionBase* ret(nullptr);
            {
                const std::lock_guard<std::mutex> lock(_mu_q);
                if (!_q.empty())
                {
                    ret = _q.front();
                    _q.pop();
                }
            }
            return ret;
        }

        void AsynchronousExecutor::thread_proc()
        {
            AsynchronousExecutionBase* p(nullptr);
            while (_running)
            {   
                std::unique_lock<std::mutex> lk(_mu_cv);
                _cv.wait(lk);                        
                if (!_running) break;                
                do
                {
                    if ((p = get()) != nullptr)
                    {   
                        p->execute();
                        delete p;
                    }
                } while(p != nullptr);
                lk.unlock();
            }
        }
    }
}