#pragma once

#include <string>
#include <utility>
#include "ugine/core.h"
#include "ugine/event/event.h"
#include "ugine/renderer.h"
#include "ugine/input.h"
#include <functional>

struct SDL_Window;
struct SDL_Renderer;

namespace ugine {

    struct UGINE_API WindowProps {
        std::string title = "Default title";
        int height = 650;
        int width = 650;
    };


    class UGINE_API Window
    {
    public:
        using event_callback_type = std::function<void(const ugine::event::Event&)>;
        Window() = default;
        virtual ~Window() = default;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;
        /**
         * Dispatch window event
         * @param callback: callback call when an event occurred
         */
        void on_event(event_callback_type callback) noexcept {
            this->event_cb = std::move(callback);
        }
        /**
         * Create a new OS window, if the window is already created a
         * WindowAlreadyCreated exception is thrown, to recreate the window you
         * must call close before.
         * @param props Property of the window
         */
        virtual void create(const WindowProps& props = {}) = 0;
        /**
         * Close the window if it has been created, otherwise does nothing
         */
        virtual void close() const = 0;
        virtual void render() const = 0;
        /**
         * Poll window's events
         */
        virtual void on_update() const = 0;
        [[nodiscard]] virtual const Input& get_input() const noexcept = 0;
    protected:
        void dispatch(const ugine::event::Event& event) const noexcept {
            this->event_cb(event);
        }
    private:
        event_callback_type event_cb = nullptr;
    };

    class UGINE_API Window2D: public Window {
    public:
        [[nodiscard]] virtual TextureManager2D& get_texture_manager() noexcept = 0;
    };

    class UGINE_API SDLWindow final: public Window2D
    {
    public:
        SDLWindow();
        void create(const WindowProps& props) override;
        void render() const override;
        SDLWindow(const SDLWindow&) = delete;
        SDLWindow(SDLWindow&&) = delete;
        SDLWindow& operator=(const SDLWindow&) = delete;
        SDLWindow& operator=(SDLWindow&&) = delete;
        ~SDLWindow() override ;
        void on_update() const override;
        void close() const override;
        TextureManager2D& get_texture_manager() noexcept override {
            return texture_manager;
        }
        [[nodiscard]] const Input& get_input() const noexcept override {
            return this->input;
        }
    private:
        SDL_Window* sdl_window{nullptr};
        SDL_Renderer* sdl_renderer{nullptr};
        void* gl_context{nullptr};
        SDLTextureManager texture_manager{sdl_window, sdl_renderer};
        SDLInput input;
    };
}

