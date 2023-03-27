#pragma once

#include "ugine/core.h"
#include "ugine/event/event.h"

namespace ugine::event {
    class KeyDown;

    class KeyUp;

    class MouseUp;

    class MouseDown;

    class MouseWheel;

    class MouseMove;

    class WindowQuit;

    class UGINE_API EventHandlerMixin {
    public:
        EventHandlerMixin() = default;

        virtual ~EventHandlerMixin() = default;

        EventHandlerMixin(const EventHandlerMixin &) = default;

        EventHandlerMixin(EventHandlerMixin &&) noexcept = default;

        EventHandlerMixin &operator=(const EventHandlerMixin &) = default;

        EventHandlerMixin &operator=(EventHandlerMixin &&) noexcept = default;

        void handle_event(const ugine::event::Event &event) {
            if (!event.is_handled()) {
                event.accept(*this);
            }
        }

        virtual void handle(const KeyDown &event) {};

        virtual void handle(const KeyUp &event) {};

        virtual void handle(const MouseUp &event) {};

        virtual void handle(const MouseDown &event) {};

        virtual void handle(const MouseWheel &event) {};

        virtual void handle(const MouseMove &event) {};

        virtual void handle(const WindowQuit &event) {};
    };
}