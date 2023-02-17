#include "Ugine/Application.h"
#include "Ugine/Renderer.h"


void ugine::Application::run() const
{
	this->signals.on_start.emit(10);
    auto renderer = TextureManager(this->window);
    renderer.load("assets/Attack.png", "attack");
    renderer.render("attack", {0,0, 100, 100, 1 });
    while(this->game_loop) {
        this->event_handler.poll_events();
        this->window.render();
    }
}
