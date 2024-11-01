#include "async_subject.hpp"

namespace DesignPattern 
{
    namespace Observer
    {   
        Subject<Asynchronous>::Subject(const std::size_t dispatchers) : _executor(dispatchers)
        {
        }

        Subject<Asynchronous>::~Subject()
        {
        }

        bool Subject<Asynchronous>::enqueue(AsynchronousExecutionBase* e)
        {
            return _executor.enqueue(e);
        }
    }
}