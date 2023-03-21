#pragma once

#include "window.h"

namespace ugine::window {
    class UGINE_API Window2D: public ugine::window::Window {
    public:
        [[nodiscard]] virtual ugine::TextureManager2D& get_texture_manager() noexcept = 0;
    };

    class UGINE_API Window2DImpl: public Window2D {
    public:
        Window2DImpl() = default;
    };

    class UGINE_API Window2DProxy final: public Window2D {
    public:
       explicit Window2DProxy(std::unique_ptr<Window2DImpl> window_impl):
           window_impl(std::move(window_impl)) {}
        void on_event(event_callback_type callback) noexcept override {
            this->window_impl->on_event(std::move(callback));
        }
        void create(const ugine::window::WindowProps& props) override {
            this->window_impl->create(props);
       }
        void render() const override {
           this->window_impl->render();
       }
        void on_update() const override {
            this->window_impl->on_update();
       }
        void close() const override {
           this->window_impl->close();
       }
        [[nodiscard]] const ugine::ui::UI& get_ui() const noexcept override {
            return this->window_impl->get_ui();
        }
        [[nodiscard]] void* get_native_window() const noexcept override {
            return this->window_impl->get_native_window();
        }
        [[nodiscard]] ugine::TextureManager2D& get_texture_manager() noexcept override {
            return this->window_impl->get_texture_manager();
        }
        [[nodiscard]] const ugine::Input& get_input() const noexcept override {
            return this->window_impl->get_input();
        }
    private:
        std::unique_ptr<Window2DImpl> window_impl;
    };

    class UGINE_API SDLWindow final: public Window2DImpl
    {
    public:
        explicit SDLWindow(std::unique_ptr<ui::SDLUI> sdl_ui = std::make_unique<ui::SDLImgui>());
        SDLWindow(const SDLWindow&) = delete;
        SDLWindow(SDLWindow&&) = delete;
        SDLWindow& operator=(const SDLWindow&) = delete;
        SDLWindow& operator=(SDLWindow&&) = delete;
        ~SDLWindow() override ;
        void create(const ugine::window::WindowProps& props) override;
        void render() const override;
        void on_update() const override;
        void close() const override;
        [[nodiscard]] const ugine::ui::UI& get_ui() const noexcept override {
            return *this->ui;
        }
        [[nodiscard]] void* get_native_window() const noexcept override {
            return this->sdl_window;
        }
        [[nodiscard]] ugine::TextureManager2D& get_texture_manager() noexcept override {
            return texture_manager;
        }
        [[nodiscard]] const ugine::Input& get_input() const noexcept override {
            return this->input;
        }
    private:
        SDL_Window* sdl_window{nullptr};
        SDL_Renderer* sdl_renderer{nullptr};
        void* gl_context{nullptr};
        std::unique_ptr<ugine::ui::SDLUI> ui;
        ugine::SDLTextureManager texture_manager{sdl_window, sdl_renderer};
        ugine::SDLInput input;
    };
}
