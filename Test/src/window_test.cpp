#include "pch.h"
#include "ugine/window.h"
#include "ugine/event/window_event.h"

class TestWindow final: public ugine::Window {
public:
    TestWindow() = default;
    void create(const ugine::WindowProps &props = {}) override {};
    void close() const override {}
    void on_update() const override {}
    void render() const override {}
    void dispatch_event() {
        this->event_cb(ugine::event::WindowQuit());
    }
};

TEST(Window, EventCallback) {
    auto test_window = TestWindow();
    int i = 0;
    test_window.set_event_callback([&i](const ugine::event::Event& event) {
        ++i;
    });
    test_window.dispatch_event();
    EXPECT_EQ(i, 1);
}