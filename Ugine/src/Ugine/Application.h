#pragma once
#include "Core.h"

namespace Ugine
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
	};

	Application* create_application();
}

