cmake_minimum_required(VERSION 3.24)
project(UgineProject VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(UGINE_SHARED_LIBRARY "Build shared library" OFF)

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/SDL)
add_subdirectory(Ugine)
add_subdirectory(Test)
add_subdirectory(Sandbox)
