#pragma once

#include "ugine/core.h"
#include "ugine/event/mouse_event.h"
#include "ugine/utils/keycode.h"
#include "ugine/utils/mouse_button.h"

namespace ugine::window {
    class UGINE_API Input {
    public:
        Input() = default;

        Input(const Input &) = delete;

        Input(Input &&) = delete;

        Input &operator=(const Input &) = delete;

        Input &operator=(Input &&) = delete;

        virtual ~Input() = default;

        [[nodiscard]] virtual bool is_key_pressed(ugine::utils::keycode key) const noexcept = 0;

        [[nodiscard]] virtual bool is_mouse_button_pressed(ugine::utils::mouse_button button) const noexcept = 0;

        [[nodiscard]] virtual std::pair<float, float> get_mouse_position() const noexcept = 0;

        [[nodiscard]] float get_mouse_x() const noexcept {
            const auto [x, _] = this->get_mouse_position();
            return x;
        }

        [[nodiscard]] float get_mouse_y() const noexcept {
            const auto [_, y] = this->get_mouse_position();
            return y;
        }
    };

}