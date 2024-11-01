#pragma once

#include <type_traits>
#include <typeinfo>
#include <unordered_map>

#include "observer_notification.hpp"
namespace DesignPattern 
{
    namespace Observer
    {
        template <typename ...T>
        class Observer; 

        template <>
        class Observer<>
        {   
        protected:
            Observer(){}
        public:
            virtual ~Observer(){};
            
            std::unordered_map<std::size_t, ObserverBase*> observer_map()
            {
                return std::unordered_map<std::size_t, ObserverBase*>();
            }
        };

        template <typename T1, typename ...Tn>
        class Observer<T1, Tn...> : public Observer<Tn...>
                                , public virtual T1
        {
            static_assert(std::is_base_of<ObserverBase, T1>::value, "Must derived class of ObserverBase");
        protected:
            Observer(){}
        public:
            virtual ~Observer(){};

            std::unordered_map<std::size_t, ObserverBase*> observer_map()
            {
                std::unordered_map<std::size_t, ObserverBase*> ret = Observer<Tn...>::observer_map();
                ret[T1::event()] = static_cast<T1*>(this);
                return ret;
            }
        };
    }
}

