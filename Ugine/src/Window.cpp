#include "Ugine/Window.h"
#include "SDL.h"


void Window::init() const {
    SDL_Init(SDL_INIT_VIDEO);
}