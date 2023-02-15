#include "Ugine/Application.h"

void ugine::Application::run() const
{
	this->signals.on_start.emit(10);
    while(this->game_loop) {
        this->event_handler.poll_events();
    }
}



