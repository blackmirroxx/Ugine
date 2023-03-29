#include "ugine/window/window_factory.h"
#include "ugine/window/window_impl.h"
#include "sdl_window.h"

std::unique_ptr<ugine::window::WindowImpl> ugine::window::WindowsWindowFactory::create() const {
    return std::make_unique<ugine::window::SDLGlWindow>();
}

std::unique_ptr<ugine::window::WindowImpl> ugine::window::LinuxWindowFactory::create() const {
    return std::make_unique<ugine::window::SDLGlWindow>();
}

std::unique_ptr<ugine::window::WindowImpl> ugine::window::AppleWindowFactory::create() const {
    return std::make_unique<ugine::window::SDLGlWindow>();
}
