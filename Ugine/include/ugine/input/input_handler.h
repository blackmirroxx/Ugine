#pragma once
#include "ugine/core.h"

namespace ugine {
    class UGINE_API InputHandler {
    public:
        InputHandler() = default;
        InputHandler(InputHandler&&) = default;
        InputHandler(const InputHandler&) = default;
        InputHandler& operator=(const InputHandler&) = default;
        InputHandler& operator=(InputHandler&&) = default;
        virtual ~InputHandler() = default;
    };

    class UGINE_API SDLInputHandler: public InputHandler {
    public:
        void poll_events() const;
    };
}

