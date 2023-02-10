set(ROOT_PATH src/Sandbox)

add_executable(Sandbox
	${ROOT_PATH}/Sandbox.cpp 
)

target_link_libraries(Sandbox 
	PRIVATE Ugine
)

target_include_directories(
	Sandbox
	PRIVATE ${PROJECT_SOURCE_DIR}/Ugine/src
)

add_custom_command(TARGET Sandbox POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${PROJECT_SOURCE_DIR}/Ugine/Debug/Ugine.dll"      # <--this is in-file
        "${CMAKE_CURRENT_BINARY_DIR}/Debug"
	COMMENT "Copy Ugine.dll to ${CMAKE_CURRENT_BINARY_DIR}/Debug")
