#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
//define something for Windows (32-bit and 64-bit, this part is common)
#ifdef _WIN64
#define UGINE_PLATFORM_WINDOWS
#else
#error "x86 Build not supported"
#endif
#elif __APPLE__
#define UGINE_PLATFORM_APPLE
#elif __linux__
#define UGINE_PLATFORM_LINUX
#else
#   error "Unknown compiler"
#endif
