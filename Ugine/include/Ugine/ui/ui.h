#pragma once
#include "ugine/core.h"

struct SDL_Window;

namespace ugine::ui {
    template <typename W>
    class UI
    {
    public:
        UI() = default;
        UI(const UI&) = delete;
        UI(UI&&) noexcept = delete;
        UI& operator=(const UI&) = delete;
        UI& operator=(UI&&) noexcept = delete;
        virtual void create(const W&) = 0;
        virtual ~UI() = default;
    };

    class SDLImgui final: public UI<SDL_Window>
    {
    public:
        void create(const SDL_Window& window) override;
    };
}