#include "pch.h"
#include "Ugine/Event/MouseEvent.h"
#include "Ugine/Event/KeyboardEvent.h"

TEST(Events, MouseUpCategories) {
    const std::unique_ptr<MouseButton> mouse_up = std::make_unique<MouseUp>(mouse_button_type::right);
    EXPECT_EQ(mouse_up->get_mouse_button(), mouse_button_type::right);
    EXPECT_EQ(mouse_up->get_event_type(), event_type::mouse_up);
    EXPECT_TRUE(mouse_up->is_in_category(event_category::input_category) );
    EXPECT_TRUE(mouse_up->is_in_category(event_category::mouse_button_category) );
    EXPECT_TRUE(mouse_up->is_in_category(event_category::mouse_category) );
    EXPECT_FALSE(mouse_up->is_in_category(event_category::keyboard_category));
}

TEST(Events, MouseDownCategories) {
    const std::unique_ptr<MouseButton> mouse_down = std::make_unique<MouseDown>(mouse_button_type::left);
    EXPECT_EQ(mouse_down->get_mouse_button(), mouse_button_type::left);
    EXPECT_EQ(mouse_down->get_event_type(), event_type::mouse_down);
    EXPECT_TRUE(mouse_down->is_in_category(event_category::input_category) );
    EXPECT_TRUE(mouse_down->is_in_category(event_category::mouse_button_category) );
    EXPECT_TRUE(mouse_down->is_in_category(event_category::mouse_category) );
    EXPECT_FALSE(mouse_down->is_in_category(event_category::keyboard_category));
}

TEST(Events, MouseeWheelCategories) {
    const std::unique_ptr<Event> mouse_wheel = std::make_unique<MouseWheel>();
    EXPECT_EQ(mouse_wheel->get_event_type(), event_type::mouse_wheel);
    EXPECT_TRUE(mouse_wheel->is_in_category(event_category::input_category) );
    EXPECT_TRUE(mouse_wheel->is_in_category(event_category::mouse_category) );
    EXPECT_FALSE(mouse_wheel->is_in_category(event_category::mouse_button_category) );
    EXPECT_FALSE(mouse_wheel->is_in_category(event_category::keyboard_category));
}

TEST(Events, MouseMoveCategories) {
    const std::unique_ptr<Event> mouse_move = std::make_unique<MouseMove>();
    EXPECT_EQ(mouse_move->get_event_type(), event_type::mouse_move);
    EXPECT_TRUE(mouse_move->is_in_category(event_category::input_category) );
    EXPECT_TRUE(mouse_move->is_in_category(event_category::mouse_category) );
    EXPECT_FALSE(mouse_move->is_in_category(event_category::mouse_button_category) );
    EXPECT_FALSE(mouse_move->is_in_category(event_category::keyboard_category));
}

TEST(Events, KeyUpCategories) {
    const std::unique_ptr<KeyboardEvent> key_up = std::make_unique<KeyUp>(12);
    EXPECT_EQ(key_up->get_key_code(), 12);
    EXPECT_EQ(key_up->get_event_type(), event_type::key_up);
    EXPECT_TRUE(key_up->is_in_category(event_category::keyboard_category));
    EXPECT_TRUE(key_up->is_in_category(event_category::input_category) );
    EXPECT_FALSE(key_up->is_in_category(event_category::mouse_category) );
    EXPECT_FALSE(key_up->is_in_category(event_category::mouse_button_category) );
}

TEST(Events, KeyDownCategories) {
    const std::unique_ptr<Event> key_up = std::make_unique<KeyDown>(21);
    EXPECT_EQ(key_up->get_event_type(), event_type::key_down);
    EXPECT_TRUE(key_up->is_in_category(event_category::keyboard_category));
    EXPECT_TRUE(key_up->is_in_category(event_category::input_category) );
    EXPECT_FALSE(key_up->is_in_category(event_category::mouse_category) );
    EXPECT_FALSE(key_up->is_in_category(event_category::mouse_button_category) );
}
