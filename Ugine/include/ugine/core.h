#pragma once

#define SDL_MAIN_HANDLED


#if defined(UGINE_SHARED_LIB)
#if defined(_MSC_VER)
#ifdef UGINE_BUILD
#define UGINE_API __declspec(dllexport)
#else
#define UGINE_API _declspec(dllimport)
#endif
#else
#define UGINE_API __attribute__((visibility("default"))) // GCC
#endif
#else
#define UGINE_API
#endif

#define BIT(x) (1 << x)

