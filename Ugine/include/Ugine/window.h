#pragma once

#include <string>
#include <utility>
#include "ugine/core.h"
#include "ugine/event/event.h"
#include "ugine/renderer.h"
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
         * @param callback: callback call when an event occured
         */
        void on_event(event_callback_type callback) noexcept {
            this->event_cb = std::move(callback);
        }
        virtual void create(const WindowProps& props = {}) = 0;
        virtual void close() const = 0;
        virtual void render() const = 0;
        virtual void on_update() const = 0;
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

    class UGINE_API SDLWindow: public Window2D
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
    private:
        SDL_Window* sdl_window{nullptr};
        SDL_Renderer* sdl_renderer{nullptr};
        SDLTextureManager texture_manager{sdl_window, sdl_renderer};
    };
}

