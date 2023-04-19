#pragma once

#include "ugine/core.h"
#include "ugine/exception/exception.h"
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
         * @throw UIAlreadyCreated If the ui is already created for another window, remove()
         * must be called
         * @param window_impl
         */
        void add(ugine::window::WindowImpl &window_impl) {
            if (this->pt_window_impl != nullptr) {
                throw ugine::exception::ui::UIAlreadyCreated();
            }
            this->pt_window_impl = &window_impl;
            this->_add();
        }

        /**
         * Remove the ui
         * @throw UINotCreated If remove is called before creation
         */
        void remove() const {
            if (this->pt_window_impl == nullptr) {
                throw ugine::exception::ui::UINotCreated();
            }
            this->_remove();
        }

        /**
         * Render the ui on the window
         * @throw UINotCreated If render is called before creation
         */
        void render() const {
            if (this->pt_window_impl == nullptr) {
                throw ugine::exception::ui::UINotCreated();
            }
            this->_render();
        }

    protected:
        virtual void _add() const = 0;

        virtual void _remove() const = 0;

        virtual void _render() const = 0;

        ugine::window::WindowImpl *pt_window_impl{nullptr};
    };

    class UGINE_API ImguiUI final : public UI {
    private:
        void _add() const override;

        void _remove() const override;

        void _render() const override;
    };

}