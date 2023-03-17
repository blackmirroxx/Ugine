#pragma once

#include <memory>
#include "ugine/core.h"
#include "ugine/signals.h"
#include "ugine/window.h"
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

    class UGINE_API Application2D: public Application {
    public:
        Application2D() = default;
        virtual SceneManager<Scene2D> & get_scene_manager() noexcept = 0;
        virtual TextureManager2D& get_texture_manager() noexcept = 0;
    };

    class UGINE_API SDLApplication2D: public Application2D
	{
	public:
		explicit SDLApplication2D(std::unique_ptr<Window2D> pt_window = std::make_unique<SDLWindow>(),
                                  const WindowProps& props = {}
		        )
        : pt_window(std::move(pt_window))
        {
            this->pt_window->create(props);
            this->pt_window->on_event(std::bind(&SDLApplication2D::on_event, this, std::placeholders::_1));
        }
		SDLApplication2D(const SDLApplication2D&) = delete;
		SDLApplication2D(SDLApplication2D&&) = delete;
		SDLApplication2D& operator=(const SDLApplication2D&) = delete;
		SDLApplication2D& operator=(SDLApplication2D&&) = delete;
		~SDLApplication2D() override = default;
		void run() override;
        [[nodiscard]] bool is_running() const noexcept {return running;}
        SceneManager<Scene2D>& get_scene_manager() noexcept override {return this->scene_manager;}
        TextureManager2D& get_texture_manager() noexcept override {return this->pt_window->get_texture_manager();}
    private:
        void on_event(const ugine::event::Event&);
        void start_loop();
        void on_game_loop() ;
        int fps = 60;
        bool running = false;
        std::unique_ptr<Window2D> pt_window;
        SceneManager2D scene_manager;
	};


	Application* create_application();
}

