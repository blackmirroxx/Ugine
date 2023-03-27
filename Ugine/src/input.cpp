#include <SDL.h>
#include "utils/key_mapping.h"
#include "ugine/input.h"


bool ugine::SDLInput::is_key_pressed(ugine::utils::keycode key) const noexcept {
    const auto *const keys_array = SDL_GetKeyboardState(nullptr);
    return static_cast<bool>(keys_array[SDL_GetScancodeFromKey(
                ugine::utils::keycode_to_sdl_keycode(key)
            )]);
}

bool ugine::SDLInput::is_mouse_button_pressed(ugine::utils::mouse_button button) const noexcept {
    return SDL_BUTTON(ugine::utils::mouse_button_to_sdl_button(button)) == SDL_GetMouseState(nullptr, nullptr);
}

std::pair<float, float> ugine::SDLInput::get_mouse_position() const noexcept {
    int mouse_x = 0;
    int mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    return {static_cast<float>(mouse_x), static_cast<float>(mouse_y)};
}
