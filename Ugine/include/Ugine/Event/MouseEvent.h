#pragma once
#include "Ugine/Event/Event.h"

class MouseUp final: public Event
{
public:
    EVENT_CATEGORIES(input_category | mouse_category | mouse_button_category)
};
