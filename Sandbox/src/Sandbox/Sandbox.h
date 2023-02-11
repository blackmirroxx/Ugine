#pragma once
#include <Ugine/Entrypoint.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"


class Sandbox final: public ugine::Application
{
};



inline ugine::Application* ugine::create_application()
{
	const auto app = new Sandbox();
	app->signals.on_start.add_listener([](const int i ) 
		{
			std::cout << " on start event " << i << std::endl;
		});
	return app;
}

