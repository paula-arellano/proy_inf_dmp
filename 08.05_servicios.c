//Habria que comprobar si el usuario y contraseña que mete esta bien y si no hay un usuario creado, que se dirija a administracion a crearlo
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
void crear_paciente();
void crear_profesional();
void pacientes_registrados();
void profesionales_registrados();
void sobreescribir_historial_clinico(char usuario[15], char especialidad[25]);
void consultar_historial_clinico(char usuario[15]);
char pedir_enviar_aviso(char receptor[20], char nombre_fichero[50]);
void enviar_aviso_administracion(char receptor[20], char aviso[300]);
void mostrar_aviso(char servicio[20], char nombre_fichero[25]);
void mostrar_aviso_administracion();



void main() {

	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int opcion;
	int dolor;
	char sino;
	char receptor[20];
	char nombre_fichero[50];
	char motivo[300];

	AltEnter();

	logo();

	Sleep(3000);

	system("PAUSE");

	system("cls");

	system("color 0F");	inicio:

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

	printf(" \tEscoja una de las siguientes opciones para identificarse: \n");	printf(" \n\n");
	printf(" \t  1. Paciente\n\t  2. Equipo medico\n\t  3. Personal de servicios\n \t  4. Administracion\n \t  5. Informar de un problema/aviso.\n\t  6. Salir\n\n");
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

			printf("\n  Responda el siguiente cuestionario con un numero del 1-10 o S(sí) - N(no)\n\n");
			printf("\n  Clasifique su nivel de su dolor 1-10:   ");
			scanf_s("%d", &dolor);

			if (dolor >= 6 && dolor <= 10) {

				printf(" \n  Sufre problemas respiratorios o cardiacos? S-N:  ");
				//fflush(stdin);  -> SI YA ESTA getchar() ESTO YA NO ES NECESARIO NO?
				getchar();
				scanf_s("%c", &sino);
	
				if (sino == 'S') {
					dolor = dolor + 4;
				}

				printf(" \n\n  Indique si alguna vez ya ha sufrido los mismos sintomas S-N:  ");
				//fflush(stdin); -> SI YA ESTA getchar() ESTO YA NO ES NECESARIO NO?
				getchar();
				scanf_s("%c", &sino);
			
				if (sino == 'S') {
					dolor = dolor + 4;
				}
			}

			else if (dolor < 6 && dolor >= 0) {

				printf(" \n\n  Sufre dolor de cabeza S-N:  ");
				//fflush(stdin) -> SI YA ESTA getchar() ESTO YA NO ES NECESARIO NO?
				getchar();
				scanf_s("%c", &sino);

					if (sino == 'S') { 
						dolor = dolor + 1; 
					}

				printf(" \n\n  Sufre vomitos S-N:  ");
				//fflush(stdin) -> SI YA ESTA getchar() ESTO YA NO ES NECESARIO NO?
				getchar();
				scanf_s("%c", &sino);

					if (sino == 'S') {
						dolor = dolor + 1; 
					}



					printf(" \n\n  Indique si sufre algun otro dolor fisico S-N:  ");
				//fflush(stdin) -> SI YA ESTA getchar() ESTO YA NO ES NECESARIO NO?
				getchar();
				scanf_s("%c", &sino);

					if (sino == 'S') { 
						dolor = dolor + 3;
					}
			}

			else { printf("\n\n  Introduzca un numero del 1 al 10\n\n"); system("EXIT"); }


			printf("  Su baremacion de dolor es:  %d\n\n", dolor);

			if (dolor == 18) { 
				printf("Sera atendido inmediatamente\n\n"); 
			}
			if (dolor <= 17 && dolor >= 15) { 
				printf("Sera atendido en menos de 15 min\n\n");
			}
			if (dolor <= 14 && dolor >= 10) { 
				printf("Sera atendido en menos de 60 min\n\n");
			}
			if (dolor <= 9 && dolor >= 7) { 
				printf("Sera atendido en menos de 120 min\n\n"); 
			}
			if (dolor <= 6 && dolor >= 4) { 
				printf("Sera atendido en menos de 240 min\n\n"); 
			}
			if (dolor <= 3 && dolor >= 0) { 
				printf("Su estado no es urgente, pida cita con el medico\n\n"); 
			}

			printf("Reiniciando\n\n");

			Sleep(4000);

			system("cls");

			goto inicio;

			break;

		default:printf("  OPCION NO VALIDA\n\n");
		}

		break;


	case 2: printf(" \tEscoja una de las siguientes especialidades:\n\n");

		printf("   1. Medico de familia\n   2. Alergologia\n   3. Cardiologia\n   4. Cirugia\n   5. Dermatologia\n   6. Endocrinologia\n   7. Geriatria\n   8. Ginecologia\n   9. Oftalmologia\n   10. Oncologia\n   11.Pediatria\n   12. Psiquiatria\n   13. Rehabilitacion\n   14. Traumatologia\n   15. Informar de un problema\n");
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

		case 9: printf("  Se ha identificado como ESPECIALISTA EN OFTALMOLOGIA, ingrese:\n");

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

				receptor[30] = "Limpieza";
				nombre_fichero[50] = "avisoslavanderia.txt";
				mostrar_aviso(receptor,nombre_fichero);

			printf("\tSus tareas son\n\n");

			switch (fecha()){
			case 'L':

				printf("\tLimpieza de la primera planta: habitaciones de 101-150 y zonas comunes\n\n");
				break;

			case 'M':

				printf("\tLimpieza de la primera planta: consultas y laboratorios\n\n");
				break;

			case 'X':

				printf("\tLimpieza de la segunda planta: habitaciones de 201-250 y zonas comunes\n\n");
				break;

			case 'J':

				printf("\tLimpieza de la segunda planta: consultas y laboratorios\n\n");
				break;

			case 'V':

				printf("\tLimpieza completa de la planta baja\n\n");
				break;

			case 'S':

				printf("\tLimpieza de la cocina y zonas comunes \n\n");
				break;
				
			case 'D':

				printf("\tEl personal de limpieza no trabaja los domingos\n\n");
				break;
			}

			break;

		case 2: printf("  Se ha identificado como PERSONAL DE LAVANDERIA, ingrese:\n"); 

			identificacion();

			/*time_t result = time(NULL); //imprime la hora
			char str[26];
			ctime_s(str, sizeof str, &result);*/
			printf("\tLa fecha de hoy es:   %s\n", str);

			receptor[30] = "Lavanderia";
			nombre_fichero[50] = "avisoslavanderia.txt";
			mostrar_aviso(receptor, nombre_fichero);

			printf("\tSus tareas son\n\n");

			switch (fecha()) {
			case 'L':

				printf("\tCambio sabanas y toallas habitaciones de 101-150 y consultas Planta 1\n\n");
				break;

			case 'M':

				printf("\tCambio sabanas y toallas habitaciones de 201-250 y consultas Planta 2\n\n");
				break;

			case 'X':

				printf("\tCambio sabanas y toallas habitaciones de 101-150 y consultas Planta 1\n\n");
				break;

			case 'J':

				printf("\tCambio sabanas y toallas habitaciones de 201-250 y consultas Planta 2\n\n");
				break;

			case 'V':

				printf("\tCambio sabanas y toallas habitaciones de 101-150 y consultas Planta 1\n\n");
				break;

			case 'S':

				printf("\tCambio sabanas y toallas habitaciones de 201-250 y consultas Planta 2\n\n");
				break;

			case 'D':

				printf("\tEl personal de lavanderia no trabaja los domingos\n\n");
				break;
			}

			break;

		case 3: printf("  Se ha identificado como PERSONAL DE COCINA, ingrese:\n"); //Falta hacer menu parecido al de limpieza

			identificacion();

			/*time_t result = time(NULL); //imprime la hora
			char str[26];
			ctime_s(str, sizeof str, &result);*/
			printf("\tLa fecha de hoy es:   %s\n", str);

			receptor[30] = "Cocina";
			nombre_fichero[50] = "avisoscocina.txt";
			mostrar_aviso(receptor, nombre_fichero);

			printf("\tMenu estandar:\n\n");

			switch (fecha()) {
			case 'L':

				printf("\tComida:\n\t\tPrimer plato: Pasta con salsa de tomate.\n\t\tSegundo plato:Merluza al horno.\n\t\tPostre: Gelatina o fruta de temporada.\n\n\tCena:\n\t\tPrimer plato: Ensalada con atun.\n\t\tSegundo plato: Tortilla francesa.\n\t\tPostre: Leche o fruta.\n\n");
				break;

			case 'M':

				printf("\tComida:\n\t\tPrimer plato: Consome.\n\t\tSegundo plato:Pechuga de pollo empanada.\n\t\tPostre: Natillas o fruta de temporada.\n\n\tCena:\n\t\tPrimer plato: Pure de patata.\n\t\tSegundo plato: Gallo enharinado.\n\t\tPostre: Yogurt o flan.\n\n");
				break;

			case 'X':

				printf("\tComida:\n\t\tPrimer plato: Pure de calabaza.\n\t\tSegundo plato: Muslo de pollo asado.\n\t\tPostre: Arroz con leche o fruta de temporada.\n\n\tCena:\n\t\tPrimer plato: Menestra de verdura.\n\t\tSegundo plato: Pescado cocido.\n\t\tPostre: Gelatina o yogurt.\n\n");
				break;

			case 'J':

				printf("\tComida:\n\t\tPrimer plato: Arroz con verdura.\n\t\tSegundo plato: Ternera con patatas cocidas.\n\t\tPostre: Flan o fruta de temporada.\n\n\tCena:\n\t\tPrimer plato: Empanadillas con ensalada\n\t\tSegundo plato: Bacalao al horno.\n\t\tPostre: Yogurt o fruta.\n\n");
				break;

			case 'V':

				printf("\tComida:\n\t\tPrimer plato: Verdura rehogada con patatas.\n\t\tSegundo plato: Merluza empanada.\n\t\tPostre: Natillas o fruta de temporada.\n\n\tCena:\n\t\tPrimer plato: Sopa de estrellas.\n\t\tSegundo plato: Pollo a la plancha.\n\t\tPostre: Yogurt o flan.\n\n");
				break;

			case 'S':

				printf("\tComida:\n\t\tPrimer plato: Pisto.\n\t\tSegundo plato: Huevos cocidos con bechamel.\n\t\tPostre: Flan o fruta de temporada.\n\n\tCena:\n\t\tPrimer plato: Ensalada mixta.\n\t\tSegundo plato: Gallo empanado.\n\t\tPostre: Yogurt o leche con cacao.\n\n");
				break;

			case 'D':

				printf("\tComida:\n\t\tPrimer plato: Paella.\n\t\tSegundo plato: Bacalao cocido.\n\t\tPostre: Yogurt o fruta de temporada.\n\n\tCena:\n\t\tPrimer plato: Ensalada.\n\t\tSegundo plato: Tortilla de patata.\n\t\tPostre: Flan o fruta de temporada.\n\n");
				break;
			}
			break;

		case 4: printf("  Se ha identificado como PERSONAL DE MANTENIMIENTO, ingrese:\n");

			identificacion();

			/*time_t result = time(NULL); //imprime la hora
			char str[26];
			ctime_s(str, sizeof str, &result);
			printf("\tLa fecha de hoy es:   %s\n", str);*/

			receptor[30] = "Mantenimiento";
			nombre_fichero[50] = "avisosmantenimiento.txt";
			mostrar_aviso(receptor, nombre_fichero);

			break;

		default:printf("  OPCION NO VALIDA\n\n");
		}

		break;


	case 4: printf("  Se ha identificado como PERSONAL DE ADMINISTRACION, ingrese:\n\n");

		identificacion();

		printf("\n   1. Ver ultimos movimientos de profesionales\n   2. Ver ultimos movimientos de pacientes\n   3. Registrar profesional\n   4. Registrar paciente\n   5. Consultar profesionales registrados\n   6. Consultar historial de pacientes registrados\n 7. Avisos \n\n");
		scanf_s("%d", &opcion);
		getchar();

		switch (opcion) {

		case 1: printf("  Cargando el historial de profesionales\n");
			verregistrosusuarios();
			break;

		case 2: printf("  Cargando los registros de pacientes\n");
			verregistrospacientes();
			break;
			
		case 3: 
			crear_profesional();
			break;

		case 4:
			crear_paciente();
			break;
		case 5:
			profesionales_registrados();
			break;

		case 6:
			pacientes_registrados();
			break;

		case 7:
			mostrar_aviso_administracion();
			break;

		default:printf("  OPCION NO VALIDA\n\n");

		}
		break;

	case 5: printf("Indique a quien debera ir dirigido el aviso:\n   1. Limpieza\n   2. Lavanderia\n   3. Cocina\n   4. Mantenimiento\n\n");
		scanf_s("%d", &opcion);

		switch (opcion) {
		case 1: 
			receptor[9] = "Limpieza";
			nombre_fichero[19] = "avisoslimpieza.txt";

			break;
		case 2:
			receptor[11] = "Lavanderia";
			nombre_fichero[21] = "avisoslavanderia.txt";

			break;
		case 3:
			receptor[6] = "Cocina";
			nombre_fichero[16] = "avisoscocina.txt";
		case 4:
			receptor[13] = "Mantenimiento";
			nombre_fichero[23] = "avisosmantenimiento.txt";
		}

		motivo[300] = pedir_enviar_aviso(receptor, nombre_fichero);

		enviar_aviso_administracion(receptor, motivo);


	case 6: printf("  Saliendo\n");

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



void identificacion() {

	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int salir = 0;
	int numusers = 0;
	int i = 0;
	char usuariofichero[20], contrasenafichero[20];
	char *usuario[15];
	FILE *usuarios;

	errno_t error;
	error = fopen_s(&usuarios, "usuarios.txt", "r");//abre el fichero

	if (error == 0) {
		printf("Fichero abierto correctamente\n");
	}

	else {//mira si hay errores

		printf("Ha habido un error %d \n", error);

		Sleep(2000);

		system("EXIT");
	}

	while (salir == 0) { // pide usuario hasta que sale uno correcto

		fopen_s(&usuarios, "usuarios.txt", "r");//abre el fichero cada vez
		printf("     Usuario: ");
		scanf_s("%s", &id.usuario, 15); //el getchar no funciona aqui
		getchar();
		printf("\n     Contrasena: ");
		gets(id.contrasena);
		
		for (i = 0; !feof(usuarios); i++) {// hasta final de archivo

			fscanf_s(usuarios, "%s", usuariofichero, 20);
			fscanf_s(usuarios, "%s", contrasenafichero, 20);

			if (strcmp(id.usuario, usuariofichero) == 0 && strcmp(id.contrasena, contrasenafichero) == 0) {

				printf("\nUsuario correcto\n\n");

				printf("\n\tBuenos dias %s \n\n", id.usuario);

				registrarusuario(id.usuario);

				fclose(usuarios);

				salir = 1;

				break;
			}
		}

		if (salir == 0){

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

	printf("\n\nIntroduzca su DNI sin la letra\n");
	
	printf("\n\t  DNI: ");
	getchar();
	scanf_s("%d", &dni);

	letradni = dni % 23;

	printf("\tSu DNI es: %d - %c\n\n", dni, letra[letradni]);


	fopen_s(&pacientes, "registrospacientes.txt", "a");

		time_t result = time(NULL); //imprime la hora
		char str[26];
		ctime_s(str, sizeof str, &result);

	fprintf(pacientes, "\nEl paciente %d-%c ha entrado en el hospital   %s\n", dni, letra[letradni], str);

	fclose(pacientes);
}


void registrarusuario(char usuario[100]) {//graba en el fichero los registros de los usuarios

	FILE *usuarios;
	int i;

	fopen_s(&usuarios, "registrosusuarios.txt", "a");

		time_t result = time(NULL); //imprime la hora
		char str[26];
		ctime_s(str, sizeof str, &result);

	fprintf(usuarios, "\nEl profesional %s ha entrado en el hospital   %s\n", usuario, str);

	fclose(usuarios);
}

void verregistrospacientes() {//imprime los registros de los pacientes

	FILE *pacientes;
	int i;
	char imprimir[200];

	fopen_s(&pacientes, "registrospacientes.txt", "r");

	//Aqui no hay que comprobar que se abre correctamente??

	for (i = 0; !feof(pacientes); i++) {

		fgets(imprimir, 200, pacientes);
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

	//Aqui no hay que comprobar que se abre correctamente??

	while (!feof(usuarios)) {

		fgets(imprimir, 200, usuarios);
		printf("%s", imprimir);
	}
		printf("\n");

	fclose(usuarios);
}

void crear_paciente() {
	FILE *crear_paciente;
	char nombre[30];
	char apellido[50];
	char usuario[15];
	char contrasena[15];
	char dni[10];

	printf("Usuario: ");
		gets(usuario);
	printf("Contrasena: ");
		gets(contrasena);
	printf("Nombre: ");
		gets(nombre);
	printf("Apellido: ");
		gets(apellido);
	printf("DNI: ");
		gets(dni);

	fopen_s(&crear_paciente,"totalpacientesregistrados.txt", "a"); //Si nolo que podemos hacer es un fichero que contenga todos los historiales de todos los pacientes y busque en el fichero el nombre del paciente y el medico escriba debajo

	fprintf(crear_paciente, "%s\n%s\n%s\n%s\n%s\n\n", usuario, contrasena, nombre, apellido, dni); //A la hora de ller el fichero, podemos poner un contador que diga el numero de veces que se ha escrito en el historial y asi saber cuantas lineas hay que pasar paraque el medico vuleva a escribir
	
	fclose(crear_paciente);
}


void crear_profesional(){
	FILE *crear_profesional;
	char nombre[30];
	char apellido[50];
	char usuario[15];
	char contrasena[15];
	char especialidad[25];

	printf("Usuario: ");
	gets(usuario);
	printf("Contrasena: ");
	gets(contrasena);
	printf("Nombre: ");
	gets(nombre);
	printf("Apellido: ");
	gets(apellido);
	printf("Especialidad/Servicio: ");
	gets(especialidad);

	fopen_s(&crear_profesional, "plantillaprofesionales.txt", "a"); //Si nolo que podemos hacer es un fichero que contenga todos los historiales de todos los pacientes y busque en el fichero el nombre del paciente y el medico escriba debajo

	fprintf(crear_profesional, "%s\n%s\n%s\n%s\n%s\n\n", usuario, contrasena, nombre, apellido, especialidad); //A la hora de ller el fichero, podemos poner un contador que diga el numero de veces que se ha escrito en el historial y asi saber cuantas lineas hay que pasar paraque el medico vuleva a escribir

	fclose(crear_profesional);
}

void pacientes_registrados() {
	FILE *pacientes;
	char imprimir[200];

	fopen_s(&pacientes, "totalpacientesregistrados.txt", "r");

	//Aqui no hay que comprobar que se abre correctamente??

	while (!feof(pacientes)) {

		fgets(imprimir, 200, pacientes);
		printf("%s", imprimir);
	}
	printf("\n");

	fclose(pacientes);
}

void profesionales_registrados() {
	FILE *profesionales;
	char imprimir[200];

	fopen_s(&profesionales, "plantillaprofesionales.txt", "r");

	//Aqui no hay que comprobar que se abre correctamente??

	while (!feof(profesionales)) {

		fgets(imprimir, 200, profesionales);
		printf("%s", imprimir);
	}
	printf("\n");

	fclose(profesionales);
}

void sobreescribir_historial_clinico(char usuario[15], char especialidad[25]) { //Esta funcion quiero que vaya leyendo el fichero hasta que encuentre el usuario, entones saltara 5 lineas+ el contador y seguira escribiendo en una linea mas el nuevo diagnostico y ademas aumentara uno el contador
	FILE *pacientes;
	int i;
	char consulta[300];

	fopen_s(&pacientes, "totalpacientesregistrados.txt", "a");

	printf("Diagnostico del paciente %s:\n", usuario);
	gets(consulta);

	while (!feof(pacientes)) {

		fprintf("\t %s: %s ", especialidad, consulta); //Tambien estaria bien escribir la hora
	}
	printf("\n");

	fclose(pacientes);

}

/*void consultar_historial_clinico(char usuario[15]) {
	FILE *pacientes;
	int i;

	pacientes = fopen_s(&pacientes, "totalpacientesregistrados.txt", "a");

	while (!feof(pacientes)) {// esto no iria en este bucle, habria que tirar las lineas anteriores hasta llegar al usuario a la basura e imprimir dentro de un bucle hasta el contador

		fscanf("\t %s: %s ", especialidad, consulta); //Tambien estaria bien escribir la hora
	}
	printf("\n");

	fclose(pacientes);
}*/

char pedir_enviar_aviso(char receptor[20], char nombre_fichero[50]) {
	char motivo[300];
	FILE *avisos;

	printf("Indique brevemente el motivo de su aviso dirigido a %s\n", receptor);
	gets(motivo);

	fopen_s(&avisos, nombre_fichero , "a");

	fprintf(avisos, "%s", motivo);

	fclose(avisos);

	return motivo;
}


void enviar_aviso_administracion(char receptor[20], char aviso[300]) {
	FILE *avisos;
	fopen_s(&avisos, "avisosadministracion.txt", "a");
	fprintf(avisos, "%s: %s\n", receptor, aviso);

	fclose(avisos);
}

void mostrar_aviso(char servicio[20], char nombre_fichero[25]) { //Este borra el aviso una vez que ya ha salido, no imprime los avisos anteriores
	FILE *avisos;
	fopen_s(&avisos, nombre_fichero, "r");
	char imprimir[300];

	while (!feof(avisos)) {

		fgets(imprimir, 200, avisos);
		printf("%s", imprimir);
	}
	printf("\n");

	fclose(avisos);

	fopen_s(&avisos, nombre_fichero, "w");// Esto sirve para eliminar el aviso una vez visto
	fprintf(avisos, "\n");
	fclose(avisos);
}

void mostrar_aviso_administracion() { //Este no borra el aviso, es como si tuviera memoria
	FILE *avisos;
	fopen_s(&avisos, "avisosadministracion.txt", "r");
	char imprimir[300];
	
	while (!feof(avisos)) {

		fgets(imprimir, 300, avisos);
		printf("%s", imprimir);
	}
	printf("\n");

	fclose(avisos);
}
