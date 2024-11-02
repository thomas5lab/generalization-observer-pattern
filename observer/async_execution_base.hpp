#pragma once

#ifndef __cpp_version
    #if defined(__clang__) || defined(__GNUC__)
        #define __cpp_version __cplusplus
    #elif defined(_MSC_VER)
        #define __cpp_version _MSVC_LANG
    #endif
#endif // __cpp_version

namespace DesignPattern 
{
    namespace Observer
    {
        struct AsynchronousExecutionBase
        {
            virtual ~AsynchronousExecutionBase(){}
            virtual void execute() = 0;
        };

#if __cpp_version < 201402L
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
#endif
    }
}