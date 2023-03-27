#include "ugine/window/window_factory.h"
#include "ugine/window/window_impl.h"

std::unique_ptr<ugine::window::WindowImpl> ugine::window::SDLFactory::create(const ugine::graphic::context context) const {
    if (context == graphic::context::opengl) {
        return std::unique_ptr<ugine::window::SDLGlWindow>();
    }
    return nullptr;
}
