#pragma once
#include <memory>
#include "Ugine/Core.h"
#include "Ugine/Signals.h"
#include "Ugine/Window.h"
#include "Ugine/Input/InputHandler.h"

namespace ugine
{
    class UGINE_API Application
	{
	public:
		explicit Application(WindowProps props = {}): window(std::move(props)) {}
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;
		virtual ~Application() = default;
		void run();
		SignalDispatcher signals{};
    private:
        void start_loop();
        void on_game_loop() ;
        int fps = 60;
        bool running = false;
        Window window;
        InputHandler input_handler;
	};

	Application* create_application();
}

