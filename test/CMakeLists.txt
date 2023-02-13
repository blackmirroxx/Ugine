include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b73f27fd164456fea9aba56163f5511355a03272.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ugine_test
  Signals.cpp
		Event.cpp)

target_include_directories(
	ugine_test
	PRIVATE ${PROJECT_SOURCE_DIR}/Ugine/include
	PRIVATE ${PROJECT_SOURCE_DIR}/Ugine/src
)

target_link_libraries(
  ugine_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ugine_test)

