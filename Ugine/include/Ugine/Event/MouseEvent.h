#pragma once
#include "Ugine/Core.h"
#include "Ugine/Event/Event.h"

namespace ugine {
    enum class mouse_button_type {
        left, right, middle
    };

    class UGINE_API MouseButtonEvent: public Event
    {
    public:
        MouseButtonEvent(event_type event_type , mouse_button_type mouse_button) : Event(event_type, input_category | mouse_category | mouse_button_category ),
                                                                                   mouse_button(mouse_button)  {}
        [[nodiscard]] mouse_button_type get_mouse_button() const {return this->mouse_button; }
    private:
        mouse_button_type mouse_button;
    };

    class UGINE_API MouseUp final: public MouseButtonEvent
    {
    public:
        explicit MouseUp(mouse_button_type mouse_button): MouseButtonEvent(event_type::mouse_up, mouse_button) {}
    };

    class UGINE_API MouseDown final : public MouseButtonEvent
    {
    public:
        explicit MouseDown(mouse_button_type mouse_button): MouseButtonEvent(event_type::mouse_down, mouse_button) {}
    };

    class UGINE_API MouseWheel final : public Event
    {
    public:
        MouseWheel(float offset_x,float offset_y) : Event(event_type::mouse_wheel, input_category | mouse_category ),
                                                    offset_x(offset_x), offset_y(offset_y){}
        [[nodiscard]] float get_offset_x() const noexcept {return offset_x;}
        [[nodiscard]] float get_offset_y() const noexcept {return offset_y;}
    private:
        float offset_x;
        float offset_y;
    };

    class UGINE_API MouseMove final : public Event
    {
    public:
        MouseMove(float mouse_x, float mouse_y) : Event(event_type::mouse_move, input_category | mouse_category ),
                                                  mouse_x(mouse_x), mouse_y(mouse_y){}
        [[nodiscard]] float get_mouse_x() const noexcept {return mouse_x;}
        [[nodiscard]] float get_mouse_y() const noexcept {return mouse_y;}
    private:
        float mouse_y;
        float mouse_x;
    };
}

