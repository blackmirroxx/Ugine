#pragma once
#include <ugine/pch.h>
#include "ugine/core.h"
#include "ugine/event/event.h"
#include "ugine/event/event_handler.h"

namespace ugine::event {
    enum class mouse_button_type {
        left, right, middle, unknown
    };


    class UGINE_API MouseButtonEvent: public Event
    {
    public:
        MouseButtonEvent(event_type event_type , mouse_button_type mouse_button,
                         float offset_x, float offset_y) : Event(event_type, input_category | mouse_category | mouse_button_category ),
                                                                                   mouse_button(mouse_button),
                                                                                   offset_x{offset_x}, offset_y{offset_y} {}
        [[nodiscard]] mouse_button_type get_mouse_button() const {return this->mouse_button; }
        [[nodiscard]] float get_offset_x() const noexcept {return offset_x;}
        [[nodiscard]] float get_offset_y() const noexcept {return offset_y;}
    protected:
        [[nodiscard]] std::string mouse_button_to_string() const {
            switch(this->mouse_button) {
                case mouse_button_type::left: return "Left";
                case mouse_button_type::right: return "Right";
                case mouse_button_type::middle: return "Middle";
                default: return "Unknown";
            }
        }
        mouse_button_type mouse_button;
        float offset_x;
        float offset_y;
    };

    class UGINE_API MouseUp final: public MouseButtonEvent
    {
    public:
        MouseUp(mouse_button_type mouse_button, float offset_x, float offset_y):
            MouseButtonEvent(event_type::mouse_up, mouse_button, offset_x, offset_y) {}
        [[nodiscard]] std::string to_string() const noexcept override {
            return  this->mouse_button_to_string() + " MouseUp " + std::to_string(offset_x) + "x" + std::to_string(offset_y);;;
        }
        void accept(EventHandler& handler ) const override {handler.handle(*this);}
    };

    class UGINE_API MouseDown final : public MouseButtonEvent
    {
    public:
        MouseDown(mouse_button_type mouse_button, float offset_x, float offset_y): MouseButtonEvent(event_type::mouse_down,
                                                                             mouse_button, offset_x, offset_y) {}
        [[nodiscard]] std::string to_string() const noexcept override {
            return this->mouse_button_to_string() + " MouseDown " + std::to_string(offset_x) + "x" + std::to_string(offset_y);;
        }
        void accept(EventHandler& handler ) const override {handler.handle(*this);}
    };

    class UGINE_API MouseWheel final : public Event
    {
    public:
        MouseWheel(float offset_x,float offset_y) : Event(event_type::mouse_wheel, input_category | mouse_category ),
                                                    offset_x(offset_x), offset_y(offset_y) {}
        [[nodiscard]] float get_offset_x() const noexcept {return offset_x;}
        [[nodiscard]] float get_offset_y() const noexcept {return offset_y;}
        [[nodiscard]] bool is_up() const noexcept {return offset_y > 0;}
        [[nodiscard]] bool is_down() const noexcept {return !this->is_up();}
        [[nodiscard]] std::string to_string() const noexcept override {
            return  "MouseWheel " + std::to_string(offset_x) + "x" + std::to_string(offset_y);
        }
        void accept(EventHandler& handler ) const override {handler.handle(*this);}
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
        [[nodiscard]] std::string to_string() const noexcept override {
            return  "MouseMove " + std::to_string(mouse_x) + "x" + std::to_string(mouse_y);
        }
        void accept(EventHandler& handler ) const override {handler.handle(*this);}
    private:
        float mouse_y;
        float mouse_x;
    };
}

