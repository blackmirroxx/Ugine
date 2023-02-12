#pragma once
#include "Ugine/Core.h"

enum class event_type
{
	mouse_up, mouse_down, mouse_wheel, mouse_move, key_up, key_down
};

enum event_category
{
	none = 0,
	input_category = BIT(0),
	keyboard_category = BIT(1),
	mouse_category = BIT(2),
	mouse_button_category = BIT(3)
};

class Event
{
public:
	Event() = default;
	Event(const Event& e) = delete;
	Event(Event&& e) = delete;
	Event& operator= (const Event& e) = delete;
	Event& operator= (Event&& e) = delete;
	[[nodiscard]] virtual int get_category_flags() const = 0;
	virtual ~Event() = default;
};
