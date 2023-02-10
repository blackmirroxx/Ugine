set(ROOT_PATH src/Ugine)

add_library(Ugine
	${ROOT_PATH}/Application.cpp 
	${ROOT_PATH}/Log.cpp
)
target_link_libraries(Ugine PRIVATE spdlog::spdlog)
target_include_directories(
	Ugine
	PUBLIC ${PROJECT_SOURCE_DIR}/vendor/spdlog/include
)
