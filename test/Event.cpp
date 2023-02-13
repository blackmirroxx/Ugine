#include "pch.h"
#include "Ugine/Event/MouseEvent.h"

TEST(Events, MouseUpCategories) {
    const std::unique_ptr<Event> mouse_up = std::make_unique<MouseUp>();
    EXPECT_TRUE(mouse_up->is_in_category(event_category::input_category) );
    EXPECT_TRUE(mouse_up->is_in_category(event_category::mouse_button_category) );
    EXPECT_TRUE(mouse_up->is_in_category(event_category::mouse_category) );
    EXPECT_FALSE(mouse_up->is_in_category(event_category::keyboard_category));
}
