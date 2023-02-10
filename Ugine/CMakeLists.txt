set(ROOT_PATH src/Ugine)

add_library(Ugine SHARED
	${ROOT_PATH}/Application.cpp 
	${ROOT_PATH}/Log.cpp
)

target_compile_definitions(Ugine
	PRIVATE U_BUILD_DLL
)
target_link_libraries(Ugine PUBLIC spdlog::spdlog)
