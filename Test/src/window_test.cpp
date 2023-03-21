#include "pch.h"
#include "mocks.h"


TEST(Window, EventCallback) {
    auto test_window = mocks::TestWindow2DImpl();
    int i = 0;
    test_window.on_event([&i](const ugine::event::Event &event) {
        ++i;
    });
    test_window.test_dispatch( ugine::event::WindowQuit() );
    EXPECT_EQ(i, 1);
}

TEST(Window, CreateUI) {
    auto test_ui = std::make_unique<mocks::TestUI>();
    auto* const pt_test_ui = test_ui.get();
    auto window_impl = std::make_unique<mocks::TestWindow2DImpl>(std::move(test_ui));
    auto* const pt_window_impl = window_impl.get();
    auto window2D_proxy = ugine::window::Window2DProxy(std::move(window_impl));
    EXPECT_CALL(*pt_test_ui, create(testing::_));
    EXPECT_CALL(*pt_window_impl, create(testing::_));
    window2D_proxy.create();
}