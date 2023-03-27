#pragma once
#include "ugine/core.h"

using GLADloadproc = void* (*)(const char *name);

namespace ugine::graphic {

    enum class context {
        opengl
    };

   class UGINE_API GraphicContext {
   public:
       GraphicContext() = default;
       GraphicContext(const GraphicContext&) = default;
       GraphicContext(GraphicContext&&) = default;
       GraphicContext& operator=(GraphicContext&&) = default;
       GraphicContext& operator=(const GraphicContext&) = default;
       virtual ~GraphicContext() = default;
   };

   class UGINE_API OpenGl final: public GraphicContext {
   public:
       static constexpr int OPENGL_MAJOR_VERSION = 4;
       static constexpr int OPENGL_MINOR_VERSION = 1;
       void load_gl_load(GLADloadproc proc) const;
   };

}