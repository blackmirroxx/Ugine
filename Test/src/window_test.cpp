#include "pch.h"
#include "mocks.h"


TEST(Window, EventCallback) {
    auto test_window = mocks::TestWindow();
    int i = 0;
    test_window.on_event([&i](const ugine::event::Event &event) {
        ++i;
    });
    test_window.test_dispatch( ugine::event::WindowQuit() );
    EXPECT_EQ(i, 1);
}