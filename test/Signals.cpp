#include "pch.h"
#include <Ugine/Signals.h>

TEST(Signals, ShouldCallTheCallbackOnEmit) {
	int i = 0;
	ugine::Signal<int> signal;
	signal.add_listener([&i](const int val) { i = val; });
	EXPECT_EQ(i, 0);
	signal.emit(2);
	EXPECT_EQ(i, 2);
}

TEST(Signals, ShouldClearCallback)
{
	int i = 0;
	ugine::Signal<int> signal;
	signal.add_listener([&i](const int val) { i = val; });
	signal.clear();
	signal.emit(2);
	EXPECT_EQ(i, 0);
}