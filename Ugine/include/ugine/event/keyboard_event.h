#pragma once
#include "ugine/core.h"
#include "ugine//event/event.h"

namespace ugine::event {
    class UGINE_API KeyboardEvent: public Event
    {
    public:
        KeyboardEvent(event_type event_type, int key_code) : Event(event_type, input_category | keyboard_category),
                                                             key_code(key_code) {}
        [[nodiscard]] int get_key_code() const noexcept {return key_code;}
    protected:
        int key_code;
    };

    class UGINE_API KeyUp final: public KeyboardEvent
    {
    public:
        explicit KeyUp(int key_code ): KeyboardEvent(event_type::key_up, key_code) {}
        [[nodiscard]] std::string to_string() const noexcept {
            return  "KeyUp " + std::to_string(key_code);
        }
    };

    class UGINE_API KeyDown final: public KeyboardEvent
    {
    public:
        explicit KeyDown(int key_code, int repeat_count = 1): KeyboardEvent(event_type::key_down, key_code),
                                                              repeat_count(repeat_count) {}
        [[nodiscard]] int get_repeat_count() const noexcept {return repeat_count;}
        [[nodiscard]] std::string to_string() const noexcept {
            return  "KeyUp " + std::to_string(key_code) + " repeat: " + std::to_string(repeat_count);
        }
    private:
        int repeat_count;
    };
}
