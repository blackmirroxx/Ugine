#pragma once
#include <utility>

#include "ugine/pch.h"
#include "ugine/window/window.h"
#include "ugine/window/window_visitor.h"
#include "ugine/window/window_factory.h"
#include "ugine/graphic/graphic_context.h"
#include "ugine/ui/ui.h"

union SDL_Event;

namespace ugine::window {

    class UGINE_API WindowImpl: public Window {
    public:
        WindowImpl() = default;
        void on_event(event_cb_type callback) noexcept override {
            this->event_cb.push_back(std::move(callback));
        }
        virtual void accept(const WindowImplVisitor&) = 0;
    protected:
        void dispatch(const ugine::event::Event& event) const noexcept {
            for (const auto& callback: this->event_cb) {
                callback(event);
            }
        }
    private:
        std::vector<event_cb_type> event_cb;
    };

    class UGINE_API WindowProxy final: public Window {
    public:
       explicit WindowProxy(std::unique_ptr<WindowImplFactory> window_factory,
                            graphic::context context = graphic::context::opengl,
                            std::unique_ptr<ui::UI> ui = nullptr):
            ui(std::move(ui)) {
           this->window_impl = window_factory->create(context);
       }
        void on_event(event_cb_type callback) noexcept override {
            this->window_impl->on_event(std::move(callback));
        }
        void create(const ugine::window::WindowProps& props = {}) override {
            this->window_impl->create(props);
            if (this->ui) this->ui->create(*this->window_impl);
            UGINE_CORE_INFO("Window {0} of {1}x{2}px created", props.title, props.height, props.width);
       }
        void render() const override {
            if (this->ui) this->ui->render();
           this->window_impl->render();
       }
        void on_update() const override {
            this->window_impl->on_update();
       }
        void close() const override {
           if (this->ui) this->ui->close();
           this->window_impl->close();
       }
        [[nodiscard]] const ugine::Input& get_input() const noexcept override {
            return this->window_impl->get_input();
        }
    private:
        std::unique_ptr<WindowImpl> window_impl;
        std::unique_ptr<ugine::ui::UI> ui;
    };

    class UGINE_API SDLWindow:  public WindowImpl
    {
        using sdl_event_cb_type = std::function<void(const SDL_Event&)>;
    public:
        SDLWindow();
        SDLWindow(const SDLWindow&) = delete;
        SDLWindow(SDLWindow&&) = delete;
        SDLWindow& operator=(const SDLWindow&) = delete;
        SDLWindow& operator=(SDLWindow&&) = delete;
        ~SDLWindow() override ;
        void on_update() const override;
        void close() const override;
        /**
         * Listen to the native sdl event before they are converting to ugine's events
         * @param callback: Call at each new event
         */
        void on_sdl_event(sdl_event_cb_type callback) noexcept;

        [[nodiscard]] const ugine::Input& get_input() const noexcept override {
            return this->input;
        }
        [[nodiscard]] SDL_Window* get_sdl_window() const noexcept {return this->sdl_window;}
    protected:
        void dispatch_sdl_event(const SDL_Event& sdl_event) const noexcept;
        SDL_Window* sdl_window{nullptr};
        ugine::SDLInput input;
        std::vector<sdl_event_cb_type> sdl_event_cb;
    };

    class UGINE_API SDLGlWindow final: public SDLWindow {
    public:
        void accept(const WindowImplVisitor& visitor) override {
            visitor.visit(*this);
        }
        [[nodiscard]] void* get_gl_context() const noexcept {return this->gl_context;}
        void create(const window::WindowProps& props) override;
        void render() const override;
        void close() const override;
    private:
        graphic::OpenGl opengl;
        void* gl_context{nullptr};
    };
}
