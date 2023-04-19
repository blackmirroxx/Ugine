#pragma once

#include "ugine/pch.h"
#include "ugine/window/window.h"
#include "ugine/ui/ui.h"
#include "ugine/window/window_visitor.h"

namespace ugine::window {

    class UGINE_API WindowImpl {
    public:
        using event_cb_type = std::function<void(const ugine::event::Event &)>;
        WindowImpl() = default;
        WindowImpl(const WindowImpl&) = delete;
        WindowImpl(WindowImpl&&) = delete;
        WindowImpl& operator=(const WindowImpl&) = delete;
        WindowImpl& operator=(WindowImpl&&) = delete;
        virtual ~WindowImpl() = default;

        virtual void open(const WindowProps &props) = 0;

        virtual void close() const = 0;

        virtual void render() const = 0;

        virtual void on_update() const = 0;

        [[nodiscard]] virtual const Input &get_input() const noexcept = 0;

        void on_event(event_cb_type callback) noexcept {
            this->event_cb.push_back(std::move(callback));
        }

        // TODO must be hidden from public api (can be hidden thank to UGINE_BUILD macro)
        virtual void accept(const WindowImplVisitor &) = 0;

    protected:
        void dispatch(const ugine::event::Event &event) const noexcept {
            for (const auto &callback: this->event_cb) {
                callback(event);
            }
        }

    private:
        std::vector<event_cb_type> event_cb;
    };

    class UGINE_API BaseWindow : public Window {
    public:
        explicit BaseWindow(std::unique_ptr<WindowImpl> window_impl,
                            std::unique_ptr<ui::UI> ui) :
                window_impl(std::move(window_impl)), ui(std::move(ui)) {}

        void on_event(event_cb_type callback) noexcept override {
            this->window_impl->on_event(std::move(callback));
        }

        void open(const ugine::window::WindowProps &props = {}) override {
            this->window_impl->open(props);
            if (this->ui) this->ui->add(*this->window_impl);
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
            if (this->ui) this->ui->remove();
            this->window_impl->close();
        }

        [[nodiscard]] const ugine::window::Input &get_input() const noexcept override {
            return this->window_impl->get_input();
        }

    protected:
        [[nodiscard]] virtual std::unique_ptr<WindowImpl> create() const = 0;

    private:
        std::unique_ptr<WindowImpl> window_impl;
        std::unique_ptr<ugine::ui::UI> ui;
    };

    class UGINE_API WindowsWindow final : public BaseWindow {
    public:
        explicit WindowsWindow(std::unique_ptr<ui::UI> ui = nullptr): BaseWindow(this->create(), std::move(ui)) {}
    private:
        [[nodiscard]] std::unique_ptr<WindowImpl> create() const override;
    };

    class UGINE_API LinuxWindow final : public BaseWindow {
    public:
        explicit LinuxWindow(std::unique_ptr<ui::UI> ui = nullptr): BaseWindow(this->create(), std::move(ui)) {}
    private:
        [[nodiscard]] std::unique_ptr<WindowImpl> create() const override;
    };

    class UGINE_API AppleWindow final : public BaseWindow {
    public:
        explicit AppleWindow(std::unique_ptr<ui::UI> ui = nullptr): BaseWindow(this->create(), std::move(ui)) {}
    private:
        [[nodiscard]] std::unique_ptr<WindowImpl> create() const override;
    };
}

#ifdef UGINE_PLATFORM_APPLE
#define UGINE_WINDOW ugine::window::AppleWindow
#elif defined(UGINE_PLATFORM_LINUX)
#define UGINE_WINDOW ugine::window::LinuxWindow
#else
#define UGINE_WINDOW ugine::window::WindowsWindow
#endif

