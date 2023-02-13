#pragma once
#include "Ugine/Core.h"
#include "Ugine/Event/Event.h"

enum class mouse_button_type {
    left, right, middle
};

class UGINE_API MouseButton: public Event
{
public:
    MouseButton(event_type event_type ,mouse_button_type mouse_button) : Event(event_type, input_category | mouse_category | mouse_button_category ),
    mouse_button(mouse_button)  {}
    [[nodiscard]] mouse_button_type get_mouse_button() const {return this->mouse_button; }
private:
    mouse_button_type mouse_button;
};

class UGINE_API MouseUp final: public MouseButton
{
public:
    explicit MouseUp(mouse_button_type mouse_button): MouseButton(event_type::mouse_up,mouse_button) {}
};

class UGINE_API MouseDown final : public MouseButton
{
public:
    explicit MouseDown(mouse_button_type mouse_button): MouseButton(event_type::mouse_down,mouse_button) {}
};

class UGINE_API MouseWheel final : public Event
{
public:
    MouseWheel() : Event(event_type::mouse_wheel, input_category | mouse_category ) {}
};

class UGINE_API MouseMove final : public Event
{
public:
    MouseMove() : Event(event_type::mouse_move, input_category | mouse_category ) {}
};
