#pragma once
#include <memory>
#include "Ugine/Core.h"
#include "Ugine/Signals.h"
#include "Ugine/Window.h"
#include "Ugine/Input/InputHandler.h"
#include "Ugine/Renderer.h"
#include "Ugine/Scene.h"

namespace ugine
{
    class UGINE_API Application
	{
	public:
		explicit Application(WindowProps props = {}): window(std::move(props)), texture_manager(window) {}
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;
		virtual ~Application() = default;
		void run();
		SignalDispatcher signals{};
        SceneManager& get_scene_manager() noexcept {return this->scene_manager;}
        TextureManager& get_texture_manager() noexcept {return this->texture_manager;}
    private:
        void start_loop();
        void on_game_loop() ;
        int fps = 60;
        bool running = false;
        Window window;
        InputHandler input_handler;
        SceneManager scene_manager;
        TextureManager texture_manager;
	};

	Application* create_application();
}

