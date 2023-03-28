#pragma once

#include "ugine/graphic/graphic_context.h"

namespace ugine::graphic {

    class OpenGl final : public GraphicContext {
    public:
        static constexpr int OPENGL_MAJOR_VERSION = 4;
        static constexpr int OPENGL_MINOR_VERSION = 1;

        static void load_gl_loader(GLADloadproc proc) ;
    };
}