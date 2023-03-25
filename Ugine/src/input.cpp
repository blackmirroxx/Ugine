#include <SDL.h>
#include "utils/keyboard_mapping.h"
#include "ugine/input.h"

static Uint8 get_mouse_button(ugine::event::mouse_button_type button) {
    switch(button) {
        case ugine::event::mouse_button_type::left: return SDL_BUTTON_LEFT;
        case ugine::event::mouse_button_type::right: return SDL_BUTTON_RIGHT;
        case ugine::event::mouse_button_type::middle : return SDL_BUTTON_MIDDLE;
        default: return 0;
    }
}

bool ugine::SDLInput::is_key_pressed(ugine::utils::keycode key) const noexcept {
    const auto *const keys_array = SDL_GetKeyboardState(nullptr);
    return static_cast<bool>(keys_array[ugine::utils::keycode_to_sdl_scancode(key)]);
}

bool ugine::SDLInput::is_mouse_button_pressed(ugine::event::mouse_button_type button) const noexcept {
    return SDL_BUTTON(get_mouse_button(button)) == SDL_GetMouseState(nullptr, nullptr);
}

std::pair<float, float> ugine::SDLInput::get_mouse_position() const noexcept {
    int mouse_x = 0;
    int mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    return {static_cast<float>(mouse_x), static_cast<float>(mouse_y)};
}
