#pragma once

namespace DesignPattern 
{
    namespace Observer
    {
        struct AsynchronousExecutionBase
        {
            virtual ~AsynchronousExecutionBase(){}
            virtual void execute() = 0;
        };
    }
}