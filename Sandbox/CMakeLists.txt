
set(SOURCES 
	src/sandbox.cpp
)

set(HEADERS 
	src/sandbox.h src/player_component.h)

add_executable(Sandbox
	${SOURCES}
	${HEADERS}
)

target_compile_definitions(Sandbox
		PRIVATE $<$<CONFIG:DEBUG>:UGINE_DEBUG>
	)

target_link_libraries(Sandbox 
	PRIVATE Ugine
)

if (UGINE_SHARED_LIBRARY)
	# copy Ugine.dll to the executable location
	add_custom_command(TARGET Sandbox POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			$<TARGET_FILE:Ugine>
			$<TARGET_FILE_DIR:Sandbox>
		COMMENT "Copy Ugine.dll")
endif()
add_custom_command(TARGET Sandbox POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/assets
		$<TARGET_FILE_DIR:Sandbox>/assets
		COMMENT "Copy assets")
