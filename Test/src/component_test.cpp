#include "pch.h"
#include "ugine/component.h"
#include "ugine/renderer.h"

class PlayerComponent final: public ugine::Component2D {
public:
    PlayerComponent(): ugine::Component2D{"player",  {3, 2}, {1,4}, {2,1}} {}
    [[nodiscard]] ugine::AssetProps initial_rendering() const noexcept override {
        return {"attack", 0,0, 100, 100, 1 };
    }
};


TEST(Component, UpdatePosition) {
    auto player = PlayerComponent();
    player.update_position();
    EXPECT_EQ(player.get_velocity().get_x(), 3);
    EXPECT_EQ(player.get_velocity().get_y(), 5);
    EXPECT_EQ(player.get_position().get_x(), 6);
    EXPECT_EQ(player.get_position().get_y(), 7);
}