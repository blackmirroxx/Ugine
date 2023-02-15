#include "Ugine/Event/EventHandler.h"
#include "SDL.h"

void EventHandler::poll_events() const {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {

    }
}
