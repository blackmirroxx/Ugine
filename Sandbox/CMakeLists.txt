
set(SOURCES 
	src/sandbox.cpp
)

set(HEADERS 
	src/sandbox.h src/player_component.h)

add_executable(Sandbox
	${SOURCES}
	${HEADERS}
)

target_link_libraries(Sandbox
	PRIVATE	$<IF:$<BOOL:${UGINE_SHARED_LIBRARY}>, Ugine::Ugine-shared, Ugine::Ugine-static>
)

if (UGINE_SHARED_LIBRARY)
	# copy Ugine.dll to the executable location
	add_custom_command(TARGET Sandbox POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			$<TARGET_FILE:Ugine::Ugine-shared>
			$<TARGET_FILE_DIR:Sandbox>
		COMMENT "Copy Ugine.dll")
endif()
add_custom_command(TARGET Sandbox POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/assets
		$<TARGET_FILE_DIR:Sandbox>/assets
		COMMENT "Copy assets")
