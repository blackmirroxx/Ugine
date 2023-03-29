#include "ugine/window/window_impl.h"
#include "sdl_window.h"

std::unique_ptr<ugine::window::WindowImpl> ugine::window::WindowsWindow::create() const {
    return std::make_unique<SDLGlWindow>();
}

std::unique_ptr<ugine::window::WindowImpl> ugine::window::LinuxWindow::create() const {
    return std::make_unique<SDLGlWindow>();
}

std::unique_ptr<ugine::window::WindowImpl> ugine::window::AppleWindow::create() const {
    return std::make_unique<SDLGlWindow>();
}
