#include "pch.h"
#include "mocks.h"
#include "ugine/event/window_event.h"


TEST(Window, EventCallback) {
    auto test_window = mocks::TestWindow2DImpl();
    int i = 0;
    test_window.on_event([&i](const ugine::event::Event &event) {
        ++i;
    });
    test_window.on_event([&i](const ugine::event::Event &event) {
        ++i;
    });
    test_window.test_dispatch( ugine::event::WindowQuit() );
    EXPECT_EQ(i, 2);
}

TEST(Window, CreateWindow) {
    auto test_ui = std::make_unique<mocks::TestUI>() ;
    auto test_window_impl = std::make_unique<mocks::TestWindow2DImpl>();
    auto* const pt_test_window_impl = test_window_impl.get();
    auto* const pt_test_ui = test_ui.get();
    const auto window_proxy = std::make_unique<ugine::window::Window2DProxy>(
            std::move(test_window_impl), std::move(test_ui)
            );
    EXPECT_CALL(*pt_test_ui, _create());
    EXPECT_CALL(*pt_test_window_impl, create(testing::_));
    window_proxy->create();
}

TEST(Window, CloseWindow) {
    auto test_ui = std::make_unique<mocks::TestUI>() ;
    auto test_window_impl = std::make_unique<mocks::TestWindow2DImpl>();
    auto* const pt_test_window_impl = test_window_impl.get();
    auto* const pt_test_ui = test_ui.get();
    const auto window_proxy = std::make_unique<ugine::window::Window2DProxy>(
            std::move(test_window_impl), std::move(test_ui)
    );
    window_proxy->create();
    EXPECT_CALL(*pt_test_ui, _close());
    EXPECT_CALL(*pt_test_window_impl, close());
    window_proxy->close();
}

TEST(Window, Rendering) {
    auto test_ui = std::make_unique<mocks::TestUI>() ;
    auto test_window_impl = std::make_unique<mocks::TestWindow2DImpl>();
    auto* const pt_test_window_impl = test_window_impl.get();
    auto* const pt_test_ui = test_ui.get();
    const auto window_proxy = std::make_unique<ugine::window::Window2DProxy>(
            std::move(test_window_impl), std::move(test_ui)
    );
    window_proxy->create();
    EXPECT_CALL(*pt_test_ui, _render());
    EXPECT_CALL(*pt_test_window_impl, render());
    window_proxy->render();
}

TEST(UI, UiAlreadyCreated) {
    auto test_ui = mocks::TestUI() ;
    auto test_window_impl = mocks::TestWindow2DImpl();
    EXPECT_CALL(test_ui, _create()).Times(1);
    test_ui.create(test_window_impl);
    EXPECT_CALL(test_ui, _create()).Times(0);
    EXPECT_THROW(
            test_ui.create(test_window_impl),
            ugine::exception::ui::UIAlreadyCreated
    );
}

TEST(UI, UINotCreated) {
    auto test_ui = mocks::TestUI() ;
    auto test_window_impl = mocks::TestWindow2DImpl();
    EXPECT_CALL(test_ui, _render()).Times(0);
    EXPECT_THROW(
            test_ui.render(),
            ugine::exception::ui::UINotCreated
    );
    EXPECT_CALL(test_ui, _close()).Times(0);
    EXPECT_THROW(
            test_ui.close(),
            ugine::exception::ui::UINotCreated
    );
}