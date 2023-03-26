cmake_minimum_required(VERSION 3.24)
project(UgineProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(UGINE_SHARED_LIBRARY "Build shared library" ${BUILD_SHARED_LIBS})
option(UGINE_TEST "Build Ugine tests" OFF)
option(UGINE_LOGGING "Display logging information" OFF)

function(build_dependencies folder)
    # Turning off BUILD_SHARED_LIBS so that dependencies are static build
    set(BUILD_SHARED_LIBS OFF)
    set(SDL2IMAGE_INSTALL OFF)
    set(SDL2IMAGE_SAMPLES OFF)
    set(IMGUI_USE_SDL2 ON)
    set(IMGUI_USE_OPENGL3 ON)
    set(BUILD_STATIC_LIBS ON) # for glm
    add_subdirectory(${folder}/spdlog)
    add_subdirectory(${folder}/SDL)
    add_subdirectory(${folder}/SDL_image)
    add_subdirectory(${folder}/glad)
    add_subdirectory(${folder}/imgui)
    add_subdirectory(${folder}/glm)
endfunction()

function(build_tests)
    if (UGINE_TEST)
        set(BUILD_SHARED_LIBS OFF)
        add_subdirectory(Test)
    endif()
endfunction()

build_dependencies(vendor)
add_subdirectory(Ugine)
build_tests()
add_subdirectory(Sandbox)

