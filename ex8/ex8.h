#pragma once

#include <windows.h>
#include <tchar.h>

#define TAM 256

#ifdef EX8_EXPORTS // mudar de DLL_EXPORTS -> ver em propriedades do project-> C\C++ -> Preprocessador
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

extern "C" // usar em C ou C++
{
	extern DLL_IMP_API int nDLL;
	DLL_IMP_API int UmaString(void);
}