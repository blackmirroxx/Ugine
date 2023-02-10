set(ROOT_PATH src/Sandbox)

set(SOURCES 
	${ROOT_PATH}/Sandbox.cpp 
)

set(HEADERS 
	${ROOT_PATH}/Sandbox.h
)

add_executable(Sandbox
	${SOURCES}
	${HEADERS}
)

target_link_libraries(Sandbox 
	PRIVATE Ugine
)

target_include_directories(
	Sandbox
	PRIVATE ${PROJECT_SOURCE_DIR}/Ugine/src
)

# copy Ugine.dll to the executable location
add_custom_command(TARGET Sandbox POST_BUILD       
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        "${PROJECT_SOURCE_DIR}/Ugine/Debug/Ugine.dll"  
        "${CMAKE_CURRENT_BINARY_DIR}/Debug"
	COMMENT "Copy Ugine.dll to ${CMAKE_CURRENT_BINARY_DIR}/Debug")
