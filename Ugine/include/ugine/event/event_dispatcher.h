#pragma once

#include <memory>
#include "ugine/event/event.h"
#include "ugine/event/mouse_event.h"
#include "ugine/event/keyboard_event.h"
#include "ugine/core.h"

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

}

