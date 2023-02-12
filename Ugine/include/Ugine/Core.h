#pragma once

#ifndef _WIN64 
	#error Ugine only support Windows
#endif


#ifdef U_BUILD_DLL
	#define UGINE_API __declspec(dllexport)
#else
	#define UGINE_API _declspec(dllimport)
#endif

#define BIT(x) (1 << x)
