#pragma once

#include <ugine/pch.h>
#include "ugine/core.h"
#include "ugine/event/event.h"
#include "ugine/event/event_handler.h"
#include "ugine/utils/mouse_button.h"

namespace ugine::event {
    class UGINE_API MouseButtonEvent : public Event {
    public:
        MouseButtonEvent(event_type event_type, ugine::utils::mouse_button mouse_button,
                         float offset_x, float offset_y) : Event(event_type, input_category | mouse_category |
                                                                             mouse_button_category),
                                                           m_mouse_button(mouse_button),
                                                           m_offset_x{offset_x}, m_offset_y{offset_y} {}

        [[nodiscard]] ugine::utils::mouse_button get_mouse_button() const noexcept { return this->m_mouse_button; }

        [[nodiscard]] float get_offset_x() const noexcept { return m_offset_x; }

        [[nodiscard]] float get_offset_y() const noexcept { return m_offset_y; }

    private:
        ugine::utils::mouse_button m_mouse_button;
        float m_offset_x;
        float m_offset_y;
    };

    class UGINE_API MouseUp final : public MouseButtonEvent {
    public:
        MouseUp(ugine::utils::mouse_button mouse_button, float offset_x, float offset_y) :
                MouseButtonEvent(event_type::mouse_up, mouse_button, offset_x, offset_y) {}

        [[nodiscard]] std::string to_string() const noexcept override {
            return std::to_string(get_mouse_button()) + " MouseUp " + std::to_string(get_offset_x()) + "x" +
                   std::to_string(get_offset_y());
        }

        void accept(EventHandlerMixin &handler) const override { handler.handle(*this); }
    };

    class UGINE_API MouseDown final : public MouseButtonEvent {
    public:
        MouseDown(ugine::utils::mouse_button mouse_button, float offset_x, float offset_y) : MouseButtonEvent(
                event_type::mouse_down,
                mouse_button, offset_x, offset_y) {}

        [[nodiscard]] std::string to_string() const noexcept override {
            return std::to_string(get_mouse_button()) + " MouseUp " + std::to_string(get_offset_x()) + "x" +
                   std::to_string(get_offset_y());
        }

        void accept(EventHandlerMixin &handler) const override { handler.handle(*this); }
    };

    class UGINE_API MouseWheel final : public Event {
    public:
        MouseWheel(float offset_x, float offset_y) : Event(event_type::mouse_wheel, input_category | mouse_category),
                                                     m_offset_x(offset_x), m_offset_y(offset_y) {}

        [[nodiscard]] float get_offset_x() const noexcept { return m_offset_x; }

        [[nodiscard]] float get_offset_y() const noexcept { return m_offset_y; }

        [[nodiscard]] bool is_up() const noexcept { return m_offset_y > 0; }

        [[nodiscard]] bool is_down() const noexcept { return !this->is_up(); }

        [[nodiscard]] std::string to_string() const noexcept override {
            return "MouseWheel " + std::to_string(m_offset_x) + "x" + std::to_string(m_offset_y);
        }

        void accept(EventHandlerMixin &handler) const override { handler.handle(*this); }

    private:
        float m_offset_x;
        float m_offset_y;
    };

    class UGINE_API MouseMove final : public Event {
    public:
        MouseMove(float mouse_x, float mouse_y) : Event(event_type::mouse_move, input_category | mouse_category),
                                                  m_mouse_x(mouse_x), m_mouse_y(mouse_y) {}

        [[nodiscard]] float get_mouse_x() const noexcept { return m_mouse_x; }

        [[nodiscard]] float get_mouse_y() const noexcept { return m_mouse_y; }

        [[nodiscard]] std::string to_string() const noexcept override {
            return "MouseMove " + std::to_string(m_mouse_x) + "x" + std::to_string(m_mouse_y);
        }

        void accept(EventHandlerMixin &handler) const override { handler.handle(*this); }

    private:
        float m_mouse_y;
        float m_mouse_x;
    };
}

