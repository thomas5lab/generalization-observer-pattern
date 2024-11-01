#pragma once

#include <mutex>
#include <thread>
#include <queue>
#include <vector>
#include <condition_variable>

#include "async_execution_base.hpp"

namespace DesignPattern 
{
    namespace Observer
    {
        class AsynchronousExecutor final
        {
        public:
            AsynchronousExecutor(const std::size_t dispatchers);
            ~AsynchronousExecutor();

            bool enqueue(AsynchronousExecutionBase* p);

        private:
            AsynchronousExecutionBase* get();
            void thread_proc();

        private:
            std::queue<AsynchronousExecutionBase*> _q;
            std::mutex _mu_q;
            std::vector<std::thread> _pool;
            bool _running;
            std::mutex _mu_cv;
            std::condition_variable _cv;
        };
    }
}