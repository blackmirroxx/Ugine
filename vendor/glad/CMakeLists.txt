set(SOURCES src/glad.c)

set(HEADERS include/glad/glad.h include/KHR/khrplatform.h)

add_library(glad STATIC ${SOURCES} ${HEADERS})
add_library(glad::4.1-static ALIAS glad)

target_include_directories(glad PUBLIC include)
