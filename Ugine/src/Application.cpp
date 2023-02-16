#include "Ugine/Application.h"
#include "Ugine/Renderer.h"

void ugine::Application::run() const
{
	this->signals.on_start.emit(10);
    auto player = AssetRenderer("assets/player.png", "player", this->window);
    player.render({0,0, 200, 200}, {0,0, 200, 200});
    while(this->game_loop) {
        this->event_handler.poll_events();
        this->window.render();
    }
}



