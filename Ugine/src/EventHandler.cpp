#include "Ugine/Event/EventHandler.h"
#include "SDL.h"

void ugine::EventHandler::poll_events() const {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {

    }
}
