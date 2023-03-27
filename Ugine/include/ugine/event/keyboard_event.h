#pragma once

#include "ugine/core.h"
#include "ugine//event/event.h"
#include "ugine/event/event_handler.h"
#include "ugine/utils/keycode.h"

namespace ugine::event {
    class UGINE_API KeyboardEvent : public Event {
    public:
        KeyboardEvent(event_type event_type, ugine::utils::keycode key_code) : Event(event_type, input_category |
                                                                                                 keyboard_category),
                                                                               key_code(key_code) {}

        [[nodiscard]] ugine::utils::keycode get_key_code() const noexcept { return key_code; }

    protected:
        ugine::utils::keycode key_code;
    };

    class UGINE_API KeyUp final : public KeyboardEvent {
    public:
        explicit KeyUp(ugine::utils::keycode key_code) : KeyboardEvent(event_type::key_up, key_code) {}

        [[nodiscard]] std::string to_string() const noexcept override {
            return "KeyUp " + std::to_string(key_code);
        }

        void accept(EventHandlerMixin &handler) const override { handler.handle(*this); }
    };

    class UGINE_API KeyDown final : public KeyboardEvent {
    public:
        explicit KeyDown(ugine::utils::keycode key_code, bool repeat = false) :
                KeyboardEvent(event_type::key_down, key_code), repeat{repeat} {}

        [[nodiscard]] bool is_repeated() const noexcept { return repeat; }

        [[nodiscard]] std::string to_string() const noexcept override {
            return "KeyDown " + std::to_string(key_code) + (repeat ? " repeated" : "");
        }

        void accept(EventHandlerMixin &handler) const override { handler.handle(*this); }

    private:
        bool repeat;
    };
}
