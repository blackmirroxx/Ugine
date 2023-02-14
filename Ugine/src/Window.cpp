#include "Ugine/Window.h"
#include "Ugine/Log.h"
#include "SDL.h"


void Window::init() const {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)  {
        UGINE_CORE_ERROR("Unable to init the SDL")
        return;
    }
    auto p_window = SDL_CreateWindow(props.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                     props.width, props.height, SDL_WINDOW_OPENGL);
}