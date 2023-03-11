#include "ugine/window.h"
#include "ugine/log.h"
#include "ugine/exception/exception.h"
#include "ugine/event/window_event.h"
#include "ugine/event/mouse_event.h"
#include "SDL.h"

static int i_count = 0;

static void init_sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw ugine::exception::WindowInitError(SDL_GetError());
    }
    UGINE_CORE_INFO("SDL initialized");
}

ugine::SDLWindow::SDLWindow() {
    if (i_count++ == 0) {
        init_sdl();
    }
}

void ugine::SDLWindow::create(const WindowProps& props)  {
    this->sdl_window = SDL_CreateWindow(props.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                     props.width, props.height, SDL_WINDOW_OPENGL);
    this->sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    UGINE_CORE_INFO("SDLWindow {0} of {1}x{2}px created", props.title, props.height, props.width);
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
    }
}

void ugine::SDLWindow::close() const {
    SDL_DestroyRenderer(this->sdl_renderer);
    SDL_DestroyWindow(this->sdl_window);
    UGINE_CORE_INFO("SDLWindow closed");
}
