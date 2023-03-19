#include "pch.h"
#include "mocks.h"


TEST(Input, MousePosition) {
    auto input = mocks::TestInput();
    EXPECT_EQ(input.get_mouse_x(), 10.F);
    EXPECT_EQ(input.get_mouse_y(), 20.F);
}