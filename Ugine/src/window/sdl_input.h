#pragma once
#include "ugine/pch.h"
#include "ugine/window/input.h"

namespace ugine::window {
        class SDLInput final : public Input {
        public:
        [[nodiscard]] bool is_key_pressed(ugine::utils::keycode key) const noexcept override;

        [[nodiscard]] bool is_mouse_button_pressed(ugine::utils::mouse_button button) const noexcept override;

        [[nodiscard]] std::pair<float, float> get_mouse_position() const noexcept override;
    };
}
