#include "pch.h"
#include "mocks.h"

TEST(Application, CreateWindow) {
    auto window = std::make_unique<mocks::TestWindowImpl>();
    auto* pt_window = window.get();
    EXPECT_CALL(*pt_window, create(testing::_));
    const auto app = mocks::TestApplication2D( std::move(window) );
}
