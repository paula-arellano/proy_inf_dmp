#include <stdio.h>
#include <time.h>

void main() {
	char date;
	date = fecha();


	printf("%c \n", date);

	system("pause");
}

int fecha() {
	time_t result = time(NULL);
	char time[26], dia;
	ctime_s(time, sizeof time, &result);
	time[4] = '\0';
	if (time[0] == 'M') dia = 'L';							//Lunes			L
	else if (time[0] == 'T' && time[1 == 'u']) dia = 'M';	//Martes		M
	else if (time[0] == 'W') dia = 'X';						//Miercoles		X
	else if (time[0] == 'T' && time[1 == 'h']) dia = 'J';	//Jueves		J
	else if (time[0] == 'F') dia = 'V';						//Viernes		V
	else if (time[0] == 'S' && time[1 == 'a']) dia = 'S';	//Sabado		S
	else if (time[0] == 'S' && time[1 == 'u']) dia = 'D';	//Domingo		D
	return(dia);
}