#pragma once
#include "ugine/core.h"
#include "ugine/event/mouse_event.h"

namespace ugine {
    class UGINE_API Input
    {
    public:
        Input() = default;
        Input(const Input&) = delete;
        Input(Input&&) = delete;
        Input& operator=(const Input&) = delete;
        Input& operator=(Input&&) = delete;
        virtual ~Input() = default;
        [[nodiscard]] virtual bool is_key_pressed(int key_code) const noexcept = 0;
        [[nodiscard]] virtual bool is_mouse_button_pressed(event::mouse_button_type button) const noexcept = 0;
        [[nodiscard]] virtual std::pair<float,float> get_mouse_position() const noexcept = 0;
        [[nodiscard]] float get_mouse_x() const noexcept {
            auto [x,y] = this->get_mouse_position();
            return x;
        }
        [[nodiscard]] float get_mouse_y() const noexcept {
            auto [x,y] = this->get_mouse_position();
            return y;
        }
    };

    class UGINE_API SDLInput final: public Input
    {
    public:
        [[nodiscard]] bool is_key_pressed(int key_code) const noexcept override;
        [[nodiscard]] bool is_mouse_button_pressed(event::mouse_button_type button) const noexcept override;
        [[nodiscard]] std::pair<float,float> get_mouse_position() const noexcept override;
    };
}