#include "Ugine/Application.h"

void ugine::Application::run() const noexcept
{
	this->signals.on_start.emit(10);
	while (true);
}

