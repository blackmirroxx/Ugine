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
	PRIVATE ${PROJECT_SOURCE_DIR}/Ugine/include
)

target_compile_definitions(
	Sandbox
	PRIVATE $<$<CONFIG:DEBUG>:UGINE_DEBUG>
)
