// ex11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//usaDLL.cpp
#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

typedef int (*DLL_FUNCTION)(void);

int _tmain(int argc, TCHAR *argv[]) {

	#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	#endif

	HINSTANCE hDLL = LoadLibrary(TEXT("ex8.dll"));
	int *nDLL;
	DLL_FUNCTION Func;

	if (hDLL != NULL)
	{
		if (!hDLL)
		{
			// handle the error  
			FreeLibrary(hDLL);
			_tprintf(TEXT("Erro ao carregar a DLL!\n"));
			return 1;
		}
		else
		{
			// call the function  
			
			//Usar a variável da Dll
			nDLL = (int*)GetProcAddress(hDLL, "nDLL");
			_tprintf(TEXT("Valor da variável da DLL: %d\n"), *nDLL);

			//Chamar a funcao da Dll
			Func = (DLL_FUNCTION)GetProcAddress(hDLL, "UmaString");
			_tprintf(TEXT("Resultado da função da UmaString DLL: %d"), Func() );
			FreeLibrary(hDLL);
			return 0;
		}
	}
}