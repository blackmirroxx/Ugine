#pragma once
#include "ugine/core.h"
#include "ugine/event/event.h"

namespace ugine::event {
    class UGINE_API WindowEvent: public Event {
    public:
        WindowEvent(event_type event_type) : Event(event_type, window_category) {}
    };

    class UGINE_API WindowQuit final: public WindowEvent {
    public:
        WindowQuit(): WindowEvent(event_type::window_quit)  {}
        [[nodiscard]] std::string to_string() const noexcept {
            return  "WindowQuit";
        }
    };
}