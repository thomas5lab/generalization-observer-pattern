#include <chrono>

#include "concrete_subject.hpp"
#include "concrete_observer.hpp"

int main()
{
    ConcreteSubjectSync a;
    ConcreteObserver<ConcreteSubjectSync> b("1", &a), b2("2", &a), b3("3", &a), b4("4", &a);

    a.on_none();

    a.on_coordinate_changed(1.0f, 1.0f, 2.0f);
    b2.detach(&a);
    a.on_state(2);
    a.on_error(-8);

    ConcreteSubjectAsync a2(4U);
    ConcreteObserver<ConcreteSubjectAsync> c("A", &a2), c2("B", &a2), c3("C", &a2), c4("D", &a2);

    a2.on_none();
    a2.on_coordinate_changed(1.0f, 1.0f, 2.0f);
    c4.detach(&a2);
    a2.on_state(2);
    a2.on_error(-8);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}