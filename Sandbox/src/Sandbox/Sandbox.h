#pragma once
#include <Ugine.h>


class Sandbox: public Ugine::Application
{
};


inline Ugine::Application* Ugine::create_application()
{
	return new Sandbox();
}

