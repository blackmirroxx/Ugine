cmake_minimum_required(VERSION 3.24)
project(UgineProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(UGINE_SHARED_LIBRARY "Build shared library" ${BUILD_SHARED_LIBS})
option(UGINE_TEST "Build Ugine tests" OFF)
option(UGINE_LOGGING "Display logging information" OFF)

# Turning off BUILD_SHARED_LIBS so that dependencies are static build
set(BUILD_SHARED_LIBS OFF)
set(SDL2IMAGE_INSTALL OFF)
set(SDL2IMAGE_SAMPLES OFF)

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/SDL)
add_subdirectory(vendor/SDL_image)
add_subdirectory(Ugine)
if (UGINE_TEST)
    add_subdirectory(Test)
endif()
add_subdirectory(Sandbox)

# Reset BUILD_SHARED_LIBS variable
set(BUILD_SHARED_LIBS ${UGINE_SHARED_LIBRARY})
