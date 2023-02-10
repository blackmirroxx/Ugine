#pragma once
#include "../src/Application.h"
#include "../src/Log.h"

extern ugine::Application* ugine::create_application();

int main(int argc, char** args)
{
	ugine::log::init();
	UGINE_CORE_INFO("Ugine has started");
	const auto app = ugine::create_application();
	app->run();
	delete app;
}

