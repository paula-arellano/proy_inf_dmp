#include<stdio.h>
#include <time.h>
#include <windows.h>

struct perfil {
	char usuario[15];
	char contrasena[15];
};

void identificacion();
void logo();
void AltEnter();// pone en pantalla completa
char fecha();

void registrarpaciente();
void verregistrospacientes();
void registrarusuario(char usuario[100]);
void verregistrosusuarios();

void main() {
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int opcion;
	int dolor;
	char sino;
	
	

	AltEnter();

	logo();
	Sleep(3000);

	system("PAUSE");
	system("cls");
	system("color 0F");
	inicio:
	printf(" \n\n");
	printf(" \n\n");
	time_t result = time(NULL); //imprime la hora
	char str[26];
	ctime_s(str, sizeof str, &result);
	printf("%s\n", str);
	printf(" \n\n");
	printf(" \n\n");
	printf("Pulsa Alt+Enter o F11 en cualquier momento para salir de la pantalla completa");
	printf(" \n\n");
	printf(" \n\n");
	printf(" \tEscoja una de las siguientes opciones para identificarse: \n");
	printf(" \n\n");
	printf(" \t  1. Paciente\n\t  2. Equipo medico\n\t  3. Personal de servicios\n \t  4. Administracion\n \t  5. Salir\n\n");
	scanf_s("%d", &opcion);

	switch (opcion) {
	case 1:printf("  Se ha identificado como PACIENTE\n");
		registrarpaciente();

		printf("Escoja una de las siguientes especialidades:\n");
		printf("   1. Medico de familia\n   2. Alergología\n   3. Cardiología\n   4. Cirugia\n   5. Dermatologia\n   6. Endocrinologia\n   7. Geriatria\n   8. Ginecologia\n   9. Oftalmologia\n   10. Oncologia\n   11.Pediatria\n   12. Psiquiatria\n   13. Rehabilitacion\n   14. Traumatologia\n   15. Urgencias\n ");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		

		case 15: printf("  Bienvenido al servicio de urgencias\n");

		printf("\n  Le vamos a hacer un cuestionario para ver su estado, conteste con un numero del 1-10 o preguntas con S(sí) o N(no)\n\n");

		

		printf("\n  Clasifique el estado de su dolor 1-10:   ");

		scanf_s("%d", &dolor);

		if (dolor >= 6&& dolor<=10) {

			printf(" \n  Cree que sufre problemas respiratorios o cardiacos S-N:  ");
			fflush(stdin);

			getchar();
			scanf_s("%c", &sino);
			
			if (sino == 'S') { dolor = dolor + 4; }
			
			printf(" \n\n  Cree que corre un riesgo vital S-N:  ");

			fflush(stdin);
			getchar();
			scanf_s("%c", &sino);
		
			if (sino == 'S') { dolor = dolor + 4; }
		}

		else if (dolor < 6&& dolor>=0) {

			printf(" \n\n  Le duele la cabeza S-N:  ");
			fflush(stdin);
			getchar();
			scanf_s("%c", &sino);

			if (sino == 'S') { dolor = dolor + 1; }

			printf(" \n\n  Sufre vomitos S-N:  ");
			fflush(stdin);
			getchar();
			scanf_s("%c", &sino);
			if (sino == 'S') { dolor = dolor + 1; }

			printf(" \n\n  Tiene algun dolor fisico S-N:  ");
			fflush(stdin);
			getchar();
			scanf_s("%c", &sino);
			if (sino == 'S') { dolor = dolor + 3; }
		}

		else { printf("\n\n  Ese numero no esta permitido en la escala\n\n"); system("EXIT"); }
		
		printf("  Su clasificacion de dolor es:  %d\n\n", dolor);
		if(dolor==18){ printf("Sera atendido inmediatamente\n\n"); }
		if (dolor<=17&& dolor>=15) { printf("Sera atendido en menos de 15 min\n\n"); }
		if (dolor <= 14 && dolor >= 10) { printf("Sera atendido en menos de 60 min\n\n"); }
		if (dolor <= 9 && dolor >= 7) { printf("Sera atendido en menos de 120 min\n\n"); }
		if (dolor <= 6 && dolor >= 4) { printf("Sera atendido en menos de 240 min\n\n"); }
		if (dolor <= 3 && dolor >= 0) { printf("Su estado, no es urgente, pida cita con el medico\n\n"); }

		printf("Volviendo al inicio\n\n");
		Sleep(4000);
		system("cls");
		goto inicio;
		break;


		default:printf("  OPCION NO VALIDA\n\n");
		}
	break;

	case 2: printf(" \tEscoja una de las siguientes especialidades:\n\n");
		printf("   1. Medico de familia\n   2. Alergología\n   3. Cardiología\n   4. Cirugia\n   5. Dermatologia\n   6. Endocrinologia\n   7. Geriatria\n   8. Ginecologia\n   9. Oftalmologia\n   10. Oncologia\n   11.Pediatria\n   12. Psiquiatria\n   13. Rehabilitacion\n   14. Traumatologia\n   15. Informar de un problema\n");

		scanf_s("%d", &opcion);
		getchar();

		switch (opcion) {
		case 1: printf("  Se ha identificado como MEDICO DE FAMILIA, ingrese:\n");
			identificacion();
			break;

		case 2: printf("  Se ha identificado como ESPECIALISTA EN ALERGOLOGIA, ingrese:\n");
			identificacion();
			break;

		case 3: printf("  Se ha identificado como ESPECIALISTA EN CARDIOLOGIA, ingrese:\n");
			identificacion();
			break;

		case 4: printf("  Se ha identificado como ESPECIALISTA EN CIRUGIA, ingrese:\n");
			identificacion();
			break;
		case 5: printf("  Se ha identificado como ESPECIALISTA EN DERMATOLOGÍA, ingrese:\n");
			identificacion();
			break;
		case 6: printf("  Se ha identificado como ESPECIALISTA EN ENDOCRINOLOGIA, ingrese:\n");
			identificacion();
			break;

		case 7: printf("  Se ha identificado como ESPECIALISTA EN GERIATRIA, ingrese:\n");
			identificacion();
			break;

		case 8: printf("  Se ha identificado como ESPECIALISTA EN GINECOLOGIA, ingrese:\n");
			identificacion();
			break;

		case 9: printf("  Se ha identificado como ESPECIALISTA EN OFTAALMOLOGIA, ingrese:\n");
			identificacion();
			break;

		case 10: printf("  Se ha identificado como ESPECIALISTA EN ONCOLOGIA, ingrese:\n");
			identificacion();
			break;

		case 11: printf("  Se ha identificado como ESPECIALISTA EN PEDIATRIA, ingrese:\n");
			identificacion();
			break;

		case 12: printf("  Se ha identificado como ESPECIALISTA EN PSIQUIATRIA, ingrese:\n");
			identificacion();
			break;

		case 13: printf("  Se ha identificado como ESPECIALISTA EN REHABILITACION, ingrese:\n");
			identificacion();
			break;

		case 14: printf("  Se ha identificado como ESPECIALISTA EN TRAUMATOLOGIA, ingrese:\n");
			identificacion();
			break;
		
		default:printf("  OPCION NO VALIDA\n\n");
			
		}
		
	break;
		
	case 3: printf("  Escoja uno de los siguientes campos:\n\n");
		printf("   1. Limpieza\n   2. Lavanderia\n   3. Cocina\n   4. Mantenimiento\n\n");
		scanf_s("%d", &opcion);
		getchar();

		switch (opcion) {
		case 1: printf("  Se ha identificado como PERSONAL DE LIMPIEZA, ingrese:\n\n");
			
			identificacion();



			time_t result = time(NULL); //imprime la hora
			char str[26];
			ctime_s(str, sizeof str, &result);
			printf("\tLa fecha de hoy es:   %s\n", str);

			printf("\tSus tareas son\n\n");

			switch (fecha())
			{
			case 'L':

				printf("\tLas tareas de hoy son limpiar las habitaciones de la primera planta, habitaciones de 101-150\n\n");

				break;

			case 'M':

				printf("\tLas tareas de hoy son limpiar las habitaciones de la segunda planta, habitaciones de 201-250\n\n");

				break;

			case 'X':

				printf("\tLas tareas de hoy son limpiar las habitaciones de la tercera planta, habitaciones de 301-350\n\n");

				break;

			case 'J':

				printf("\tLas tareas de hoy son limpiar las habitaciones de la cuarta planta, habitaciones de 401-550\n\n");

				break;

			case 'V':

				printf("\tLas tareas de hoy son limpiar la planta baja y la recepcion\n\n");

				break;

			case 'S':

				printf("\tLas tareas de hoy son limpiar la cocina y los pasillos generales\n\n");

				break;

			case 'D':

				printf("\tEl personal de limpieza no trabaja los domingos\n\n");

				break;

			}

			break;

		case 2: printf("  Se ha identificado como PERSONAL DE LAVANDERIA, ingrese:\n");
			identificacion();
			break;

		case 3: printf("  Se ha identificado como PERSONAL DE COCINA, ingrese:\n");
			identificacion();
			break;

		case 4: printf("  Se ha identificado como PERSONAL DE MANTENIMIENTO, ingrese:\n");
			identificacion();
			break;
		default:printf("  OPCION NO VALIDA\n\n");
		
		}
		
	break;
		


	case 4: printf("  Se ha identificado como PERSONAL DE ADMINISTRACION, ingrese:\n\n");
		identificacion();

		printf("\n   1. Ver historial de fichages\n   2. Ver registros de pacientes\n\n");

		scanf_s("%d", &opcion);
		getchar();

		switch (opcion) {
		case 1: printf("  Cargando el historial de fichages\n");
			
			verregistrosusuarios();

			break;

		case 2: printf("  Cargando los registros de pacientes\n");
			
			verregistrospacientes();

			break;

		default:printf("  OPCION NO VALIDA\n\n");
		

		
		}

	
	break;

	case 5: printf("  Saliendo\n");

		Sleep(1000);

		return 0;
	break;

	default:printf("  OPCION NO VALIDA\n\n");
	}

	system("PAUSE");

	printf("\n\nVolviendo al inicio\n\n");
	Sleep(2000);
	system("cls");
	goto inicio;

}

void identificacion( ) {

	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int salir=0;
	int numusers = 0;
	int i=0;
	char usuariofichero[20], contrasenafichero[20];
	char *usuario[15];
	FILE *usuarios;
	
	

	errno_t error;

	error = fopen_s(&usuarios, "usuarios.txt", "r");//abre el fichero



	if (error == 0) {
		printf("Fichero abrierto correctamente\n");


	}

	else {//mira si hay errores
		printf("Ha habido un error %d \n", error);
		Sleep(2000);
		system("EXIT");
		
	}


	while (salir==0) { // pide usuario hasta que sale uno correcto
		
		fopen_s(&usuarios, "usuarios.txt", "r");//abre el fichero cada vez

	printf("     Usuario: ");
	scanf_s("%s",&id.usuario,15); //el getchar no funciona aqui
	printf("\n     Contrasena: ");
	getchar();
	gets(id.contrasena);

	for (i = 0; !feof(usuarios); i++) {// hasta final de archivo

		fscanf_s(usuarios, "%s", usuariofichero,15);
		fscanf_s(usuarios, "%s", contrasenafichero, 15);

		

		if (strcmp(id.usuario, usuariofichero) == 0 && strcmp(id.contrasena, contrasenafichero) == 0) {
			printf("\nUsuario correcto\n\n");

			printf("\n\tBuenos dias %s \n\n",id.usuario);

			registrarusuario(id.usuario);

			fclose(usuarios);




			salir = 1;
			break;
			
			
		}
	}

	if (salir == 0)
	{
		printf("\n\tUsuario incorrecto\n\n");

		printf("\n\tVuelva a introducir usuario y contrasena\n\n");

	}

		
	}
	
	return 0;

}


void logo() {//logotipo



	system("color 0A");

	printf("\n");
	printf("\n");
	printf(" 8888888888b d88888888888b d888    d88b d88888888888b  888888888888b      _d88888888b__   \n");
	printf("88888888888P 888888888888P 88888  _8888 Y88888888888P  8888888888888b    d8888888888888b\n");
	printf("8888         8888_______   888888  8888      8888      888 ____d88888    88888P    88888\n");
	printf("8888         88888888888b  888888888888      8888      8888888888888P    8888       Y888\n");
	printf("8888         88888888888P  8888bY888888      8888      888888888888      8888        888\n");
	printf("8888b______  8888          Y8888  88888      8888      8888  Y88888b     8888b_  ___d888\n");
	printf("Y8888888888b Y88888888888   8888   8888      8888      8888    Y8888b     88888bd8888888\n");
	printf("Y888888888P   Y888888888P   Y88P   Y88P      Y88P      Y88P     Y888P      8888888888\n");

	printf("\n");

	printf("_____      ___________\n");
	printf("d88888b_    d88888888888b\n");
	printf("88888888b   Y888888888888\n");
	printf("888888888b  8888____\n");
	printf("8888 Y8888  888888888b\n");
	printf("8888  8888  888888888P\n");
	printf("8888 d8888  8888    \n");
	printf("8888d8888P  8888___\n");
	printf("88888888P   88888888888\n");
	printf("Y888888P    Y888888888P\n");
	printf("\n");
	printf("\n");
	printf("   _______        _____       __          __        __     ______\n");
	printf(" _d8888888b     _d88888      d88b        d88b      d88b   d888888b_\n");
	printf("d888888888P    d88888888     8888        8888      8888   888888888b_\n");
	printf("88888_         8888P 8888    8888        8888      8888   8888  88888b\n");
	printf("888888b        8888__8888    8888        8888      8888   8888   88888b\n");
	printf("Y8888888888b  d8888888888b   8888        8888     d8888   8888    Y8888\n");
	printf("     8PY8888b 888888888888   8888        8888b    8888P   8888     8888\n");
	printf(" _______ 8888 88888    888b  8888_______ Y8888_  d8888    8888__  d8888\n");
	printf("d888888888888 88888    8888  88888888888b 88888bd8888P    888888bd8888\n");
	printf("Y88888888888P Y888P    Y88P  88888888888P Y888888888       8888888888\n");
	printf("\n");
	printf("\n");


	

	return 0;
}

void AltEnter()//abir pantalla completa
{
	keybd_event(VK_MENU,
		0x38,
		0,
		0);
	keybd_event(VK_RETURN,
		0x1c,
		0,
		0);
	keybd_event(VK_RETURN,
		0x1c,
		KEYEVENTF_KEYUP,
		0);
	keybd_event(VK_MENU,
		0x38,
		KEYEVENTF_KEYUP,
		0);
	return 0;
}


char fecha() {
	time_t result = time(NULL);
	char time[26], dia;
	ctime_s(time, sizeof time, &result);
	time[4] = '\0';
	if (time[0] == 'M') dia = 'L';							//Lunes			L
	else if (time[0] == 'T' && time[1] == 'u') dia = 'M';	//Martes		M
	else if (time[0] == 'W') dia = 'X';						//Miercoles		X
	else if (time[0] == 'T' && time[1] == 'h') dia = 'J';	//Jueves		J
	else if (time[0] == 'F') dia = 'V';						//Viernes		V
	else if (time[0] == 'S' && time[1] == 'a') dia = 'S';	//Sabado		S
	else if (time[0] == 'S' && time[1] == 'u') dia = 'D';	//Domingo		D
	return(dia);
}

void registrarpaciente() {//graba en el fichero los registros de los pacientes

	FILE *pacientes;
	int dni;

	char letra[23] = "TRWAGMYFPDXBNJZSQVHLCKE";

	int letradni;

	int i;

	char basura[40];

	printf("\n\nIntroduzca su DNI sin la letra\n");


	printf("\n\t  DNI: ");
	getchar();
	scanf_s("%d",&dni);



	letradni = dni % 23;

	printf("\tSu DNI es: %d - %c\n\n", dni, letra[letradni]);

	fopen_s(&pacientes, "registrospacientes.txt", "r+");

	time_t result = time(NULL); //imprime la hora
	char str[26];
	ctime_s(str, sizeof str, &result);

	for (i = 0; !feof(pacientes); i++) {

		fscanf_s(pacientes, "%s", basura, 40);

		
	}

	fprintf(pacientes, "\nEl paciente %d-%c ha entrado en el hospital   %s\n", dni, letra[letradni], str);

	fclose(pacientes);

}


void registrarusuario(char usuario[100]) {//graba en el fichero los registros de los usuarios

	FILE *usuarios;
	int i;
	char basura[40];
	

	fopen_s(&usuarios, "registrosusuarios.txt", "r+");

	time_t result = time(NULL); //imprime la hora
	char str[26];
	ctime_s(str, sizeof str, &result);

	for (i = 0; !feof(usuarios); i++) {// lee las lineas anteriores

		fscanf_s(usuarios, "%s", basura, 40);


	}

	fprintf(usuarios, "\nEl personal %s ha entrado en el hospital   %s\n", usuario, str);//imprime al final del fichero

	fclose(usuarios);

}

void verregistrospacientes() {//imprime los registros de los pacientes

	FILE *pacientes;
	int i;
	char imprimir[200];


	fopen_s(&pacientes, "registrospacientes.txt", "r");

	
	for (i = 0; !feof(pacientes); i++) {

		fgets(imprimir,200,pacientes);

		printf("%s", imprimir);
	}

	printf("\n");

	fclose(pacientes);

}


void verregistrosusuarios() {//imprime los registros de los usuarios

	FILE *usuarios;
	int i;
	char imprimir[200];


	fopen_s(&usuarios, "registrosusuarios.txt", "r");


	while(!feof(usuarios)) {
	
			fgets(imprimir, 200, usuarios);
			
			printf("%s", imprimir);
		
	}

	printf("\n");

	fclose(usuarios);

}




