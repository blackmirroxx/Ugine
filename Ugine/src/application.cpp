#include "ugine/application.h"

void ugine::Application2D::run() {
    this->signals.on_start.emit();
    this->start_loop();
}


void ugine::Application2D::start_loop() {
    this->running = true;
    // const int delay_time = 1000 / fps;
    while (this->is_running()) {
        //const auto frame_start = SDL_GetTicks();
        this->on_game_loop();
        // const auto frame_time = SDL_GetTicks() - frame_start;
        // if (frame_time < delay_time) {
        //     SDL_Delay(delay_time - frame_time);
        // }
    }
}

void ugine::Application2D::on_game_loop() const {
    this->pt_window->on_update();
    this->pt_window->render();
}
