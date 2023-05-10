#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"

namespace ugine::event {
    class EventHandlerMixin;

    enum class event_type {
        mouse_up, mouse_down, mouse_wheel, mouse_move, key_up, key_down,
        window_quit
    };

    enum event_category {
        none = 0,
        input_category = BIT(0),
        keyboard_category = BIT(1),
        mouse_category = BIT(2),
        mouse_button_category = BIT(3),
        window_category = BIT(4)
    };

    class UGINE_API Event {
    public:
        Event(event_type event_type, int category_flags) : m_event(event_type), m_category_flags(category_flags) {}

        Event(const Event &e) = delete;

        Event(Event &&e) = default;

        Event &operator=(const Event &e) = delete;

        Event &operator=(Event &&e) = default;

        [[nodiscard]] int get_category_flags() const { return this->m_category_flags; }

        [[nodiscard]] event_type get_event_type() const { return this->m_event; }

        virtual ~Event() = default;

        [[nodiscard]] virtual std::string to_string() const noexcept = 0;

        [[nodiscard]] bool is_in_category(event_category category) const {
            return (this->m_category_flags & category) != 0;
        }

        virtual void accept(EventHandlerMixin &handler) const = 0;

        /**
         * Stop the propagation of an event, the next handler won't be called
         */
        void stop_propagation() const noexcept { this->m_handle = true; }

        [[nodiscard]] bool is_handled() const noexcept { return this->m_handle; }

    private:
        bool mutable m_handle = false;
        int m_category_flags = event_category::none;
        event_type m_event;
    };

}
