#pragma once

#if defined(__clang__) || defined(__GNUC__)
	#define __cpp_version __cplusplus
#elif defined(_MSC_VER)
	#define __cpp_version _MSVC_LANG
#endif

#if __cpp_version >= 201402L
    #include <tuple>
#endif // >= c++14

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
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event, 
                                  Tn... args)
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, std::get<I>(_args)...);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
            SubjectBase* _sub;
            const E* _event;
            std::tuple<Tn...> _args;            
        };
#else // c++11
        struct _0Argument{};
        struct _1Argument{};
        struct _2Arguments{};
        struct _3Arguments{};
        struct _4Arguments{};
        struct _5Arguments{};
        struct _6Arguments{};
        struct _7Arguments{};
        struct _8Arguments{};
        struct _9Arguments{};
        struct _10Arguments{};

        template<typename E, typename ...Tn>
        class AsynchronousExecution;

        template<typename E>
        class AsynchronousExecution<E, _0Argument> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E>::*function)(const SubjectBase * const, const E* const);
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event)
                                  : _ob(ob)
                                  , _f(f)
                                  , _sub(sub)
                                  , _event(event)
            {               
            }
            virtual ~AsynchronousExecution(){}
            virtual void execute()
            {
                using Notification = ObserverNotification<E>;
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
            SubjectBase* _sub;
            const E* _event;        
        };

        template<typename E, typename T>
        class AsynchronousExecution<E, _1Argument, T> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T>::*function)(const SubjectBase * const, const E* const, T);
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T arg)
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
            SubjectBase* _sub;
            const E* _event;        
            T _arg;
        };

        template<typename E, typename T1, typename T2>
        class AsynchronousExecution<E, _2Arguments, T1, T2> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2>::*function)(const SubjectBase * const, const E* const, T1, T2);
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2)
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3)
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4)
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5)
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
            AsynchronousExecution(ObserverBase* ob, 
                                  function f, 
                                  SubjectBase* sub,
                                  const E* const event,
                                  T1 arg,
                                  T2 arg2,
                                  T3 arg3,
                                  T4 arg4,
                                  T5 arg5,
                                  T6 arg6)
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
            AsynchronousExecution(ObserverBase* ob, 
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
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
            AsynchronousExecution(ObserverBase* ob, 
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
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
        class AsynchronousExecution<E, _8Arguments, T1, T2, T3, T4, T5, T6, T7, T8, T9> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5, T6, T7, T8, T9);
            AsynchronousExecution(ObserverBase* ob, 
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
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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
        class AsynchronousExecution<E, _8Arguments, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> : public AsynchronousExecutionBase
        {
        public:
            typedef bool (ObserverNotification<E, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::*function)(const SubjectBase * const, const E* const, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
            AsynchronousExecution(ObserverBase* ob, 
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
                                  : _ob(ob)
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
                Notification* p = static_cast<Notification*>(_ob);
                if (p != nullptr)
                {
                    try {
                        (p->*_f)(_sub, _event, _arg, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10);
                    } catch(...) {                        
                    }
                }
            }

        private:
            function _f;
            ObserverBase* _ob;
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