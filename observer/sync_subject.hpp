#pragma once

#include "subject_base.hpp"

namespace DesignPattern 
{
    namespace Observer
    {
        template <>
        class Subject<Synchronous> : public SubjectBase
        {
        protected:
            Subject(){};

        public:
            virtual ~Subject(){};

        protected:
            template <typename E, typename ...Tn>
            bool notify(const E* const, Tn... args)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, Tn...>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (nullptr == p)
                    {
                        ret = false;
                        continue;
                    }

                    try {
                        ret = p->on_notified(this, ev, args...) && ret;
                    } catch (...) {
                        ret = false;
                    }
                }
                
                return ret;
            }
        };
    }
}