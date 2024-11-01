#pragma once
#include <typeinfo>

namespace DesignPattern 
{
    namespace Observer
    {
        struct ObserverBase
        {
            virtual ~ObserverBase(){}
        };

        class SubjectBase;

        template <typename ...Tn>
        class ObserverNotification;

        template <typename E>
        class ObserverNotification<E> : public ObserverBase
        {
        public:
            virtual ~ObserverNotification(){}
            virtual bool on_notified(const SubjectBase * const, const E* const) = 0;
            static const std::size_t event()
            {
                return typeid(E).hash_code();
            }
        };

        template <typename E, typename ...Tn>
        class ObserverNotification<E, Tn...> : public ObserverBase
        {
        public:
            virtual ~ObserverNotification(){}
            virtual bool on_notified(const SubjectBase * const, const E* const, Tn...) = 0;
            static const std::size_t event()
            {
                return typeid(E).hash_code();
            }
        };
    }
}