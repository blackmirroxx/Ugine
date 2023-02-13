set(SRC_PATH src/Sandbox)

set(SOURCES 
	${SRC_PATH}/Sandbox.cpp
)

set(HEADERS 
	${SRC_PATH}/Sandbox.h
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
	PRIVATE ${PROJECT_SOURCE_DIR}/Ugine/include
)

target_compile_definitions(
	Sandbox
	PRIVATE $<$<CONFIG:DEBUG>:UGINE_DEBUG>
)

# copy Ugine.dll to the executable location
add_custom_command(TARGET Sandbox POST_BUILD       
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
		$<TARGET_FILE:Ugine>
        $<TARGET_FILE_DIR:Sandbox>
	COMMENT "Copy Ugine.dll")