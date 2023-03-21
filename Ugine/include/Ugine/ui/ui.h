#pragma once
#include "ugine/core.h"

namespace ugine::window {
    class Window;
}

namespace ugine::ui {
    class UI
    {
    public:
        UI() = default;
        UI(const UI&) = delete;
        UI(UI&&) noexcept = delete;
        UI& operator=(const UI&) = delete;
        UI& operator=(UI&&) noexcept = delete;
        virtual void create(const ugine::window::Window&) = 0;
        virtual ~UI() = default;
    };

    class SDLImgui final: public UI
    {
    public:
        void create(const ugine::window::Window& window) override;
    };
}