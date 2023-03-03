#pragma once
#include <memory>
#include "ugine/core.h"
#include "ugine/signals.h"
#include "ugine/window.h"
#include "ugine/input/input_handler.h"
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
    };

    class UGINE_API Application2D: public Application
	{
	public:
		explicit Application2D(WindowProps props = {}): Application(), window(std::move(props)), texture_manager(window) {}
		Application2D(const Application2D&) = delete;
		Application2D(Application2D&&) = delete;
		Application2D& operator=(const Application2D&) = delete;
		Application2D& operator=(Application2D&&) = delete;
		~Application2D() override = default;
		void run() override;
		SignalDispatcher signals{};
        SceneManager2D& get_scene_manager() noexcept {return this->scene_manager;}
        SDLTextureManager& get_texture_manager() noexcept {return this->texture_manager;}
    private:
        void start_loop();
        void on_game_loop() ;
        int fps = 60;
        bool running = false;
        SDLWindow window;
        SDLInputHandler input_handler;
        SceneManager2D scene_manager;
        SDLTextureManager texture_manager;
	};

	Application2D* create_application();
}

