#include "ugine/window/window_factory.h"
#include "ugine/window/window_impl.h"
#include "sdl_window.h"

std::unique_ptr<ugine::window::WindowImpl> ugine::window::SDLFactory::create_with_opengl() const {
    return std::make_unique<ugine::window::SDLGlWindow>();
}
