/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

// GENERAL FUNCTION
// RECIBE VALORES, M?NIMO, Y M?XIMO Y COMPARA CON EL DADO PARA CONCATENAR
extern "C" __declspec(dllexport)
char *values(double L, char *str, double inf, double sup, char *cad){
	
	if (L<inf){
		L=inf;
	}
	else if (L>sup){
		L=sup;
	}
	
	char w[18]; 
	strcat(str,cad); 
	sprintf(w, ", %4.1f,", L);
	strcat(str, w);
	
	return str;	
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}



