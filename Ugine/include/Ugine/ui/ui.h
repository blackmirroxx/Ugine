#pragma once
#include "ugine/core.h"

namespace ugine::window {
    class Window;
}

namespace ugine::ui {
    class UGINE_API UI
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

    class UGINE_API SDLUI: public UI {

    };

    class UGINE_API SDLImgui final: public SDLUI
    {
    public:
        void create(const ugine::window::Window& window) override;
    };
}