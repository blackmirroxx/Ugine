#include "Ugine/Application.h"
#include "Ugine/Renderer.h"


void ugine::Application::run() const
{
	this->signals.on_start.emit(10);
    auto player = AssetRenderer("assets/Attack.png", "attack", this->window);
    player.render({200,200, 100, 200});
    while(this->game_loop) {
        this->event_handler.poll_events();
        this->window.render();
    }
}



