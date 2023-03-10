#include "pch.h"
#include "ugine/event/event.h"
#include "ugine/event/mouse_event.h"
#include "ugine/event/event_dispatcher.h"


class PlayerMouseUpListener final: public ugine::event::Listener<ugine::event::MouseUp> {
public:
    void operator()(const ugine::event::MouseUp& event) override {
        val += 1;
    }
    int val = 0;
};

TEST(EventDispatcher, RegisterAndCallListener) {
    auto mouse_up_event_dispatcher = ugine::event::EventDispatcher<ugine::event::MouseUp>();
    std::unique_ptr<ugine::event::Listener<ugine::event::MouseUp>> listener = std::make_unique<PlayerMouseUpListener>();
    auto* raw_ptr = dynamic_cast<PlayerMouseUpListener*>(listener.get());
    mouse_up_event_dispatcher.set_listener(std::move(listener));
    EXPECT_EQ(raw_ptr->val, 0);
    mouse_up_event_dispatcher.dispatch(ugine::event::MouseUp(ugine::event::mouse_button_type::left));
    EXPECT_EQ(raw_ptr->val, 1);
}
