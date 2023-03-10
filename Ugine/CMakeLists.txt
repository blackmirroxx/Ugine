
set(SOURCES
		src/application.cpp src/component.cpp src/log.cpp
		src/input_handler.cpp src/renderer.cpp src/scene.cpp src/window.cpp
        src/event.cpp)

set(HEADERS
		include/ugine/application.h include/ugine/component.h include/ugine/core.h
		include/ugine/entrypoint.h include/ugine/log.h include/ugine/renderer.h
		include/ugine/scene.h include/ugine/signals.h include/ugine/vector.h
		include/ugine/window.h include/ugine/event/event.h
		include/ugine/event/event_dispatcher.h include/ugine/event/keyboard_event.h
		include/ugine/event/mouse_event.h include/ugine/event/window_event.h
		include/ugine/exception/exception.h include/ugine/input/input_handler.h
)


if(UGINE_SHARED_LIBRARY OR BUILD_SHARED_LIBS)
	add_library(Ugine SHARED ${SOURCES} ${HEADERS} )
	target_compile_definitions(Ugine PUBLIC UGINE_SHARED_LIB )
else()
	add_library(Ugine STATIC ${SOURCES} ${HEADERS} )
endif()

target_include_directories(Ugine
		PUBLIC include
)

target_compile_definitions(Ugine
		PRIVATE U_BUILD_DLL
		PRIVATE $<$<CONFIG:DEBUG>:UGINE_DEBUG>
)

target_link_libraries(Ugine
		PUBLIC spdlog::spdlog
		PRIVATE SDL2::SDL2-static
		PRIVATE SDL2_image::SDL2_image-static
)
