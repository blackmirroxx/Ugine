#pragma once
#include "ugine/pch.h"
#include "ugine/window/window.h"
#include "ugine/window/window_visitor.h"
#include "ugine/ui/ui.h"


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
       explicit WindowProxy(std::unique_ptr<WindowImpl> window_impl,
                            std::unique_ptr<ui::UI> ui = nullptr):
           window_impl(std::move(window_impl)) ,ui(std::move(ui)) {
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

}
