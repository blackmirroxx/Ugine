#pragma once
#include "Ugine/Core.h"

#define EVENT_CATEGORIES(categories) [[nodiscard]] int get_category_flags() const override { return categories; }

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
	Event(Event&& e) = default;
	Event& operator= (const Event& e) = delete;
	Event& operator= (Event&& e) = default;
	[[nodiscard]] virtual int get_category_flags() const = 0;
	virtual ~Event() = default;
    [[nodiscard]] bool is_in_category(event_category category) const {
        return this->get_category_flags() & category;
    }
};
