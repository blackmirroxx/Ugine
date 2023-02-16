set(SRC_PATH src)

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



if (UGINE_SHARED_LIBRARY)
	# copy Ugine.dll to the executable location
	add_custom_command(TARGET Sandbox POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			$<TARGET_FILE:Ugine>
			$<TARGET_FILE_DIR:Sandbox>
		COMMENT "Copy Ugine.dll")
endif()
add_custom_command(
		 TARGET Sandbox POST_BUILD
		 COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:Sandbox>"
		 COMMENT "Copy SDL2.dll"
)
