#pragma once
#include "Ugine/Application.h"
#include "Ugine/Log.h"

int main(int argc, char** args)
{
	ugine::log::init();
	UGINE_CORE_INFO("Ugine has started");
	const auto app = std::unique_ptr<ugine::Application>(
            ugine::create_application());
	app->run();
	UGINE_CORE_INFO("Ugine has stopped");
}

