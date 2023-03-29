#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"
#include "ugine/event/event.h"
#include "ugine/renderer.h"
#include "ugine/window/input.h"

struct SDL_Window;
struct SDL_Renderer;


namespace ugine::window {
    class WindowImpl;
    struct UGINE_API WindowProps {
        std::string title = "Default title";
        int height = 650;
        int width = 1080;
    };


    class UGINE_API Window {
    public:
        using event_cb_type = std::function<void(const ugine::event::Event &)>;

        Window() = default;

        virtual ~Window() = default;

        Window(const Window &) = delete;

        Window(Window &&) = delete;

        Window &operator=(const Window &) = delete;

        Window &operator=(Window &&) = delete;

        /**
         * Dispatch window event
         * @param callback: callback call when an event occurred
         */
        virtual void on_event(event_cb_type callback) noexcept = 0;

        /**
         * Open a new OS window.
         * @throw WindowAlreadyCreated If the window is already opened, remove() must be called before
         * @param props Property of the window
         */
        virtual void open(const WindowProps &props) = 0;

        /**
         * Close the window if it has been created, otherwise does nothing
         */
        virtual void close() const = 0;

        virtual void render() const = 0;

        /**
         * Poll window's events
         */
        virtual void on_update() const = 0;

        [[nodiscard]] virtual const Input &get_input() const noexcept = 0;

    };

}


