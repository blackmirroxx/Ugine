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
            if (this->m_pt_window_impl != nullptr) {
                throw ugine::exception::ui::UIAlreadyCreated();
            }
            this->m_pt_window_impl = &window_impl;
            this->add_impl();
        }

        /**
         * Remove the ui
         * @throw UINotCreated If remove is called before creation
         */
        void remove() const {
            if (this->m_pt_window_impl == nullptr) {
                throw ugine::exception::ui::UINotCreated();
            }
            this->remove_impl();
        }

        /**
         * Render the ui on the window
         * @throw UINotCreated If render is called before creation
         */
        void render() const {
            if (this->m_pt_window_impl == nullptr) {
                throw ugine::exception::ui::UINotCreated();
            }
            this->render_impl();
        }

    protected:
        virtual void add_impl() const = 0;

        virtual void remove_impl() const = 0;

        virtual void render_impl() const = 0;

        [[nodiscard]] ugine::window::WindowImpl* get_window_impl() const {return this->m_pt_window_impl;}
    private:
        ugine::window::WindowImpl *m_pt_window_impl{nullptr};
    };

    class UGINE_API ImguiUI final : public UI {
    private:
        void add_impl() const override;

        void remove_impl() const override;

        void render_impl() const override;
    };

}