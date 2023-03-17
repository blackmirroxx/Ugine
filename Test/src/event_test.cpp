#include "pch.h"
#include "ugine/event/mouse_event.h"
#include "ugine/event/keyboard_event.h"
#include "ugine/event/window_event.h"


TEST(Events, MouseUpCategories) {
    const std::unique_ptr<ugine::event::MouseButtonEvent> mouse_up = std::make_unique<ugine::event::MouseUp>(
            ugine::event::mouse_button_type::right, 10, 20);
    EXPECT_EQ(mouse_up->get_offset_x(), 10);
    EXPECT_EQ(mouse_up->get_offset_y(), 20);
    EXPECT_EQ(mouse_up->get_mouse_button(), ugine::event::mouse_button_type::right);
    EXPECT_EQ(mouse_up->get_event_type(), ugine::event::event_type::mouse_up);
    EXPECT_TRUE(mouse_up->is_in_category(ugine::event::event_category::input_category) );
    EXPECT_TRUE(mouse_up->is_in_category(ugine::event::event_category::mouse_button_category) );
    EXPECT_TRUE(mouse_up->is_in_category(ugine::event::event_category::mouse_category) );
    EXPECT_FALSE(mouse_up->is_in_category(ugine::event::event_category::keyboard_category));
}

TEST(Events, MouseDownCategories) {
    const std::unique_ptr<ugine::event::MouseButtonEvent> mouse_down = std::make_unique<ugine::event::MouseDown>(
            ugine::event::mouse_button_type::left, 100, 5000);
    EXPECT_EQ(mouse_down->get_mouse_button(), ugine::event::mouse_button_type::left);
    EXPECT_EQ(mouse_down->get_event_type(), ugine::event::event_type::mouse_down);
    EXPECT_TRUE(mouse_down->is_in_category(ugine::event::event_category::input_category) );
    EXPECT_TRUE(mouse_down->is_in_category(ugine::event::event_category::mouse_button_category) );
    EXPECT_TRUE(mouse_down->is_in_category(ugine::event::event_category::mouse_category) );
    EXPECT_FALSE(mouse_down->is_in_category(ugine::event::event_category::keyboard_category));
}

TEST(Events, MouseeWheelCategories) {
    const std::unique_ptr<ugine::event::MouseWheel> mouse_wheel = std::make_unique<ugine::event::MouseWheel>(0.0, 1.0);

    EXPECT_TRUE(mouse_wheel->is_up());
    EXPECT_FALSE(mouse_wheel->is_down());
    EXPECT_EQ(mouse_wheel->get_event_type(), ugine::event::event_type::mouse_wheel);
    EXPECT_TRUE(mouse_wheel->is_in_category(ugine::event::event_category::input_category) );
    EXPECT_TRUE(mouse_wheel->is_in_category(ugine::event::event_category::mouse_category) );
    EXPECT_FALSE(mouse_wheel->is_in_category(ugine::event::event_category::mouse_button_category) );
    EXPECT_FALSE(mouse_wheel->is_in_category(ugine::event::event_category::keyboard_category));
}

TEST(Events, MouseMoveCategories) {
    const std::unique_ptr<ugine::event::Event> mouse_move = std::make_unique<ugine::event::MouseMove>(10.2, 20.5);
    EXPECT_EQ(mouse_move->get_event_type(), ugine::event::event_type::mouse_move);
    EXPECT_TRUE(mouse_move->is_in_category(ugine::event::event_category::input_category) );
    EXPECT_TRUE(mouse_move->is_in_category(ugine::event::event_category::mouse_category) );
    EXPECT_FALSE(mouse_move->is_in_category(ugine::event::event_category::mouse_button_category) );
    EXPECT_FALSE(mouse_move->is_in_category(ugine::event::event_category::keyboard_category));
}

TEST(Events, KeyUpCategories) {
    const std::unique_ptr<ugine::event::KeyboardEvent> key_up = std::make_unique<ugine::event::KeyUp>(12);
    EXPECT_EQ(key_up->get_key_code(), 12);
    EXPECT_EQ(key_up->get_event_type(), ugine::event::event_type::key_up);
    EXPECT_TRUE(key_up->is_in_category(ugine::event::event_category::keyboard_category));
    EXPECT_TRUE(key_up->is_in_category(ugine::event::event_category::input_category) );
    EXPECT_FALSE(key_up->is_in_category(ugine::event::event_category::mouse_category) );
    EXPECT_FALSE(key_up->is_in_category(ugine::event::event_category::mouse_button_category) );
}

TEST(Events, KeyDownCategories) {
    const std::unique_ptr<ugine::event::KeyDown> key_down = std::make_unique<ugine::event::KeyDown>(97, true);
    EXPECT_TRUE(key_down->is_repeated());
    EXPECT_EQ(key_down->get_key_code(), 97);
    EXPECT_EQ(key_down->get_event_type(), ugine::event::event_type::key_down);
    EXPECT_TRUE(key_down->is_in_category(ugine::event::event_category::keyboard_category));
    EXPECT_TRUE(key_down->is_in_category(ugine::event::event_category::input_category) );
    EXPECT_FALSE(key_down->is_in_category(ugine::event::event_category::mouse_category) );
    EXPECT_FALSE(key_down->is_in_category(ugine::event::event_category::mouse_button_category) );
}

TEST(Events, QuitEvent) {
    const std::unique_ptr<ugine::event::Event> quit= std::make_unique<ugine::event::WindowQuit>();
    EXPECT_EQ(quit->get_event_type(), ugine::event::event_type::window_quit);
    EXPECT_TRUE(quit->is_in_category(ugine::event::event_category::window_category));
    EXPECT_FALSE(quit->is_in_category(ugine::event::event_category::input_category) );
}