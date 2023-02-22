#include "pch.h"
#include <termmgr.h>
#include "Ugine/Event/Event.h"
#include "Ugine/Event/MouseEvent.h"
#include "Ugine/Event/EventDispatcher.h"


class PlayerMouseUpListener final: public ugine::Listener<ugine::MouseUp> {
public:
    void operator()(const ugine::MouseUp& event) override {
        val += 1;
    }
    int val = 0;
};

TEST(EventDispatcher, RegisterAndCallListener) {
    auto mouse_up_event_dispatcher = ugine::EventDispatcher<ugine::MouseUp>();
    std::unique_ptr<ugine::Listener<ugine::MouseUp>> listener = std::make_unique<PlayerMouseUpListener>();
    auto* raw_ptr = dynamic_cast<PlayerMouseUpListener*>(listener.get());
    mouse_up_event_dispatcher.set_listener(listener);
    EXPECT_EQ(raw_ptr->val, 0);
    mouse_up_event_dispatcher.dispatch(ugine::MouseUp(ugine::mouse_button_type::left));
    EXPECT_EQ(raw_ptr->val, 1);
}
