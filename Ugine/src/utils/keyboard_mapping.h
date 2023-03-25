#pragma once
#include <SDL.h>
#include <imgui.h>
#include "ugine/utils/keycode.h"


namespace ugine::utils {
    ImGuiKey keycode_to_imguikey(ugine::utils::keycode key);
    ugine::utils::keycode sdl_keycode_to_keycode(SDL_Keycode key);
    SDL_Scancode keycode_to_sdl_scancode(ugine::utils::keycode key);
}