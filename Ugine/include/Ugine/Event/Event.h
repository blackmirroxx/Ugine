#pragma once
#include "Ugine/Core.h"
#include <vector>

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

class UGINE_API Event
{
public:
	Event(event_type event_type,int category_flags): event(event_type), category_flags(category_flags) {}
	Event(const Event& e) = delete;
	Event(Event&& e) = default;
	Event& operator= (const Event& e) = delete;
	Event& operator= (Event&& e) = default;
	[[nodiscard]] int get_category_flags() const {return this->category_flags;}
    [[nodiscard]] event_type get_event_type() const {return this->event; }
	virtual ~Event() = default;
    [[nodiscard]] bool is_in_category(event_category category) const {
        return this->category_flags & category;
    }
private:
    bool handled = false;
    int category_flags = event_category::none;
    event_type event;
};

template <typename E=Event>
class UGINE_API Listener
{
public:
    Listener() = default;
    Listener(const Listener&) = delete;
    Listener(Listener&&) = delete;
    void operator=(const Listener&) = delete;
    void operator=(Listener&&) = delete;
    virtual void operator()(const E& e) = 0;
    virtual ~Listener() = default;
};
