include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b73f27fd164456fea9aba56163f5511355a03272.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  Test
  src/signals_test.cpp src/event_test.cpp
  src/event_dispatcher_test.cpp src/vector_test.cpp src/scene_test.cpp src/texture_manager_test.cpp src/component_test.cpp src/window_test.cpp)

#target_precompile_headers(
#		Test
#		PRIVATE src/pch.h
#)


target_link_libraries(
		Test
	PRIVATE GTest::gtest_main
	PRIVATE GTest::gmock_main
	PRIVATE Ugine
)


include(GoogleTest)
gtest_discover_tests(Test)

