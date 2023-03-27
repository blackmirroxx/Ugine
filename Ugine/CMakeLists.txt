
set(SOURCES
        src/application.cpp src/component.cpp src/log.cpp
        src/renderer.cpp src/scene.cpp src/window/sdl_window.cpp
        src/event.cpp src/input.cpp src/pch.cpp src/ui/imgui.cpp src/window/window.cpp src/graphic/opengl.cpp)

set(HEADERS
        include/ugine/application.h include/ugine/component.h include/ugine/core.h
        include/ugine/entrypoint.h include/ugine/log.h include/ugine/renderer.h
        include/ugine/scene.h include/ugine/signals.h include/ugine/vector.h
        include/ugine/window/window.h include/ugine/event/event.h
        include/ugine/event/keyboard_event.h
        include/ugine/event/mouse_event.h include/ugine/event/window_event.h
        include/ugine/exception/exception.h
        include/ugine/input.h include/ugine/pch.h include/ugine/ui/ui.h include/ugine/window/window_impl.h
        include/ugine/window/window_visitor.h include/ugine/event/event_handler.h include/ugine/utils/keycode.h
        src/utils/key_mapping.h include/ugine/utils/mouse_button.h include/ugine/window/window_factory.h include/ugine/graphic/graphic_context.h src/window/sdl_window.h src/graphic/opengl.h)

add_library(Ugine-public-options INTERFACE)
add_library(Ugine-private-options INTERFACE)

macro(add_options LIB)
    target_link_libraries(${LIB} PUBLIC Ugine-public-options)
    target_link_libraries(${LIB} PRIVATE Ugine-private-options)
    target_precompile_headers(${LIB} PRIVATE include/ugine/pch.h)
endmacro()

target_include_directories(Ugine-public-options
        INTERFACE include
        )

target_compile_definitions(Ugine-private-options
        INTERFACE U_BUILD_DLL
        )

target_link_libraries(Ugine-private-options
        INTERFACE SDL2::SDL2-static
        INTERFACE SDL2_image::SDL2_image-static
        INTERFACE glad::4.1-static
        INTERFACE imgui-static
        INTERFACE glm::glm_static
        )

target_link_libraries(Ugine-public-options
        INTERFACE spdlog::spdlog
        )

if (UGINE_SHARED_LIBRARY OR BUILD_SHARED_LIBS)
    add_library(Ugine-shared SHARED ${SOURCES} ${HEADERS})
    add_library(Ugine::Ugine-shared ALIAS Ugine-shared)
    target_compile_definitions(Ugine-shared
            PUBLIC UGINE_SHARED_LIB
            PUBLIC $<$<BOOL:UGINE_LOGGING>:UGINE_DEBUG>
            )
    add_options(Ugine-shared)
else ()
    add_library(Ugine-static STATIC ${SOURCES} ${HEADERS})
    add_library(Ugine::Ugine-static ALIAS Ugine-static)
    target_compile_definitions(Ugine-static
            PUBLIC $<$<BOOL:UGINE_LOGGING>:UGINE_DEBUG>
            )
    add_options(Ugine-static)
endif ()

if (UGINE_TEST)
    add_library(Ugine-test STATIC ${SOURCES} ${HEADERS})
    add_library(Ugine::Ugine-test ALIAS Ugine-test)
    add_options(Ugine-test)
endif ()
