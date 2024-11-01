#pragma once

class IComponentEvent {
    virtual bool on_none() = 0;
    virtual bool on_state(const int state) = 0;
    virtual bool on_error(const int err) = 0;
    virtual bool on_coordinate_changed(const float x, const float y, const float z) = 0;
};