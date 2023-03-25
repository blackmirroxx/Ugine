#pragma once
#include "ugine/core.h"
#include "ugine/event/event.h"
#include "ugine/event/event_handler.h"

namespace ugine::event {
    class UGINE_API WindowEvent: public Event {
    public:
        WindowEvent(event_type event_type) : Event(event_type, window_category) {}
    };

    class UGINE_API WindowQuit final: public WindowEvent {
    public:
        WindowQuit(): WindowEvent(event_type::window_quit)  {}
        [[nodiscard]] std::string to_string() const noexcept override {
            return  "WindowQuit";
        }
        void accept(EventHandlerMixin& handler ) const override {handler.handle(*this);}
    };
}