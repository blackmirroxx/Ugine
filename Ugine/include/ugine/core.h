#pragma once

#define SDL_MAIN_HANDLED

#ifndef _WIN64
#error Ugine only support Windows
#endif


#if defined(UGINE_SHARED_LIB)
#if defined(_MSC_VER)
#ifdef U_BUILD_DLL
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
