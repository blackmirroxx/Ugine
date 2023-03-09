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
        ~InputHandler() = default;
    };
}

