#pragma once

#include "subject.hpp"
#include "event_definition.hpp"


class ConcreteSubjectSync : public DesignPattern::Observer::Subject<>
                          , public IComponentEvent
{
public:
    virtual bool on_none()
    {
        ComopmentEvent::Event_void* ev;
        return notify(ev);
    }

    virtual bool on_state(const int state)
    {
        ComopmentEvent::Event_state* ev;
        return notify(ev, state);
    }

    virtual bool on_error(const int err)
    {
        ComopmentEvent::Event_error* ev;
        return notify(ev, err);
    }

    virtual bool on_coordinate_changed(const float x, const float y, const float z)
    {
        ComopmentEvent::Event_coordinate* ev;
        return notify(ev, x, y, z);
    }
};

class ConcreteSubjectAsync : public DesignPattern::Observer::Subject<DesignPattern::Observer::Asynchronous>
                           , public IComponentEvent
{
public:
    ConcreteSubjectAsync(const std::size_t dispatchers = 1U) : DesignPattern::Observer::Subject<DesignPattern::Observer::Asynchronous>(dispatchers)
    {

    }

    virtual bool on_none()
    {
        ComopmentEvent::Event_void* ev;
        return notify(ev);
    }

    virtual bool on_state(const int state)
    {
        ComopmentEvent::Event_state* ev;
        return notify(ev, state);
    }

    virtual bool on_error(const int err)
    {
        ComopmentEvent::Event_error* ev;
        return notify(ev, err);
    }

    virtual bool on_coordinate_changed(const float x, const float y, const float z)
    {
        ComopmentEvent::Event_coordinate* ev;
        return notify(ev, x, y, z);
    }
};