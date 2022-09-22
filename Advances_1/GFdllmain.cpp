/* Replace "dll.h" 9with the name of your header */
#include "GFdll.h"
#include <windows.h>
#include <stdio.h>
#include <string>

// GENERAL FUNCTION
// RECIBE VALORES, MÍNIMO, Y MÁXIMO Y COMPARA CON EL DADO PARA CONCATENAR

extern "C" DLLIMPORT
char *values(double L, char *str, double inf, double sup, char *cad){
	
	if (L<inf){
		L=inf;
	}
	else if (L>sup){
		L=sup;
	}
	char w[18];
	strcat(str,cad);
	strcat(str," ");
	sprintf(w,"%4.1f",L);
	strcat(str,w);
	strcat(str,",");
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
