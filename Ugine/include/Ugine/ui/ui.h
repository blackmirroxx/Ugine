#pragma once
#include "ugine/core.h"
#include "ugine/window/window_visitor.h"

struct SDL_Window;
namespace ugine::window {
    class Window2DImpl;
    class SDLWindow;
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
        virtual ~UI() = default;
        virtual void create(const ugine::window::Window2DImpl&) const = 0;
        virtual void close(const ugine::window::Window2DImpl&) const = 0;
        virtual void on_update(const ugine::window::Window2DImpl&) const = 0;
    };

    class UGINE_API ImguiUI final: public UI
    {
    public:
        void create(const ugine::window::Window2DImpl& window) const override;
        void close(const ugine::window::Window2DImpl& window) const override;
        void on_update(const ugine::window::Window2DImpl& window) const override;
    };

}