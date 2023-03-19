#include "ugine/application.h"
#include <imgui.h>

void ugine::SDLApplication2D::run()
{
	this->signals.on_start.emit();
    this->start_loop();
}


void ugine::SDLApplication2D::start_loop() {
    this->running = true;
    const int delay_time = 1000 / fps;
    while (this->is_running()) {
        //const auto frame_start = SDL_GetTicks();
        this->on_game_loop();
       // const auto frame_time = SDL_GetTicks() - frame_start;
       // if (frame_time < delay_time) {
       //     SDL_Delay(delay_time - frame_time);
       // }
    }
}

void ugine::SDLApplication2D::on_game_loop() {
    this->pt_window->render();
    this->pt_window->on_update();
}

void ugine::SDLApplication2D::on_event(const ugine::event::Event& event) {
    UGINE_CORE_TRACE("Event {0}", event.to_string());
    if (event.get_event_type() == ugine::event::event_type::window_quit) {
        this->running = false;
    }
}
