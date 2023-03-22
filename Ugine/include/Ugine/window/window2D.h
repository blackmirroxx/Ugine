#pragma once
#include "ugine/window/window.h"
#include "ugine/window/window_visitor.h"
#include "ugine/ui/ui.h"

namespace ugine::window {
    class UGINE_API Window2D: public ugine::window::Window {
    public:
        [[nodiscard]] virtual ugine::TextureManager2D& get_texture_manager() noexcept = 0;
    };

    class UGINE_API Window2DImpl: public Window2D {
    public:
        Window2DImpl() = default;
        void on_event(event_callback_type callback) noexcept override {
            this->event_cb = std::move(callback);
        }
        virtual void accept(const Window2DVisitor&) const = 0;
    protected:
        void dispatch(const ugine::event::Event& event) const noexcept {
            this->event_cb(event);
        }
    private:
        event_callback_type event_cb = nullptr;
    };

    class UGINE_API Window2DProxy final: public Window2D {
    public:
       explicit Window2DProxy(std::unique_ptr<Window2DImpl> window_impl,
                              std::unique_ptr<ui::UI> ui):
           window_impl(std::move(window_impl)), ui(std::move(ui)) {}
        void on_event(event_callback_type callback) noexcept override {
            this->window_impl->on_event(std::move(callback));
        }
        void create(const ugine::window::WindowProps& props = {}) override {
            this->window_impl->create(props);
            this->ui->create(*this->window_impl);
            UGINE_CORE_INFO("Window {0} of {1}x{2}px created", props.title, props.height, props.width);
       }
        void render() const override {
           this->window_impl->render();
       }
        void on_update() const override {
            this->window_impl->on_update();
       }
        void close() const override {
           this->ui->close(*this->window_impl);
           this->window_impl->close();
       }
        [[nodiscard]] ugine::TextureManager2D& get_texture_manager() noexcept override {
            return this->window_impl->get_texture_manager();
        }
        [[nodiscard]] const ugine::Input& get_input() const noexcept override {
            return this->window_impl->get_input();
        }
    private:
        std::unique_ptr<Window2DImpl> window_impl;
        std::unique_ptr<ugine::ui::UI> ui;
    };

    class UGINE_API SDLWindow final: public Window2DImpl
    {
        friend ui::CreateImguiUI;
    public:
        SDLWindow();
        SDLWindow(const SDLWindow&) = delete;
        SDLWindow(SDLWindow&&) = delete;
        SDLWindow& operator=(const SDLWindow&) = delete;
        SDLWindow& operator=(SDLWindow&&) = delete;
        ~SDLWindow() override ;
        void create(const ugine::window::WindowProps& props) override;
        void render() const override;
        void on_update() const override;
        void close() const override;
        void accept(const Window2DVisitor& visitor) const override {
            visitor.visit(*this);
        }
        [[nodiscard]] ugine::TextureManager2D& get_texture_manager() noexcept override {
            return texture_manager;
        }
        [[nodiscard]] const ugine::Input& get_input() const noexcept override {
            return this->input;
        }
        static constexpr int OPENGL_MAJOR_VERSION = 4;
        static constexpr int OPENGL_MINOR_VERSION = 1;
    private:
        SDL_Window* sdl_window{nullptr};
        SDL_Renderer* sdl_renderer{nullptr};
        void* gl_context{nullptr};
        ugine::SDLTextureManager texture_manager{sdl_window, sdl_renderer};
        ugine::SDLInput input;
    };
}
