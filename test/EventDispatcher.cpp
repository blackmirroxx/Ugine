#include <termmgr.h>
#include "pch.h"
#include "Ugine/Event/Event.h"
#include "Ugine/Event/MouseEvent.h"

class PlayerMouseUpListener final: public Listener {
public:
    PlayerMouseUpListener(): Listener(event_type::mouse_up) {}
    void operator()(const Event& event) override {
        val += 1;
    }
    int val = 0;
};

TEST(EventDispatcher, RegisterAndCallListener) {
    auto player_event_dispatcher = EventDispatcher();
    std::unique_ptr<Listener> listener = std::make_unique<PlayerMouseUpListener>();
    auto* raw_ptr = dynamic_cast<PlayerMouseUpListener*>(listener.get());
    player_event_dispatcher.add_listener(listener);
    EXPECT_EQ(raw_ptr->val, 0);
    player_event_dispatcher.dispatch(MouseDown(mouse_button_type::left));
    EXPECT_EQ(raw_ptr->val, 0);
    player_event_dispatcher.dispatch(MouseUp(mouse_button_type::left));
    EXPECT_EQ(raw_ptr->val, 1);
}