// ex4.cpp : Defines the entry point for the console application.
//

//#define UNICODE

#include "stdafx.h"

#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

#define MAX 256

// NOTA: no cmd: tasklist | findstr "ex4_2.exe"
// ou tasklist | findstr "notepad.exe"

int _tmain(int argc, LPTSTR argv[]) {
	TCHAR executavel[MAX], resp;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	//UNICODE: Por defeito, a consola Windows não processe caracteres wide.
	//A maneira mais fácil para ter esta funcionalidade é chamar _setmode:

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	_tprintf(TEXT("Lançar outra aplicação igual a mim (S/N)?"));
	_tscanf_s(TEXT("%c"), &resp, 1);
	if (resp == 'S' || resp == 's') {
		ZeroMemory(&si, sizeof(STARTUPINFO));//É equivalente preencher com 0s
		si.cb = sizeof(STARTUPINFO);
		//GetModuleFileName(NULL, executavel, MAX);
		_tcscpy_s(executavel, TEXT("notepad.exe"));
		_tprintf(TEXT("Processo a ser lançado:%s\n"), executavel);
		if (CreateProcess(NULL, executavel, NULL, NULL, 0, 0, NULL, NULL, &si, &pi))
			_tprintf(TEXT("Sucesso\n"));
		else
			_tprintf(TEXT("Erro\n"));
	}
	return 0;
}