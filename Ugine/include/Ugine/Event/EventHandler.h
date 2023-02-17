#pragma once
#include "Ugine/Core.h"

namespace ugine {
    class UGINE_API EventHandler {
    public:
        void poll_events() const;
    };
}

