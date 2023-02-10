set(ROOT_PATH src)

set(SOURCES 
	${ROOT_PATH}/Application.cpp 
	${ROOT_PATH}/Log.cpp
)

set(HEADERS 
	include/Ugine/Entrypoint.h
	${ROOT_PATH}/Application.h
	${ROOT_PATH}/Core.h
	${ROOT_PATH}/Log.h
	${ROOT_PATH}/Signals.h
)

add_library(Ugine SHARED
	${SOURCES}
	${HEADERS}
)


target_compile_definitions(Ugine
	PRIVATE U_BUILD_DLL
)
target_link_libraries(Ugine PUBLIC spdlog::spdlog)


# copy Ugine.dll to the executable location
add_custom_command(TARGET Ugine POST_BUILD       
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        "${CMAKE_CURRENT_BINARY_DIR}/Debug/Ugine.dll"
        "${PROJECT_SOURCE_DIR}/Sandbox/Debug"
	COMMENT "Copy Ugine.dll to ${PROJECT_SOURCE_DIR}/Sandbox/Debug")

