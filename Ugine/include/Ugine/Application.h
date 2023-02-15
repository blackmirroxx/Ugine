#pragma once
#include <memory>
#include "Ugine/Core.h"
#include "Ugine/Signals.h"
#include "Ugine/Window.h"
#include "Ugine/Event/EventHandler.h"

namespace ugine
{
	class UGINE_API Application
	{
	public:
		Application(WindowProps props = {}): window(std::move(props)) {}
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;
		virtual ~Application() = default;
		void run() const;
		SignalDispatcher signals{};
    private:
        bool game_loop = true;
        Window window;
        EventHandler event_handler;
	};

	Application* create_application();
}

