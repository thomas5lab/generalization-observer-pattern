#pragma once

#include <typeinfo>
#include <memory>
#include <unordered_map>
#include <list>

#include "observer_notification.hpp"

namespace DesignPattern 
{
    namespace Observer
    {
        class ObserverCollection;

        class SubjectBase
        {
        protected:
            SubjectBase();
        public:
            virtual ~SubjectBase();

            template<typename E>
            bool observe(ObserverBase* ob, const E* const)
            {
                return observe(typeid(E).hash_code(), ob);
            }

            template<typename E>
            bool observe(const std::unordered_map<std::size_t, ObserverBase*>& obs, const E* const)
            {
                bool ret(false);
                const size_t code = typeid(E).hash_code();
                std::unordered_map<std::size_t, ObserverBase*>::const_iterator it(obs.cend());
                if ((it = obs.find(code)) != obs.cend())
                {
                    ret = observe(code, it->second);
                }

                return ret;
            }

            template<typename E1, typename ...En>
            bool observe(const std::unordered_map<std::size_t, ObserverBase*>& obs, const E1* const, const En* const... events)
            {
                bool ret(false);
                const size_t code = typeid(E1).hash_code();
                std::unordered_map<std::size_t, ObserverBase*>::const_iterator it(obs.cend());
                if ((it = obs.find(code)) != obs.cend())
                {
                    ret = observe(code, it->second);
                }

                return observe(obs, events...) && ret;
            }


            void remove(ObserverBase* ob);
            void remove(const std::unordered_map<std::size_t, ObserverBase*>& obs);

        protected:
            std::list<ObserverBase*> get_observer(const std::size_t code);

        private:    
            bool observe(const std::size_t code, ObserverBase* ob);
            void remove(const std::size_t code, ObserverBase* ob);

        private:
            std::shared_ptr<ObserverCollection> _collection;
        };


        struct Synchronous{};
        template <typename T = Synchronous>
        class Subject;
    }
}