
#include <windows.h>
#include "ex8.h" //DLL.h"

char ponteiro[40960];

int nDLL = 1234;

int UmaString(void) {
	TCHAR str[TAM];
	_tprintf(TEXT("teste DLL\n"));
	_tprintf(TEXT("Dentro da Dll\n"));
	_tprintf(TEXT("Introduza uma frase:"));
	_fgetts(str, TAM, stdin);
	if (_tcslen(str) > 1)
		return 1;
	else
		return 0;
}

BOOL WINAPI DllMain(HANDLE hInstance, DWORD razao, LPVOID tipo_declaracao) {
	switch (razao) {

	case DLL_PROCESS_ATTACH:
		if (tipo_declaracao == NULL)
			_tprintf(TEXT("O processou carregou a biblioteca explicitamente\n"));
			//MessageBox(NULL, TEXT("O processou carregou a biblioteca explicitamente"), TEXT("DLLmain"), MB_OK);
		else
			_tprintf(TEXT("O processou carregou a biblioteca explicitamente\n"));
			//MessageBox(NULL, TEXT("O processou carregou a biblioteca implicitamente"), TEXT("DLLmain"), MB_OK);
		break;

	case DLL_PROCESS_DETACH:
		if (tipo_declaracao == NULL)
			_tprintf(TEXT("O processou desmapeou a biblioteca explicitamente\n"));
			//MessageBox(NULL, TEXT("O processou desmapeou a biblioteca explicitamente"),	TEXT("DLLmain"), MB_OK);
		else
			_tprintf(TEXT("O processou desmapeou a biblioteca explicitamente\n"));
			//MessageBox(NULL, TEXT("O processou desmapeou a biblioteca implicitamente"), TEXT("DLLmain"), MB_OK);
		break;
	}
	return 1;
}