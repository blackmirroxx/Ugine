#include "Ugine/Application.h"
#include "SDL.h"

void ugine::Application::run()
{
	this->signals.on_start.emit(10);
    this->start_loop();
}

void ugine::Application::start_loop() {
    this->running = true;
    const int delay_time = 1000 / fps;
    while (this->running) {
        const auto frame_start = SDL_GetTicks();
        this->on_game_loop();
        const auto frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < delay_time) {
            SDL_Delay(delay_time - frame_time);
        }
    }
}

void ugine::Application::on_game_loop() {
    this->input_handler.poll_events();
    this->window.render();
}