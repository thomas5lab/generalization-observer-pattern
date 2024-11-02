#pragma once

#include <string>
#include <iostream>
#include <chrono>

#include "observer.hpp"
#include "event_definition.hpp"

#include "concrete_subject.hpp"

using Event_Class = DesignPattern::Observer::ObserverNotification<ComopmentEvent::Event_void>;
using Observer_Class = DesignPattern::Observer::Observer<Event_Class,
                                                         DesignPattern::Observer::ObserverNotification<ComopmentEvent::Event_state, const int>,
                                                         DesignPattern::Observer::ObserverNotification<ComopmentEvent::Event_error, const int>,
                                                         DesignPattern::Observer::ObserverNotification<ComopmentEvent::Event_coordinate, const float, const float, const float>>;
template <typename T>
class ConcreteObserver : public Observer_Class
{
public:
    ConcreteObserver(const char* s, T* sub) : _name(s)
    {
        ComopmentEvent::Event_void* ev;
        ComopmentEvent::Event_state* ev2;  
        ComopmentEvent::Event_error* ev3;  
        ComopmentEvent::Event_coordinate* ev4;

        sub->observe(observer_map(), ev, ev2, ev3, ev4);
    }

    

    virtual ~ConcreteObserver(){}

    void detach(T* sub)
    {
        sub->remove(observer_map());
    }

protected:
    bool on_notified(const DesignPattern::Observer::SubjectBase * const sub, 
                     const ComopmentEvent::Event_void* const)
    {
        std::cout << _name << ": void" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        return true;
    }

    bool on_notified(const DesignPattern::Observer::SubjectBase * const sub, 
                     const ComopmentEvent::Event_state* const, 
                     const int n)
    {
        std::cout << _name << ": state = " << n << std::endl;
        return true;
    }

    bool on_notified(const DesignPattern::Observer::SubjectBase * const sub, 
                     const ComopmentEvent::Event_error* const, 
                     const int n)
    {
        std::cout << _name << ": error = " << n << std::endl;
        return true;
    }

    bool on_notified(const DesignPattern::Observer::SubjectBase * const sub, 
                     const ComopmentEvent::Event_coordinate* const, 
                     const float x, const float y, const float z)
    {
        std::cout << _name << ": x = " << x << ",y = " << y << ",z = " << z << std::endl;
        return true;
    }
private:
    std::string _name;
};