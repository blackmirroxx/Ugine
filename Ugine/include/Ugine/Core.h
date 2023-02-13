#pragma once

#ifndef _WIN64 
	#error Ugine only support Windows
#endif


#if defined(_MSC_VER)
    #ifdef U_BUILD_DLL
        #define UGINE_API __declspec(dllexport)
    #else
        #define UGINE_API _declspec(dllimport)
    #endif
#elif defined(__GNUC__)
    #define UGINE_API __attribute__((visibility("default"))) // GCC
#else
    #define UGINE_API
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#define BIT(x) (1 << x)
