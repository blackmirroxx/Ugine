#include "pch.h"
#include "mocks.h"


TEST(Application2D, StopOnQuit) {
    auto test_window = std::make_unique<mocks::TestWindow2D>();
    auto* pt_window = test_window.get();
    auto test_app = mocks::TestApplication2D(std::move(test_window));
    test_app.set_running(true);
    EXPECT_TRUE(test_app.is_running());
    pt_window->test_dispatch(ugine::event::WindowQuit());
    EXPECT_FALSE(test_app.is_running());
}