#pragma once

#include "ugine/core.h"


namespace ugine::graphic {

    class UGINE_API GraphicContext {
    public:
        GraphicContext() = default;

        GraphicContext(const GraphicContext &) = default;

        GraphicContext(GraphicContext &&) = default;

        GraphicContext &operator=(GraphicContext &&) = default;

        GraphicContext &operator=(const GraphicContext &) = default;

        virtual ~GraphicContext() = default;
    };


}