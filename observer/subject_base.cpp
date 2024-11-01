#include <mutex>

//#include "spinlock.hpp"

#include "subject_base.hpp"

namespace DesignPattern 
{
    namespace Observer
    {
        struct copyable_mutex : std::mutex
        {
            copyable_mutex() = default;
            copyable_mutex(const copyable_mutex&) noexcept : std::mutex(){} // change semantic
            bool operator == (const copyable_mutex& o){ return this == &o; }
        };
        using locktype = copyable_mutex;

        class ObserverCollection final
        {
        public:
            ObserverCollection()
            {

            }

            bool add(const std::size_t code, ObserverBase* ob)
            {
                bool ret(false);
                const std::lock_guard<locktype> lock(_spin);
                if (_map.find(code) != _map.end())
                {
                    _map[code].push_back(ob);
                }
                else
                {
                    std::list<ObserverBase*> l;
                    l.push_back(ob);
                    _map[code] = l;
                }
                return true;
            }

            void remove(ObserverBase* ob)
            {
                std::list<ObserverBase*>::iterator its;
                const std::lock_guard<locktype> lock(_spin);
                for (auto element : _map)
                {
                    element.second.remove(ob);
                }
            }

            void remove(const std::size_t code, ObserverBase* ob)
            {
                const std::lock_guard<locktype> lock(_spin);
                std::unordered_map<std::size_t, std::list<ObserverBase*>>::iterator it(_map.end());
                if ((it = _map.find(code)) != _map.end())
                {
                    it->second.remove(ob);
                }
            }

            std::list<ObserverBase*> get(const std::size_t code)
            {
                static std::list<ObserverBase*> ret;
                
                const std::lock_guard<locktype> lock(_spin);
                std::unordered_map<std::size_t, std::list<ObserverBase*>>::iterator it(_map.end());
                if ((it = _map.find(code)) != _map.end())
                {
                    ret = it->second;
                }
                return ret;
            }

        private:
            std::unordered_map<std::size_t, std::list<ObserverBase*>> _map;
            locktype _spin;
        };


        SubjectBase::SubjectBase()
        {
            _collection = std::make_shared<ObserverCollection>(ObserverCollection());
        }

        SubjectBase::~SubjectBase()
        {
            _collection.reset();
        }


        void SubjectBase::remove(ObserverBase* ob)
        {
            if(_collection)
            {
                try {
                    _collection->remove(ob);
                } catch(...) {

                }
            }
        }

        void SubjectBase::remove(const std::unordered_map<std::size_t, ObserverBase*>& obm)
        {        
            for (auto element : obm)
            {
                remove(element.first, element.second);
            }
        }

        std::list<ObserverBase*> SubjectBase::get_observer(const std::size_t code)
        {
            std::list<ObserverBase*> ret;
            if(_collection)
            {
                try {
                    ret = _collection->get(code);
                } catch(...) {
                }
            }
            return ret;
        }

        bool SubjectBase::observe(const std::size_t code, ObserverBase* ob)
        {
            bool ret(false);
            if(ob != nullptr && _collection)
            {
                try {
                    ret = _collection->add(code, ob);
                } catch(...) {
                }
            }
            return ret;
        }

        void SubjectBase::remove(const std::size_t code, ObserverBase* ob)
        {
            if(_collection)
            {
                try {
                    _collection->remove(code, ob);
                } catch(...) {

                }
            }
        }
    }
}