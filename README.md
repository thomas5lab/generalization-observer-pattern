design pattern observer c++ generalization implementation

pure c++ codes using STL, suopprts c++11 and later version. Also supports synchronous & asynchorouns dispatching, dispatching threads can be set through asynchronous subject constructor, default is 1. No OS platform is specific, all is OK(Just compile and run on MacOS 13.2.1 with clang-1403.0.22.14.1 :P).

Dispatching Table:
                                             Subject         Observer
Synchronous Dispatching                         X              N/A
Asynchronous Dispatching                        X
Asynchronous Concurrency Dispatching            X

interface: observer/subject.hpp only, class Subject<Synchronous>, Subject<Asynchronous>, ObserverNotification<T...> Observer<T...>
observer/*.cpp can be compiled and linked into so/dll.

samples: x_event.cpp - Observed event definition.
         event_definition.hpp - Detailed event type definition for each method usage.
         concrete_subject.hpp - Concrete subject implementation.
         concrete_observer.hpp - Concrete observer implementation.
         test.cpp - Few codes test subject update.

compilation command line: g++ -O2 -std=c++14 test.cpp observer/subject_base.cpp observer/async_subject.cpp observer/async_executor.cpp -o test -I . -I observer/
                          g++ -O2 -std=c++11 test.cpp observer/subject_base.cpp observer/async_subject.cpp observer/async_executor.cpp -o test -I . -I observer/

lackness: only test argument pass by value. all arguments are shallow copied, pointer type should be ok for synchronous dispatching.

licensing: none, free for forking, downloading and correcting.
         
