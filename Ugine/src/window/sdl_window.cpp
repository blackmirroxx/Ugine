#include "ugine/window/window.h"
#include "ugine/log.h"
#include "ugine/exception/exception.h"
#include "ugine/event/window_event.h"
#include "ugine/event/mouse_event.h"
#include "ugine/event/keyboard_event.h"
#include "../utils/key_mapping.h"
#include "../graphic/opengl.h"
#include "sdl_window.h"

static int i_count = 0;

static void init_sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw ugine::exception::window::WindowInitError(SDL_GetError());
    }
    UGINE_CORE_INFO("SDL initialized");
}


ugine::window::SDLWindow::SDLWindow() {
    if (i_count++ == 0) {
        init_sdl();
    }
}

void ugine::window::SDLGlWindow::create(const window::WindowProps &props) {
    if (this->sdl_window != nullptr) {
        throw ugine::exception::window::WindowAlreadyCreated();
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, graphic::OpenGl::OPENGL_MAJOR_VERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, graphic::OpenGl::OPENGL_MINOR_VERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    this->sdl_window = SDL_CreateWindow(props.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                        props.width, props.height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (this->sdl_window == nullptr) {
        UGINE_CORE_ERROR("Error creating sdl_window, details: {0}", SDL_GetError());
        return;
    }
    this->gl_context = SDL_GL_CreateContext(this->sdl_window);
    if (this->gl_context == nullptr) {
        UGINE_CORE_ERROR("Error creating opengl context, details: {0}", SDL_GetError());
        return;
    }
    graphic::OpenGl::load_gl_loader(SDL_GL_GetProcAddress);
}

ugine::window::SDLWindow::~SDLWindow() {
    if (--i_count == 0) {
        SDL_Quit();
        UGINE_CORE_INFO("SDL cleaned up");
    }
}

void ugine::window::SDLGlWindow::render() const {
    SDL_GL_MakeCurrent(this->sdl_window, this->gl_context); // The gl context may have changed from ui
    SDL_GL_SwapWindow(this->sdl_window);
}


void ugine::window::SDLWindow::on_update() const {
    SDL_Event event;
    if (SDL_PollEvent(&event) != 0) {
        this->dispatch_sdl_event(event);
        if (event.type == SDL_QUIT) {
            this->dispatch(event::WindowQuit());
        }
        if (event.type == SDL_MOUSEMOTION) {
            const auto *const motion_event = reinterpret_cast<SDL_MouseMotionEvent *>(&event);
            this->dispatch(
                    event::MouseMove{static_cast<float>(motion_event->x), static_cast<float>(motion_event->y)});
        }
        if (event.type == SDL_MOUSEBUTTONUP) {
            const auto *const button_up_event = reinterpret_cast<SDL_MouseButtonEvent *>(&event);
            this->dispatch(event::MouseUp{utils::sdl_button_to_mouse_button(button_up_event->button),
                                                 static_cast<float>(button_up_event->x),
                                                 static_cast<float>(button_up_event->y)
            });
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            const auto *const button_down_event = reinterpret_cast<SDL_MouseButtonEvent *>(&event);
            this->dispatch(event::MouseDown{utils::sdl_button_to_mouse_button(button_down_event->button),
                                                   static_cast<float>(button_down_event->x),
                                                   static_cast<float>(button_down_event->y)
            });
        }
        if (event.type == SDL_MOUSEWHEEL) {
            const auto *const mouse_wheel_event = reinterpret_cast<SDL_MouseWheelEvent *>(&event);
            this->dispatch(event::MouseWheel{mouse_wheel_event->preciseX, mouse_wheel_event->preciseY});
        }
        if (event.type == SDL_KEYUP) {
            const auto *const key_up_event = reinterpret_cast<SDL_KeyboardEvent *>(&event);
            this->dispatch(event::KeyUp(utils::sdl_keycode_to_keycode(key_up_event->keysym.sym)));
        }
        if (event.type == SDL_KEYDOWN) {
            const auto *const key_down_event = reinterpret_cast<SDL_KeyboardEvent *>(&event);
            this->dispatch(event::KeyDown(utils::sdl_keycode_to_keycode(key_down_event->keysym.sym),
                                                 static_cast<bool>(key_down_event->repeat)));
        }
    }
}

void ugine::window::SDLWindow::close() const {
    SDL_DestroyWindow(this->sdl_window);
    UGINE_CORE_INFO("Window closed");
}

void ugine::window::SDLGlWindow::close() const {
    SDL_GL_DeleteContext(this->gl_context);
    UGINE_CORE_INFO("Opengl context deleted");
    SDLWindow::close();
}

void ugine::window::SDLWindow::dispatch_sdl_event(const SDL_Event &sdl_event) const noexcept {
    for (const auto &callback: this->sdl_event_cb) {
        callback(sdl_event);
    }
}

void ugine::window::SDLWindow::on_sdl_event(sdl_event_cb_type callback) noexcept {
    this->sdl_event_cb.push_back(std::move(callback));
}

