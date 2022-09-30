#include <iostream>
#include <string>
#include <windows.h>
#include "ldll.h"
//#include <fstream>
//#include <sstream>
//#include <iomanip>

using namespace std;

// AUXILIAR FUNCTIONS
int request_channel(int);
char *main_menu(int, char*);
// FROM DLL LIBRARIES
char *values(double, char*, double, double, char*);
char *chain(char *, double, double, char *, char *, char *);

// NEW TYPE OF VARIABLE DEFINED
typedef char* (WINAPI*funct)(double, char*,double,double, char*);
funct function;


int main(int argc, char** argv) {

	int o = 1;
	while (o != 0){
		
		// DEFINITION OF VARIABLE FOR CHANNEL, WAVEFORM AND COMMAND
		int canal = 0, wave;
		char *str = new char [200];
			
		// REQUEST CHANNEL
		canal = request_channel(canal);		
		
		// IF CANAL = 7, FINISH PROGRAM
		if (canal == 7){o = 0; break;}
		
		// CHANNEL AND MAIN INSTRUCTION ADDED
		sprintf(str,"C%d",canal);
		strcat(str, ":BSWV WVTP, ");
		
		// REQUEST WAVEFORM AND MAIN MENU
		str = main_menu(wave, str);
		
		// PRINT FINAL COMMAND		
		cout << str << endl;	
				
	}
    system("PAUSE");
    
	cout << "\nFIN DEL PROGRAMA\n" << endl;

	return 0;
}

// MODEL: WaveStation
// SERIAL: LCRY3602C00213


// REQUEST CHANNEL

int request_channel(int canal){
	while (canal != 1 and canal != 2 and canal != 7){
	  	cout << "\nEscriba el Canal 1 o 2 \n"<<endl;
	  	cout << "7 - Fin del Programa \n" << endl;
		cin >> canal;
		system("CLS");
	}
	return canal;
}

// REQUEST WAVEFORM AND VALUE OF EVERY PARAMETER

char *main_menu(int wave, char *str){
	
		cout << "\nEscriba el numero para una Forma de Onda:\n" << endl;
		cout << "0 - - SINE \n1 - - SQUARE \n2 - - RAMP \n3 - - PULSE" << endl;
		cout << "4 - - NOISE \n5 - - DC \n6 - - ARBITRARY \n7 - - SALIR \n" << endl;
		cin >> wave;
		system("CLS");
		
		char Frecuencia[11] = "Frecuencia", Amplitud[9] = "Amplitud", Offset[7] = "Offset", Fase[5] = "Fase";
		char Duty[5] = "Duty", Rise[5] = "Rise", Delay[6] = "Delay", Symmetry[9] = "Symmetry";
		
		char FREQ[5] = "FREQ", AMP[4] = "AMP", OFST[5] = "OFST", PHSE[5] = "PHSE";
		char DUTY[5] = "DUTY", RISE[5] = "RISE", DLY[4] = "DLY", SYM[4] = "SYM"; 
		
		char Hz[3] = "Hz", V[2] = "V", Deg[4] = "Deg", Percent[3] = "%", mV[3] = "mV", s[2] = "s";
		
		char Mean[5] = "Mean", STD[30] = "Desviacion Estandar";
		char MEAN[5] = "MEAN", STDEV[6] = "STDEV";
		
		switch(wave){
	  		case 0:			// SINE
	  			strcat(str, "SINE, ");
	  			str = chain(str, 1E-6, 120E6, Frecuencia, FREQ, Hz);
	  			str = chain(str, 1E-3, 9.920, Amplitud, AMP, V);
	  			str = chain(str, -750, 750, Offset, OFST, V);
	  			str = chain(str, -360, 360, Fase, PHSE, Deg);
	    		break;
	  		case 1:			// SQUARE
	  			strcat(str, "SQUARE, ");
	  			str = chain(str, 1E-6, 50E6, Frecuencia, FREQ, Hz);
	  			str = chain(str, 1E-3, 120e-3, Amplitud, AMP, V);
	  			str = chain(str, -4.940, 4.940, Offset, OFST, V);
	  			str = chain(str, -360, 360, Fase, PHSE, Deg);
	  			str = chain(str, 20, 80, Duty, DUTY, Percent);
	    		break;
	    	case 2:			// RAMP
	  			strcat(str, "RAMP, ");
	    		str = chain(str, 1E-6, 40E6, Frecuencia, FREQ, Hz);
	  			str = chain(str, 1E-3, 120e-3, Amplitud, AMP, V);
	  			str = chain(str, -4.940, 4.940, Offset, OFST, V);
	  			str = chain(str, -360, 360, Fase, PHSE, Deg);
	  			str = chain(str, 0, 100, Symmetry, SYM, Percent);
	    		break;
	    	case 3:			// PULSE
	  			strcat(str, "PULSE, ");
	    		str = chain(str, 1E-6, 40E6, Frecuencia, FREQ, Hz);
	  			str = chain(str, 1E-3, 120e-3, Amplitud, AMP, V);
	  			str = chain(str, -4.925, 4.999, Offset, OFST, V);
	  			str = chain(str, 48, 52, Duty, DUTY, Percent);
				str = chain(str, 6E-9, 187.6E-9, Rise, RISE, s);
				str = chain(str, -25E-9, 25E-9, Delay, DLY, s);  	  			
	    		break;
	    	case 4:			// NOISE
	    		strcat(str, "NOISE, ");
	    		str = chain(str, 0.5, 800, STD, STDEV, mV);
	  			str = chain(str, -4.996, 4.996, Mean, MEAN, V);
	    		break;
	    	case 5: 		// DC
	    		strcat(str, "DC, ");
	    		str = chain(str, -5, 5, Offset, OFST, V);
	    		break;
	    	case 6:         // ARB
	    		strcat(str, "ARB, ");
	    		str = chain(str, 1E-6, 40E6, Frecuencia, FREQ, Hz);
	  			str = chain(str, 1E-3, 4, Amplitud, AMP, V);
	  			str = chain(str, -3, 3, Offset, OFST, V);
	  			str = chain(str, -360, 360, Fase, PHSE, Deg);
	    		break;
	    	case 7:       // ENDS THE PROGRAM
	    		break;
	  		default:
	    		cout << "Ingreso mal el dato" << endl;	    	
		}

	return str;	
}


// REQUEST OF VALUE

char *chain(char *str, double min, double max,char *name, char *command, char *units){
 	
	double value;
 	
	cout << "Escriba el valor de "<< name << " de rango " << min << " a " << max << " " << units << endl;
	cin >> value;
	system("CLS");
	
	str = values(value, str, min, max, command);
	
	return str;
}


// SET VALUE ACCORDING TO LIMITS

char *values(double L, char *str, double inf, double sup, char* cad){

    char *res;   
   	res = new char [100];

    HINSTANCE hLib;       
    hLib = LoadLibrary("LDLL.dll");
 
    if(hLib!=0)
     {
          function = (char* (__stdcall *) (double,char*,double, double, char*)) GetProcAddress(hLib,"values");
          res = function(L,str,inf,sup,cad);                                       
     }
    else  {
         cout << "No se ha podido cargar DLL";
         FreeLibrary(hLib);
     }   
     
    return res;           
}

