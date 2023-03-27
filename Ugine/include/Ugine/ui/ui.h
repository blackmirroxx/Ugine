#pragma once

#include "ugine/core.h"
#include "ugine/exception/exception.h"
#include "ugine/window/window_visitor.h"
#include "ugine/event/event_handler.h"

struct SDL_Window;
namespace ugine::window {
    class WindowImpl;

    class SDLWindow;
}

namespace ugine::ui {
    class UGINE_API UI {
    public:
        UI() = default;

        UI(const UI &) = delete;

        UI(UI &&) noexcept = delete;

        UI &operator=(const UI &) = delete;

        UI &operator=(UI &&) noexcept = delete;

        virtual ~UI() = default;

        /**
         * Create the ui for a specific window
         * @param window_impl
         */
        void create(ugine::window::WindowImpl &window_impl) {
            if (this->pt_window_impl != nullptr) {
                throw ugine::exception::ui::UIAlreadyCreated();
            }
            this->pt_window_impl = &window_impl;
            this->_create();
        }

        void close() const {
            if (this->pt_window_impl == nullptr) {
                throw ugine::exception::ui::UINotCreated();
            }
            this->_close();
        }

        void render() const {
            if (this->pt_window_impl == nullptr) {
                throw ugine::exception::ui::UINotCreated();
            }
            this->_render();
        }

    protected:
        virtual void _create() const = 0;

        virtual void _close() const = 0;

        virtual void _render() const = 0;

        ugine::window::WindowImpl *pt_window_impl{nullptr};
    };

    class UGINE_API ImguiUI final : public UI {
    private:
        void _create() const override;

        void _close() const override;

        void _render() const override;
    };

}