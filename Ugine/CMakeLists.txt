set(SRC_PATH src)
set (INCLUDE_PATH include/Ugine)

set(SOURCES
	${SRC_PATH}/Application.cpp 
	${SRC_PATH}/Log.cpp
	${SRC_PATH}/Window.cpp)

set(HEADERS 
	${INCLUDE_PATH}/Entrypoint.h
	${INCLUDE_PATH}/Application.h
	${INCLUDE_PATH}/Log.h
	${INCLUDE_PATH}/Core.h
	${INCLUDE_PATH}/Event/Event.h
	${INCLUDE_PATH}/Event/MouseEvent.h
	${INCLUDE_PATH}/Event/KeyboardEvent.h
	${INCLUDE_PATH}/Event/EventDispatcher.h
	${INCLUDE_PATH}/Window.h
	${INCLUDE_PATH}/Signals.h
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
)

target_link_libraries(Ugine
		PUBLIC spdlog::spdlog
		PUBLIC SDL2::SDL2
		)
