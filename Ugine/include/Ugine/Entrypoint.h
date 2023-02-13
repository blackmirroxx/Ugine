#pragma once
#include "Ugine/Application.h"
#include "Log.h"

int main(int argc, char** args)
{
	ugine::log::init();
	UGINE_CORE_INFO("Ugine has started");
	 const auto app = ugine::create_application();
	app->run();
	delete app;
	UGINE_CORE_INFO("Ugine has stopped");
}

