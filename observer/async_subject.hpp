#pragma once

#include "async_execution.hpp"
#include "async_executor.hpp"

namespace DesignPattern 
{
    namespace Observer
    {
        struct Asynchronous{};

        class AsynchronousExecutor;

        template <>
        class Subject<Asynchronous> : public SubjectBase
        {
        protected:
            Subject(const std::size_t dispatchers = 1U);

        public:
            virtual ~Subject();

        protected:
#if __cpp_version >= 201402L
            template <typename E, typename ...Tn>
            bool notify(const E* const, Tn... args)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, Tn...>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {   
                    ret = enqueue(new AsynchronousExecution<E, Tn...>(ob, &Notification::on_notified, this, ev, args...)) && ret;   
                }
                return ret;
            }
#else // c++11
            template <typename E>
            bool notify(const E* const)
            {
                bool ret(true);
                using Notification = ObserverNotification<E>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _0Argument>(ob, &Notification::on_notified, this, ev)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T>
            bool notify(const E* const, T arg)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _1Argument, T>(ob, &Notification::on_notified, this, ev, arg)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2>
            bool notify(const E* const, T1 arg, T2 arg2)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _2Arguments, T1, T2>(ob, &Notification::on_notified, this, ev, arg, arg2)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _3Arguments, T1, T2, T3>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3, typename T4>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3, T4 arg4)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3, T4>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _4Arguments, T1, T2, T3, T4>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3, arg4)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3, typename T4, typename T5>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _5Arguments, T1, T2, T3, T4, T5>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3, arg4, arg5)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _6Arguments, T1, T2, T3, T4, T5, T6>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3, arg4, arg5, arg6)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _7Arguments, T1, T2, T3, T4, T5, T6, T7>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3, arg4, arg5, arg6, arg7)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _8Arguments, T1, T2, T3, T4, T5, T6, T7, T8>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3, arg4, arg5, arg6, arg7, arg8)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _9Arguments, T1, T2, T3, T4, T5, T6, T7, T8, T9>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)) && ret;   
                }
                return ret;
            }

            template <typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
            bool notify(const E* const, T1 arg, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10)
            {
                bool ret(true);
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>;
                const E* const ev(nullptr);    

                std::list<ObserverBase*> l = get_observer(typeid(E).hash_code());
                for (ObserverBase* ob : l)
                {
                    ret = enqueue(new AsynchronousExecution<E, _9Arguments, T1, T2, T3, T4, T5, T6, T7, T8, T9>(ob, &Notification::on_notified, this, ev, arg, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)) && ret;   
                }
                return ret;
            }
#endif // __cpp_version >= 201402L        
        private:
            bool enqueue(AsynchronousExecutionBase*);

        private:
            AsynchronousExecutor _executor;
        };
    }
}