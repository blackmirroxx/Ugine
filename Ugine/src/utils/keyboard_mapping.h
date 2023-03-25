#pragma once
#include <SDL.h>
#include <imgui.h>
#include "ugine/utils/keycode.h"


namespace ugine::utils {
    ugine::utils::keycode sdl_keycode_to_keycode(SDL_Keycode key);
    SDL_Keycode keycode_to_sdl_keycode(ugine::utils::keycode key);
}