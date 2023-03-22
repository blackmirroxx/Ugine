#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"
#include "ugine/signals.h"
#include "ugine/window/window.h"
#include "ugine/window/window_impl.h"
#include "ugine/renderer.h"
#include "ugine/scene.h"

namespace ugine
{

    class UGINE_API Application
    {
    public:
        Application() = default;
        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;
        virtual ~Application() = default;
        virtual void run() = 0;
        [[nodiscard]] SignalDispatcher& get_signals() noexcept {return signals;}
    protected:
        SignalDispatcher signals{};
    };

    class UGINE_API Application2D: public Application
	{
	public:
		explicit Application2D(std::unique_ptr<window::Window2D> pt_window =
                std::make_unique<window::Window2DProxy>(std::make_unique<window::SDLWindow>(),
                        std::make_unique<ui::ImguiUI>()),
		       std::unique_ptr<SceneManager<Scene2D>> scene_manager = std::make_unique<SceneManager2D>(),
               const window::WindowProps& props = {}
		        )
        : pt_window(std::move(pt_window)), pt_scene_manager(std::move(scene_manager))
        {
            this->pt_window->create(props);
            this->pt_window->on_event(std::bind(&Application2D::on_event, this, std::placeholders::_1));
        }
		Application2D(const Application2D&) = delete;
		Application2D(Application2D&&) = delete;
		Application2D& operator=(const Application2D&) = delete;
		Application2D& operator=(Application2D&&) = delete;
		~Application2D() override = default;
		void run() override;
        [[nodiscard]] bool is_running() const noexcept {return running;}
        SceneManager<Scene2D>& get_scene_manager() noexcept {return *this->pt_scene_manager;}
        TextureManager2D& get_texture_manager() noexcept {return this->pt_window->get_texture_manager();}
    private:
        void on_event(const ugine::event::Event&);
        void start_loop();
        void on_game_loop();
        bool running = false;
        std::unique_ptr<window::Window2D> pt_window;
        std::unique_ptr<SceneManager<Scene2D>> pt_scene_manager;
	};

	Application* create_application();
}

