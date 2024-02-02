#pragma once

#ifdef DGE_PLATFORM_WINDOWS
	#ifdef DGE_BUILD_DLL
		#define DESSERT_API __declspec(dllexport)
	#else
		#define DESSERT_API __declspec(dllimport)
	#endif

#else 
	#error Dessert only support Windows!
#endif 

#define BIT(x) (1 << x)