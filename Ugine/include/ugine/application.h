#pragma once

#include "ugine/core.h"
#include "ugine/signals.h"
#include "ugine/window/window.h"
#include "ugine/window/window_impl.h"
#include "ugine/renderer.h"
#include "ugine/scene.h"
#include "ugine/event/event_handler.h"
#include "ugine/event/window_event.h"

namespace ugine {
    class UGINE_API Application : protected event::EventHandlerMixin {
    public:
        Application() = default;

        Application(const Application &) = delete;

        Application(Application &&) = delete;

        Application &operator=(const Application &) = delete;

        Application &operator=(Application &&) = delete;

        virtual ~Application() = default;

        virtual void run() = 0;

        [[nodiscard]] SignalDispatcher &get_signals() noexcept { return m_signals; }

    private:
        SignalDispatcher m_signals{};
    };


    class UGINE_API Application2D : public Application {
    public:
        explicit Application2D(std::unique_ptr<window::Window> pt_window =
        std::make_unique<UGINE_WINDOW>( std::make_unique<ui::ImguiUI>()),
                               std::unique_ptr<SceneManager<Scene2D>> scene_manager = std::make_unique<SceneManager2D>(),
                               const window::WindowProps &props = {}
        )
                : m_pt_window(std::move(pt_window)), m_pt_scene_manager(std::move(scene_manager)) {
            this->m_pt_window->open(props);
            this->m_pt_window->on_event([this](const ugine::event::Event &event) {
                UGINE_CORE_TRACE("Event {0}", event.to_string());
                this->handle_event(event);
            });
        }

        Application2D(const Application2D &) = delete;

        Application2D(Application2D &&) = delete;

        Application2D &operator=(const Application2D &) = delete;

        Application2D &operator=(Application2D &&) = delete;

        ~Application2D() override = default;

        void run() override;

        [[nodiscard]] bool is_running() const noexcept { return m_running; }

        [[nodiscard]] SceneManager<Scene2D> &get_scene_manager() const noexcept { return *this->m_pt_scene_manager; }

    private:
        void handle(const ugine::event::WindowQuit &event) final {
            this->m_running = false;
            event.stop_propagation();
        }

        void start_loop();

        void on_game_loop() const;

        bool m_running = false;
        std::unique_ptr<window::Window> m_pt_window;
        std::unique_ptr<SceneManager<Scene2D>> m_pt_scene_manager;
    };

    Application *create_application();
}

