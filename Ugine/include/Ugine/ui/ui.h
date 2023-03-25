#pragma once
#include "ugine/core.h"
#include "ugine/window/window_visitor.h"
#include "ugine/event/event_handler.h"

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
        virtual void create() const = 0;
        virtual void close() const = 0;
        virtual void render() const = 0;
        void set_window(ugine::window::Window2DImpl* window_impl) noexcept {
            this->pt_window_impl = window_impl;
        }
    protected:
        ugine::window::Window2DImpl* pt_window_impl{nullptr};
    };

    class UGINE_API ImguiUI final: public UI
    {
    public:
        void create() const override;
        void close() const override;
        void render() const override;
    };

}