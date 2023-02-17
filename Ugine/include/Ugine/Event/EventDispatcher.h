#pragma once

#include <memory>
#include "Ugine/Event/Event.h"
#include "Ugine/Event/MouseEvent.h"
#include "Ugine/Event/KeyboardEvent.h"
#include "Ugine/Core.h"

namespace ugine {
    template <typename E>
    class UGINE_API EventDispatcher
    {
    public:
        void set_listener(std::unique_ptr<Listener<E>>& listener) {this->event_listener = std::move(listener);}
        void dispatch(const E& event) const noexcept {
            if (event_listener) this->event_listener->operator()(event);
        }
    private:
        std::unique_ptr<Listener<E>> event_listener;
    };

    struct UGINE_API EventController
    {
        EventDispatcher<MouseUp> mouse_up;
        EventDispatcher<MouseDown> mouse_down;
        EventDispatcher<MouseWheel> mouse_wheel;
        EventDispatcher<MouseMove> mouse_move;
        EventDispatcher<KeyUp> key_up;
        EventDispatcher<KeyDown> key_down;
    };
}

