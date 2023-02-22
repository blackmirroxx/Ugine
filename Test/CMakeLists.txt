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
  src/Signals.cpp
  src/Event.cpp
  src/EventDispatcher.cpp
        src/Vector.cpp src/Scene.cpp)

#target_precompile_headers(
#		Test
#		PRIVATE src/pch.h
#)


target_link_libraries(
		Test
	PRIVATE GTest::gtest_main
	PRIVATE Ugine
)


include(GoogleTest)
gtest_discover_tests(Test)

