#include <SDL.h>
#include <glad/glad.h>
#include "ugine/window.h"
#include "ugine/log.h"
#include "ugine/exception/exception.h"
#include "ugine/event/window_event.h"
#include "ugine/event/mouse_event.h"
#include "ugine/event/keyboard_event.h"

static int i_count = 0;

static void init_sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw ugine::exception::WindowInitError(SDL_GetError());
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    UGINE_CORE_INFO("SDL initialized");
}

static ugine::event::mouse_button_type get_mouse_button(Uint8 button) {
    switch(button) {
        case SDL_BUTTON_LEFT: return ugine::event::mouse_button_type::left;
        case SDL_BUTTON_RIGHT: return ugine::event::mouse_button_type::right;
        case SDL_BUTTON_MIDDLE: return ugine::event::mouse_button_type::middle;
        default: return ugine::event::mouse_button_type::unknown;
    }
}

ugine::SDLWindow::SDLWindow() {
    if (i_count++ == 0) {
        init_sdl();
    }
}

void ugine::SDLWindow::create(const WindowProps& props)  {
    if (this->sdl_window != nullptr || this->sdl_renderer != nullptr || this->gl_context != nullptr) {
        throw ugine::exception::WindowAlreadyCreated();
    }
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
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    this->sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (this->sdl_renderer == nullptr) {
        UGINE_CORE_ERROR("Error creating sdl_renderer, details: {0}", SDL_GetError());
        return;
    }
    this->ui.create(*this);
    UGINE_CORE_INFO("Window {0} of {1}x{2}px created", props.title, props.height, props.width);
}

ugine::SDLWindow::~SDLWindow() {
    this->close();
    if (--i_count == 0) {
        SDL_Quit();
        UGINE_CORE_INFO("SDL cleaned up");
    }
}

void ugine::SDLWindow::render() const {
    SDL_RenderPresent(this->sdl_renderer);
}


void ugine::SDLWindow::on_update() const {
    SDL_Event event;
    if (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            this->dispatch(ugine::event::WindowQuit());
        }
        if (event.type == SDL_MOUSEMOTION) {
            auto *motion_event = reinterpret_cast<SDL_MouseMotionEvent*>(&event);
            this->dispatch(ugine::event::MouseMove{ static_cast<float>(motion_event->x), static_cast<float>(motion_event->y)});
        }
        if (event.type == SDL_MOUSEBUTTONUP) {
            auto *button_up_event = reinterpret_cast<SDL_MouseButtonEvent*>(&event);
            this->dispatch(ugine::event::MouseUp{get_mouse_button(button_up_event->button),
                          static_cast<float>(button_up_event->x), static_cast<float>(button_up_event->y)
                    });
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            auto *button_down_event = reinterpret_cast<SDL_MouseButtonEvent*>(&event);
            this->dispatch(ugine::event::MouseDown{get_mouse_button(button_down_event->button),
                          static_cast<float>(button_down_event->x), static_cast<float>(button_down_event->y)
            });
        }
        if (event.type == SDL_MOUSEWHEEL) {
            auto *mouse_wheel_event = reinterpret_cast<SDL_MouseWheelEvent*>(&event);
            this->dispatch(ugine::event::MouseWheel{mouse_wheel_event->preciseX, mouse_wheel_event->preciseY});
        }
        if (event.type == SDL_KEYUP) {
            auto *key_up_event = reinterpret_cast<SDL_KeyboardEvent *>(&event);
            this->dispatch(ugine::event::KeyUp(key_up_event->keysym.sym));
        }
        if (event.type == SDL_KEYDOWN) {
            auto *key_down_event = reinterpret_cast<SDL_KeyboardEvent *>(&event);
            this->dispatch(ugine::event::KeyDown(key_down_event->keysym.sym, bool(key_down_event->repeat)));
        }
    }
}

void ugine::SDLWindow::close() const {
    SDL_DestroyRenderer(this->sdl_renderer);
    SDL_GL_DeleteContext(this->gl_context);
    SDL_DestroyWindow(this->sdl_window);
    UGINE_CORE_INFO("Window closed");
}
