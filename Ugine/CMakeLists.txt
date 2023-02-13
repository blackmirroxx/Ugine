set(SRC_PATH src)
set (INCLUDE_PATH include/Ugine)

set(SOURCES 
	${SRC_PATH}/Application.cpp 
	${SRC_PATH}/Log.cpp
)

set(HEADERS 
	${INCLUDE_PATH}/Entrypoint.h
	${INCLUDE_PATH}/Application.h
	${INCLUDE_PATH}/Log.h
	${INCLUDE_PATH}/Core.h
	${INCLUDE_PATH}/Event/Event.h
	${INCLUDE_PATH}/Event/MouseEvent.h
	${INCLUDE_PATH}/Event/KeyboardEvent.h
	${INCLUDE_PATH}/Event/EventDispatcher.h
	${SRC_PATH}/Signals.h
)

add_library(Ugine SHARED
	${SOURCES}
	${HEADERS}
)

target_include_directories(Ugine
	PRIVATE include
)

target_compile_definitions(Ugine
	PRIVATE U_BUILD_DLL
)

target_link_libraries(Ugine PUBLIC spdlog::spdlog)



