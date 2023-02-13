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

class UGINE_API Listener
{
public:
    explicit Listener(event_type event_t): event_t(event_t) {}
    Listener(const Listener&) = delete;
    Listener(Listener&&) = delete;
    void operator=(const Listener&) = delete;
    void operator=(Listener&&) = delete;
    virtual void operator()(const Event& e) = 0;
    virtual ~Listener() = default;
    [[nodiscard]] event_type get_event_type() const noexcept {return event_t;}
protected:
   event_type event_t;
};

class UGINE_API EventDispatcher
{
public:
    void add_listener(std::unique_ptr<Listener>& listener) {this->listeners.push_back(std::move(listener));}
    void dispatch(const Event& event) {
        for (auto& listener: listeners) {
            if (listener->get_event_type() == event.get_event_type()) {
                listener->operator()(event);
            }
        }
    }
private:
    std::vector<std::unique_ptr<Listener>> listeners;
};