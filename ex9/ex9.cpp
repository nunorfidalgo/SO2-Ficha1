// ex9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//usaDLL.cpp
#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

// #include "DLL.h"
#include "../ex8/ex8.h" // adicionar ao linker: ../Debug/ex8.lib

//#define UNICODE

int _tmain(int argc, TCHAR *argv[]) {

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	//Usar a variável da Dll
	_tprintf(TEXT("Valor da variável da DLL: %d\n"), nDLL);
	//Chamar a funcao da Dll
	_tprintf(TEXT("Resultado da função da UmaString DLL: %d"), UmaString());
	return 0;
}
/*
abrir o devel cmd prompt 2017

cd C : \Users\Nuno Fidalgo\Dropbox\isec\2017 - 2018\2ano\so2\praticas\Ficha1\Debug

dumpbin ex9 / DEPENDENTS
dumpbin ex9.exe / IMPORTS

se mudarmos o nome 
*/
