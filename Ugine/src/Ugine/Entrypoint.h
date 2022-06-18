#pragma once
#include <cstdio>

extern Ugine::Application* Ugine::create_application();

int main(int argc, char** args)
{
	printf("Welcome to Ugine engine");
	const auto app = Ugine::create_application();
	app->run();
	delete app;
}

