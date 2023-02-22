#include "Ugine/Input/InputHandler.h"
#include "SDL.h"

void ugine::InputHandler::poll_events() const {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {

    }
}
