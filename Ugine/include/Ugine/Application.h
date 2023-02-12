#pragma once
#include "Ugine/Core.h"
#include "../src/Signals.h"

namespace ugine
{
	class UGINE_API Application
	{
	public:
		Application() = default;
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application operator=(const Application&) = delete;
		Application operator=(Application&&) = delete;
		virtual ~Application() = default;
		void run() const noexcept;
		SignalDispatcher signals{};
	};

	Application* create_application();
}

