#pragma once
#include "ugine/core.h"
#include "ugine/event/event.h"

namespace ugine {
    class UGINE_API WindowEvent: public Event {
    public:
        WindowEvent(event_type event_type) : Event(event_type, window_category) {}
    };

    class UGINE_API QuitEvent: public WindowEvent {
    public:
        QuitEvent(): WindowEvent(event_type::window_quit)  {}
    };
}