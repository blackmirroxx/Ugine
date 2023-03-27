#include "ugine/graphic/graphic_context.h"
#include "glad/glad.h"


void ugine::graphic::OpenGl::load_gl_loader(GLADloadproc proc) const {
    gladLoadGLLoader(proc);
}

