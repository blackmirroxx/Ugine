#pragma once
#include "Ugine/Event/Event.h"

class MouseUp final: public Event
{
public:
	[[nodiscard]] int get_category_flags() const override
	{
		return input_category | mouse_category | mouse_button_category;
	}
};
