cmake_minimum_required(VERSION 3.24)
project(UgineProject VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(vendor/spdlog)
add_subdirectory(Ugine)
