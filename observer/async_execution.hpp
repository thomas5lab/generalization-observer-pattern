#pragma once

#ifndef __cpp_version
    #if defined(__clang__) || defined(__GNUC__)
        #define __cpp_version __cplusplus
    #elif defined(_MSC_VER)
        #define __cpp_version _MSVC_LANG
    #endif
#endif // __cpp_version

#if __cpp_version >= 201402L
    #include <tuple>
#endif // >= c++14

#include <list>

#include "async_execution_base.hpp"

#include "subject_base.hpp"

namespace DesignPattern 
{
    namespace Observer
    {
#if __cpp_version >= 201402L
        template<typename E, typename ...Tn>
        class AsynchronousExecution : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, Tn...>::*function)(const SubjectBase * const, const E* const, Tn...);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event, 
                                  Tn... args)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _args(args...)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                unpack_execute(std::make_index_sequence<std::tuple_size<decltype(_args)>::value>());
            }

        private:
            template<std::size_t... I>
            void unpack_execute(std::index_sequence<I...>)
            {
                using Notification = ObserverNotification<E, Tn...>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, std::get<I>(_args)...);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;
            std::tuple<Tn...> _args;            
        };

#else // c++11
        template<typename E, typename ...Tn>
        class AsynchronousExecution;

        template<typename E>
        class AsynchronousExecution<E, _0Argument> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E>::*function)(const SubjectBase * const, const E* const);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
        };

        template<typename E, typename T>
        class AsynchronousExecution<E, _1Argument, T> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T>::*function)(const SubjectBase * const, const E* const, T);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T arg)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T _arg;
        };

        template<typename E, typename T1, typename T2>
        class AsynchronousExecution<E, _2Arguments, T1, T2> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2>::*function)(const SubjectBase * const, const E* const, T1, T2);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
        };

        template<typename E, typename T1, typename T2, typename T3>
        class AsynchronousExecution<E, _3Arguments, T1, T2, T3> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3>::*function)(const SubjectBase * const, const E* const, T1, T2, T3);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
        };

        template<typename E, typename T1, typename T2, typename T3, typename T4>
        class AsynchronousExecution<E, _4Arguments, T1, T2, T3, T4> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
                                  , _arg4(arg4)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3, T4>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
            T4 _arg4;
        };

        template<typename E, typename T1, typename T2, typename T3, typename T4, typename T5>
        class AsynchronousExecution<E, _5Arguments, T1, T2, T3, T4, T5> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
                                  , _arg4(arg4)
                                  , _arg5(arg5)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
            T4 _arg4;
            T5 _arg5;
        };

        template<typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        class AsynchronousExecution<E, _6Arguments, T1, T2, T3, T4, T5, T6> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5, T6>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5, T6);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5,
                                  T6 arg6)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
                                  , _arg4(arg4)
                                  , _arg5(arg5)
                                  , _arg6(arg6)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
            T4 _arg4;
            T5 _arg5;
            T6 _arg6;
        };

        template<typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
        class AsynchronousExecution<E, _7Arguments, T1, T2, T3, T4, T5, T6, T7> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5, T6, T7);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5,
                                  T6 arg6,
                                  T7 arg7)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
                                  , _arg4(arg4)
                                  , _arg5(arg5)
                                  , _arg6(arg6)
                                  , _arg7(arg7)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
            T4 _arg4;
            T5 _arg5;
            T6 _arg6;
            T7 _arg7;
        };

        template<typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
        class AsynchronousExecution<E, _8Arguments, T1, T2, T3, T4, T5, T6, T7, T8> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5, T6, T7, T8);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5,
                                  T6 arg6,
                                  T7 arg7,
                                  T8 arg8)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
                                  , _arg4(arg4)
                                  , _arg5(arg5)
                                  , _arg6(arg6)
                                  , _arg7(arg7)
                                  , _arg8(arg8)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
            T4 _arg4;
            T5 _arg5;
            T6 _arg6;
            T7 _arg7;
            T8 _arg8;
        };

        template<typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
        class AsynchronousExecution<E, _9Arguments, T1, T2, T3, T4, T5, T6, T7, T8, T9> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5, T6, T7, T8, T9);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5,
                                  T6 arg6,
                                  T7 arg7,
                                  T8 arg8,
                                  T9 arg9)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
                                  , _arg4(arg4)
                                  , _arg5(arg5)
                                  , _arg6(arg6)
                                  , _arg7(arg7)
                                  , _arg8(arg8)
                                  , _arg9(arg9)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
            T4 _arg4;
            T5 _arg5;
            T6 _arg6;
            T7 _arg7;
            T8 _arg8;
            T9 _arg9;
        };



        template<typename E, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
        class AsynchronousExecution<E, _10Arguments, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
            AsynchronousExecution(const std::list<ObserverBase*>& lst, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5,
                                  T6 arg6,
                                  T7 arg7,
                                  T8 arg8,
                                  T9 arg9,
                                  T10 arg10)
                                  : _lst(lst)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
                                  , _arg(arg)
                                  , _arg2(arg2)
                                  , _arg3(arg3)
                                  , _arg4(arg4)
                                  , _arg5(arg5)
                                  , _arg6(arg6)
                                  , _arg7(arg7)
                                  , _arg8(arg8)
                                  , _arg9(arg9)
                                  , _arg10(arg10)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>;
                for (ObserverBase* ob : _lst)
                {
                    Notification* p = static_cast<Notification*>(ob);
                    if (p != nullptr)
                    {
                        try {
                            (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10);
                        } catch(...) {                        
                        }
                    }
                }
            }

        private:
            std::list<ObserverBase*> _lst;
            function _f;
            SubjectBase* _sub;
            const E* _event;        
            T1 _arg;
            T2 _arg2;
            T3 _arg3;
            T4 _arg4;
            T5 _arg5;
            T6 _arg6;
            T7 _arg7;
            T8 _arg8;
            T9 _arg9;
            T10 _arg10;
        };
#endif // >= c++14
    }
}