#include<stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include<stdlib.h>


struct paciente {
	char nombre[20];
	char apellido[50];
	int contrasena;
	int dni;
};

struct dia {
	int h1;
	int h2;
	int h3;
	int h4;
	int h5;
};

struct semana {
	struct dia l;
	struct dia m;
	struct dia x;
	struct dia j;
	struct dia v;
};

typedef struct {
	char especialidad[30];
	char nombre[20];
	char apellido[50];
	int dni;
	char contrasena[6];
	struct semana citas;
}medico;

struct perfil {
	char usuario[15];
	char contrasena[15];
};

void identificacion();
void logo();
void AltEnter();// pone en pantalla completa
char fecha();

int GetFontSize(HANDLE windowHandle, COORD *size);
int SetFontSize(HANDLE windowHandle, COORD size);
int registrarpaciente();
void verregistrospacientes();
void registrarusuario(char usuario[100]);
void verregistrosusuarios();
void crear_paciente(struct paciente* registro);
void pacientes_registrados();
void profesionales_registrados();
void consultar_historial_clinico(int dni);
void menu_medico(medico* p);

char* leertarjeta();
void identificacion_servicios();
int identificacion_medicos(medico* p);
void cita_paciente(int dni, char especialidad[30], medico* p);
void consulta_medico(int dni, medico* p); //puntero a medico

void aviso(char receptor[15], char nombre_fichero[50]);
void mostrar_aviso(char nombre_fichero[25]);
void mostrar_aviso_administracion();

void main() {
	struct paciente nuevo_registro;
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	medico equipo[14]; //Vector de estructuras con especialidad
	medico* p;
	int opcion;
	int dolor;
	char sino;
	char receptor[20];
	char* motivo;
	int dni, contrasena;
	int i;
	int identificacion;
	FILE *pf;

	//NOMBRES DE FICHEROS PARA ENVIAR A FUNCIONES DE AVISOS
	char nombreFicheroLimpieza[19] = "avisoslimpieza.txt";
	char nombreFicheroLavanderia[30] = "avisoslavanderia.txt";
	char nombreFicheroCocina[17] = "avisoscocina.txt";
	char nombreFicheroMantenimiento[24] = "avisosmantenimiento.txt";

	//INICIALIZACION DE LAS ESTRUCTURAS PARA TRABAJAR CON ELLAS
	fopen_s(&pf, "medicos.txt", "r");
	i = 0;
	while (!feof(pf)) {
		fscanf_s(pf, "%s %s %s %d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", equipo[i].especialidad, 30, equipo[i].nombre, 20, equipo[i].apellido, 50, &equipo[i].dni, equipo[i].contrasena, 6, &equipo[i].citas.l.h1, &equipo[i].citas.l.h2, &equipo[i].citas.l.h3, &equipo[i].citas.l.h4, &equipo[i].citas.l.h5, &equipo[i].citas.m.h1, &equipo[i].citas.m.h2, &equipo[i].citas.m.h3, &equipo[i].citas.m.h4, &equipo[i].citas.m.h5, &equipo[i].citas.x.h1, &equipo[i].citas.x.h2, &equipo[i].citas.x.h3, &equipo[i].citas.x.h4, &equipo[i].citas.x.h5, &equipo[i].citas.j.h1, &equipo[i].citas.j.h2, &equipo[i].citas.j.h3, &equipo[i].citas.j.h4, &equipo[i].citas.j.h5, &equipo[i].citas.v.h1, &equipo[i].citas.v.h2, &equipo[i].citas.v.h3, &equipo[i].citas.v.h4, &equipo[i].citas.v.h5);
		i++;
	}
	fclose(pf);

	AltEnter();

	logo();

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

		printf("Escoja una de las siguientes especialidades:\n");
		printf("   1. Medico de familia\n   2. Alergologia\n   3. Cardiologia\n   4. Cirugia\n   5. Dermatologia\n   6. Endocrinologia\n   7. Geriatria\n   8. Ginecologia\n   9. Oftalmologia\n   10. Oncologia\n   11.Pediatria\n   12. Psiquiatria\n   13. Rehabilitacion\n   14. Traumatologia\n   15. Urgencias\n ");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:
			dni = registrarpaciente();
			char medico[] = "Medicofamilia";
			cita_paciente(dni, medico, &equipo[0]);
			break;
		case 2:
			dni = registrarpaciente();
			char alergologia[] = "Alergologia";
			cita_paciente(dni, alergologia, &equipo[1]);
			break;
		case 3:
			dni = registrarpaciente();
			char cardiologia[] = "Cardiologia";
			cita_paciente(dni, cardiologia, &equipo[2]);
			break;
		case 4:
			dni = registrarpaciente();
			char cirugia[] = "Cirugia";
			cita_paciente(dni, cirugia, &equipo[3]);
			break;
		case 5:
			dni = registrarpaciente();
			char dermatologia[] = "Dermatologia";
			cita_paciente(dni, dermatologia, &equipo[4]);
			break;
		case 6:
			dni = registrarpaciente();
			char endocrinologia[] = "Endocrinologia";
			cita_paciente(dni, endocrinologia, &equipo[5]);
			break;
		case 7:
			dni = registrarpaciente();
			char geriatria[] = "Geriatria";
			cita_paciente(dni, geriatria, &equipo[6]);
			break;
		case 8:
			dni = registrarpaciente();
			char ginecologia[] = "Ginecologia";
			cita_paciente(dni, ginecologia, &equipo[7]);
			break;
		case 9:
			dni = registrarpaciente();
			char oftalmologia[] = "Oftalmologia";
			cita_paciente(dni, oftalmologia, &equipo[8]);
			break;
		case 10:
			dni = registrarpaciente();
			char oncologia[] = "Oncologia";
			cita_paciente(dni, oncologia, &equipo[9]);
			break;
		case 11:
			dni = registrarpaciente();
			char pediatria[] = "Pediatria";
			cita_paciente(dni, pediatria, &equipo[10]);
			break;
		case 12:
			dni = registrarpaciente();
			char psiquiatria[] = "Psiquiatria";
			cita_paciente(dni, psiquiatria, &equipo[11]);
			break;
		case 13:
			dni = registrarpaciente();
			char rehabilitacion[] = "Rehabilitacion";
			cita_paciente(dni, rehabilitacion, &equipo[12]);
			break;
		case 14:
			dni = registrarpaciente();
			char traumatologia[] = "Traumatologia";
			cita_paciente(dni, traumatologia, &equipo[13]);
			break;

		case 15: printf("  Bienvenido al servicio de urgencias\n");

			printf("\n  Responda el siguiente cuestionario con un numero del 1-10 o S(sí) - N(no)\n\n");
			printf("\n  Clasifique su nivel de su dolor 1-10:   ");
			scanf_s("%d", &dolor);

			if (dolor >= 6 && dolor <= 10) {

				printf(" \n  Sufre problemas respiratorios o cardiacos? S-N:  ");
				fflush(stdin); 
				getchar();
				scanf_s("%c", &sino);

				if (sino == 'S') {
					dolor = dolor + 4;
				}

				printf(" \n\n  Indique si alguna vez ya ha sufrido los mismos sintomas S-N:  ");
				fflush(stdin); 
				getchar();
				scanf_s("%c", &sino);

				if (sino == 'S') {
					dolor = dolor + 4;
				}
			}

			else if (dolor < 6 && dolor >= 0) {

				printf(" \n\n  Sufre dolor de cabeza S-N:  ");
				fflush(stdin);
				getchar();
				scanf_s("%c", &sino);

				if (sino == 'S') {
					dolor = dolor + 1;
				}

				printf(" \n\n  Sufre vomitos S-N:  ");
				fflush(stdin);
				getchar();
				scanf_s("%c", &sino);

				if (sino == 'S') {
					dolor = dolor + 1;
				}



				printf(" \n\n  Indique si sufre algun otro dolor fisico S-N:  ");
				fflush(stdin);
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

		i = 0;
		switch (opcion) {

		case 1: printf("  Se ha identificado como MEDICO DE FAMILIA, ingrese:\n");
			identificacion=identificacion_medicos(&equipo[0]);
			if (identificacion == 1) {
				registrarusuario(equipo[0].nombre, equipo[0].apellido);
				menu_medico(&equipo[0]);
			}
			break;

		case 2: printf("  Se ha identificado como ESPECIALISTA EN ALERGOLOGIA, ingrese:\n");
			identificacion = identificacion=identificacion_medicos(&equipo[1]);
			if (identificacion == 1) {
				menu_medico(&equipo[1]);
			}
			break;

		case 3: printf("  Se ha identificado como ESPECIALISTA EN CARDIOLOGIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[2]);
			if (identificacion == 1) {
				menu_medico(&equipo[2]);
			}
			break;

		case 4: printf("  Se ha identificado como ESPECIALISTA EN CIRUGIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[3]);
			if (identificacion == 1) {
				menu_medico(&equipo[3]);
			}
			break;

		case 5: printf("  Se ha identificado como ESPECIALISTA EN DERMATOLOGÍA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[4]);
			if (identificacion == 1) {
				menu_medico(&equipo[4]);
			}
			break;

		case 6: printf("  Se ha identificado como ESPECIALISTA EN ENDOCRINOLOGIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[5]);
			if (identificacion == 1) {
				menu_medico(&equipo[5]);
			}
			break;

		case 7: printf("  Se ha identificado como ESPECIALISTA EN GERIATRIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[6]);
			if (identificacion == 1) {
				menu_medico(&equipo[6]);
			}
			break;

		case 8: printf("  Se ha identificado como ESPECIALISTA EN GINECOLOGIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[7]);
			if (identificacion == 1) {
				menu_medico(&equipo[7]);
			}
			break;

		case 9: printf("  Se ha identificado como ESPECIALISTA EN OFTALMOLOGIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[8]);
			if (identificacion == 1) {
				menu_medico(&equipo[8]);
			}
			break;

		case 10: printf("  Se ha identificado como ESPECIALISTA EN ONCOLOGIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[9]);
			if (identificacion == 1) {
				menu_medico(&equipo[9]);
			}
			break;

		case 11: printf("  Se ha identificado como ESPECIALISTA EN PEDIATRIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[10]);
			if (identificacion == 1) {
				menu_medico(&equipo[10]);
			}
			break;

		case 12: printf("  Se ha identificado como ESPECIALISTA EN PSIQUIATRIA, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[11]);
			if (identificacion == 1) {
				menu_medico(&equipo[11]);
			}
			break;

		case 13: printf("  Se ha identificado como ESPECIALISTA EN REHABILITACION, ingrese:\n");
			identificacion = identificacion_medicos(&equipo[12]);
			if (identificacion == 1) {
				menu_medico(&equipo[12]);
			}
			break;

		case 14: printf("  Se ha identificado como ESPECIALISTA EN TRAUMATOLOGIA, ingrese:\n");
		identificacion=	identificacion_medicos(&equipo[13]);
			if (identificacion == 1) {
				menu_medico(&equipo[13]);
			}
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

			identificacion_servicios();

			ctime_s(str, sizeof str, &result);
			printf("\tLa fecha de hoy es:   %s\n", str);

			mostrar_aviso(nombreFicheroLimpieza);

			printf("\tSus tareas son -->");

			switch (fecha()) {
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

			identificacion_servicios();

			ctime_s(str, sizeof str, &result);
			printf("\tLa fecha de hoy es:   %s\n", str);

			mostrar_aviso(nombreFicheroLavanderia);

			printf("\tSus tareas son -->");

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

			identificacion_servicios();


			ctime_s(str, sizeof str, &result);
			printf("\tLa fecha de hoy es:   %s\n", str);

			mostrar_aviso(nombreFicheroCocina);

			printf("\tMenu estandar:\n");

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

			identificacion_servicios();
			;
			ctime_s(str, sizeof str, &result);
			printf("\tLa fecha de hoy es:   %s\n", str);

			mostrar_aviso(nombreFicheroMantenimiento);

			break;

		default:printf("  OPCION NO VALIDA\n\n");
		}

		break;


	case 4: printf("  Bienvenido al servicio de administracion, ingrese:\n\n");


		printf("\n   1. Ver ultimos movimientos de profesionales\n   2. Ver ultimos movimientos de pacientes\n   3. Paciente nuevo\n   4. Consultar historial clinico\n   6. Avisos \n\n");
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
			crear_paciente(&nuevo_registro);
			break;

		case 4:
			printf("Ingrese el DNI del paciente: ");
			scanf_s("%d", &dni);
			consultar_historial_clinico(dni);
			break;

		case 6:
			mostrar_aviso_administracion();
			break;

		default:printf("  OPCION NO VALIDA\n\n");

		}
		break;

	case 5: printf("Indique a quien debera ir dirigido el aviso:\n   1. Limpieza\n   2. Lavanderia\n   3. Cocina\n   4. Mantenimiento\n\n");
		scanf_s("%d", &opcion);


		switch (opcion) {
		case 1:
			getchar();
			char receptor1[] = "Limpieza";
			aviso(receptor1, nombreFicheroLimpieza);

			break;
		case 2:
			getchar();
			char receptor2[] = "Lavanderia";
			aviso(receptor2, nombreFicheroLavanderia);
			break;
		case 3:
			getchar();
			char receptor3[] = "Cocina";
			aviso(receptor3, nombreFicheroCocina);
			break;
		case 4:
			getchar();
			char receptor4[] = "Mantenimiento";
			aviso(receptor4, nombreFicheroMantenimiento);
			break;
		}
		break;
	case 6: printf("  Saliendo\n");

		Sleep(1000);

		return 0;

		break;

	default:printf("  OPCION NO VALIDA\n\n");
	}

	//SALVAR EN EL FICHERO LAS MODIFICACIONES DE LAS ESTRUCTURAS
	fopen_s(&pf, "medicos.txt", "w");
	for (i = 0; i<14; i++) {
		fprintf(pf, "%s %s %s %d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", equipo[i].especialidad, equipo[i].nombre, equipo[i].apellido, equipo[i].dni, equipo[i].contrasena, equipo[i].citas.l.h1, equipo[i].citas.l.h2, equipo[i].citas.l.h3, equipo[i].citas.l.h4, equipo[i].citas.l.h5, equipo[i].citas.m.h1, equipo[i].citas.m.h2, equipo[i].citas.m.h3, equipo[i].citas.m.h4, equipo[i].citas.m.h5, equipo[i].citas.x.h1, equipo[i].citas.x.h2, equipo[i].citas.x.h3, equipo[i].citas.x.h4, equipo[i].citas.x.h5, equipo[i].citas.j.h1, equipo[i].citas.j.h2, equipo[i].citas.j.h3, equipo[i].citas.j.h4, equipo[i].citas.j.h5, equipo[i].citas.v.h1, equipo[i].citas.v.h2, equipo[i].citas.v.h3, equipo[i].citas.v.h4, equipo[i].citas.v.h5);
	}
	fclose(pf);

	system("PAUSE");
	printf("\n\nVolviendo al inicio\n\n");
	Sleep(2000);
	system("cls");
	goto inicio;
}



void identificacion() {//anticuada se puede borrar

	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int salir = 0;
	int numusers = 0;
	int i = 0;
	char usuariofichero[20], contrasenafichero[20];
	char *usuario[15];
	char basura[20];
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
			fscanf_s(usuarios, "%s", basura, 20);


			if (strcmp(id.usuario, usuariofichero) == 0 && strcmp(id.contrasena, contrasenafichero) == 0) {

				printf("\nUsuario correcto\n\n");

				printf("\n\tBuenos dias %s \n\n", id.usuario);

				//registrarusuario(id.usuario);

				fclose(usuarios);

				salir = 1;

				break;
			}
		}

		if (salir == 0) {

			printf("\n\tUsuario incorrecto\n\n");
			printf("\n\tVuelva a introducir usuario y contrasena\n\n");
		}
	}
	return 0;
}


void identificacion_servicios() {

	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int salir = 0;
	int numusers = 0;
	int i = 0;
	char usuariofichero[20], contrasenafichero[20];
	char *usuario[15];
	FILE *usuarios;

	errno_t error;
	error = fopen_s(&usuarios, "personalservicios.txt", "r");//abre el fichero

	if (error == 0) {
		printf("Fichero abierto correctamente\n");
	}

	else {//mira si hay errores

		printf("Ha habido un error %d \n", error);

		Sleep(2000);

		system("EXIT");
	}

	while (salir == 0) { // pide usuario hasta que sale uno correcto

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

				registrarusuario(id.usuario,"");

				fclose(usuarios);

				salir = 11;

				break;
			}
		}

		if (salir == 0) {

			printf("\n\tUsuario incorrecto\n\n");
			printf("\n\tVuelva a introducir usuario y contrasena\n\n");
		}
	}
	return 0;
}

int GetFontSize(HANDLE windowHandle, COORD *size) {

	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
		return 0;

	*size = font.dwFontSize;

	return 1;
}



int SetFontSize(HANDLE windowHandle, COORD size) {

	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
		return 0;

	font.dwFontSize = size;

	if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
		return 0;

	return 1;

}


void logo() {



	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("        ,,,,,   ,,,,,      ,,,,,,        ,,,,,,     ,,,,,,,,,    ,,,,,  ,,,,,,,,,,,,,     ,,,,,      ,,,,,\n");

	printf("        MMMMF   JMMMM   ,aMMMMMMMMb,   JMMMM@MMMW,  MMMMMMMMMMb  JMMMM  MMMMMMMMMMMMF    JMMMMM      JMMMM\n");

	printf("        MMMMF   JMMMM  JMMMMM99NMMMM, JMMMM` 9MMMM  MMMMP!?NMMMF JMMMM  @@@@MMMMM@@@E   JMMMMMMI     JMMMM\n");

	printf("        MMMMWmmmdMMMM  MMMMP    YMMMW JMMMMMMmJ,    MMMMF  JMMMF JMMMM      MMMMF       MMMMJMMMJ    JMMMM\n");

	printf("        MMMMMMMMMMMMM  MMMMF    JMMMM  J@MMMMMMMMp  MMMMMMMMMMM+ JMMMM      MMMMF      JMMME,MMMM    JMMMM\n");

	printf("        MMMMP!!!YMMMM  MMMMF    JMMMM   ,,,7?@MMMML MMMMM@@@9!   JMMMM      MMMMF     JMMMMJJdMMMF   JMMMM\n");

	printf("        MMMMF   JMMMM  JMMMMp,,JMMMMW JMMMh, ,MMMME MMMMF        JMMMM      MMMMF     MMMMMMMMMMMMJ  JMMMMJJJJJJ\n");

	printf("        MMMMF   JMMMM   JNMMMMMMMMMW   @MMMMMMMMME  MMMMF        JMMMM      MMMMF    JMMMP^^^^JMMMM  JMMMMMMMMMMF\n");

	printf("        99999   J9999     ?9@@99`      Q?9@@@9!     MMMMF        JMMMM      MMMMF    9999+     99999 J9999999999T\n");

	printf(" \n\n\n");

	SetConsoleTextAttribute(hConsole, 12);

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"),

		printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	printf("                                   J@@@@@@@@@@@@@@@@NMMMMMMMMMMMMMMM@@@@@@@@@@@@@@@@@\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    JMMMMMMMMMMMMMMM\n");

	printf("                                                    J@@@@@@@@@@@@@@9\n\n\n\n");



	SetConsoleTextAttribute(hConsole, 15);

	system("PAUSE");

	system("cls");

	system("color 07");

}

void AltEnter() { //Abrir pantalla completa

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



int registrarpaciente() {//graba en el fichero los registros de los pacientes

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

	return dni;
}


void registrarusuario(char nombre[100],char apellido[100]) {//graba en el fichero los registros de los usuarios

	FILE *usuarios;
	int i;

	fopen_s(&usuarios, "registrosusuarios.txt", "a");

	time_t result = time(NULL); //imprime la hora
	char str[26];
	ctime_s(str, sizeof str, &result);

	fprintf(usuarios, "\nEl profesional %s %s ha entrado en el hospital   %s\n", nombre, apellido, str);

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

void crear_paciente(struct paciente* registro) {//crea un archivo con el nombre dni.txt

	FILE *crear_paciente;

	char txt[5] = ".txt";

	char dnic[13];

	printf("Nombre: ");
	gets(registro->nombre);
	printf("Apellido: ");
	gets(registro->apellido);
	printf("DNI ( sin letra): ");


	char letra[23] = "TRWAGMYFPDXBNJZSQVHLCKE";
	int letradni;
	fflush(stdin);
	int dni;
	scanf_s("%d", &registro->dni);

	letradni = registro->dni % 23;

	printf("\tSu DNI es: %d - %c\n\n", registro->dni, letra[letradni]);



	sprintf_s(dnic, 9, "%d", registro->dni);

	strcat_s(dnic, 13, txt);

	fopen_s(&crear_paciente, dnic, "a");

	fprintf(crear_paciente, "%s\n%s\n%d-%c\n\n", registro->nombre, registro->apellido, registro->dni, letra[letradni]);

	fclose(crear_paciente);

	printf("\n\n\t Paciente registrado correctamente\n");
}

void consultar_historial_clinico(int dni) {
	FILE *pf;
	errno_t error;
	int i;
	char txt[5] = ".txt";
	char dnic[13];
	char imprimir[300];
	char letra[23] = "TRWAGMYFPDXBNJZSQVHLCKE";
	int letradni;

	letradni = dni % 23;

	sprintf_s(dnic, 9, "%d", dni);
	strcat_s(dnic, 13, txt);

	error = fopen_s(&pf, dnic, "r");

	if (error == 0) {

		while (!feof(pf)) {
			fgets(imprimir, 200, pf);
			printf("%s", imprimir);
		}
		printf("\n");

		fclose(pf);
	}

	else {
		printf("No existe ningun usuario con ese DNI.\n\n");
		return 0;
	}

}

void aviso(char receptor[15], char nombre_fichero[50]) {
	char aviso[300];
	FILE *avisos;
	FILE *administracion;

	printf("Indique brevemente el motivo de su aviso:	");
	gets(aviso);


	fopen_s(&avisos, nombre_fichero, "a");
	fprintf(avisos, "AVISO: %s\n", aviso);
	fclose(avisos);

	fopen_s(&administracion, "avisosadministracion.txt", "a");
	fprintf(administracion, "%s: %s\n", receptor, aviso);
	fclose(administracion);

}

void mostrar_aviso(char nombre_fichero[25]) { //Este borra el aviso una vez que ya ha salido, no imprime los avisos anteriores
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

void cita_paciente(int dni, char especialidad[30], medico* p) {
	FILE *pf;
	int i;
	errno_t error;
	char txt[5] = ".txt";
	int dia, hora;
	char dnic[13];

	char letra[23] = "TRWAGMYFPDXBNJZSQVHLCKE";
	int letradni;

	letradni = dni % 23;

	sprintf_s(dnic, 9, "%d", dni);

	strcat_s(dnic, 13, txt);


	error = fopen_s(&pf, dnic, "r");
	if (error == 0) {
		printf("Bienvenido al hospital.\n");
		fclose(pf);
	}

	else {
		printf("No existe ningun usuario con ese DNI.\n\tAcuda a administracion para registrarse.\n");
		return 0;
	}

	fopen_s(&pf, dnic, "a");

	printf("Escoja el dia para la cita:\n  1. Lunes\n  2. Martes\n  3. Miercoles\n  4. Jueves\n  5. Viernes\n\n");
	scanf_s("%d", &dia);


	switch (dia) {
	case 1:
		printf("Escoja una franja horaria:\n  1. 08:00-09:00\n  2. 09:00-10:00\n  3. 10:00-11:00\n  4. 11:00-12:00\n  5. 12:00-13:00\n\n");
		scanf_s("%d", &hora);
		switch (hora) {
		case 1:
			if (p->citas.l.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Lunes--> 08:00-09:00\n", especialidad);
				p->citas.l.h1 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 2:
			if (p->citas.l.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Lunes--> 09:00-10:00\n", especialidad);
				p->citas.l.h2 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 3:
			if (p->citas.l.h2 == 0) {
				fprintf(pf, "\t Cita en %s: Lunes--> 10:00-11:00\n", especialidad);
				p->citas.l.h3 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 4:
			if (p->citas.l.h1 == 0) {
				fprintf(pf, "\tCita en %s: Lunes--> 11:00-12:00\n", especialidad);
				p->citas.l.h4 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 5:
			if (p->citas.l.h1 == 0) {
				fprintf(pf, "\tCita en %s: Lunes--> 12:00-13:00\n", especialidad);
				p->citas.l.h5 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		}
		break;
	case 2:
		printf("Escoja una franja horaria:\n  1. 08:00-09:00\n  2. 09:00-10:00\n  3. 10:00-11:00\n  4. 11:00-12:00\n  5. 12:00-13:00\n\n");
		scanf_s("%d", &hora);
		switch (hora) {
		case 1:
			if (p->citas.m.h1 == 0) {
				fprintf(pf, "\tCita en %s: Martes--> 08:00-09:00\n", especialidad);
				p->citas.m.h1 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 2:
			if (p->citas.m.h1 == 0) {
				fprintf(pf, "\tCita en %s: Martes--> 09:00-10:00\n", especialidad);
				p->citas.m.h2 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 3:
			if (p->citas.l.h2 == 0) {
				fprintf(pf, "\tCita en %s: Martes--> 10:00-11:00\n", especialidad);
				p->citas.m.h3 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 4:
			if (p->citas.l.h1 == 0) {
				fprintf(pf, "\tCita en %s: Martes--> 11:00-12:00\n", especialidad);
				p->citas.m.h4 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 5:
			if (p->citas.l.h1 == 0) {
				fprintf(pf, "\tCita en %s: Martes--> 12:00-13:00\n", especialidad);
				p->citas.m.h5 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		}
		break;
	case 3: printf("Escoja una franja horaria:\n  1. 08:00-09:00\n  2. 09:00-10:00\n  3. 10:00-11:00\n  4. 11:00-12:00\n  5. 12:00-13:00\n\n");
		scanf_s("%d", &hora);
		switch (hora) {
		case 1:
			if (p->citas.x.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Miercoles--> 08:00-09:00\n", especialidad);
				p->citas.x.h1 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 2:
			if (p->citas.x.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Miercoles--> 09:00-10:00\n", especialidad);
				p->citas.x.h2 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 3:
			if (p->citas.x.h2 == 0) {
				fprintf(pf, "\t Cita en %s: Miercoles--> 10:00-11:00\n", especialidad);
				p->citas.x.h3 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 4:
			if (p->citas.x.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Miercoles--> 11:00-12:00\n", especialidad);
				p->citas.x.h4 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 5:
			if (p->citas.x.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Miercoles--> 12:00-13:00\n", especialidad);
				p->citas.x.h5 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		}
		break;
	case 4:
		printf("Escoja una franja horaria:\n  1. 08:00-09:00\n  2. 09:00-10:00\n  3. 10:00-11:00\n  4. 11:00-12:00\n  5. 12:00-13:00\n\n");
		scanf_s("%d", &hora);
		switch (hora) {
		case 1:
			if (p->citas.j.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Jueves--> 08:00-09:00\n", especialidad);
				p->citas.j.h1 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 2:
			if (p->citas.j.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Jueves--> 09:00-10:00\n", especialidad);
				p->citas.j.h2 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 3:
			if (p->citas.j.h2 == 0) {
				fprintf(pf, "\t Cita en %s: Jueves--> 10:00-11:00\n", especialidad);
				p->citas.j.h3 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 4:
			if (p->citas.j.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Jueves--> 11:00-12:00\n", especialidad);
				p->citas.j.h4 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 5:
			if (p->citas.j.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Jueves--> 12:00-13:00\n", especialidad);
				p->citas.j.h5 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		}
		break;
	case 5:
		printf("Escoja una franja horaria:\n  1. 08:00-09:00\n  2. 09:00-10:00\n  3. 10:00-11:00\n  4. 11:00-12:00\n  5. 12:00-13:00\n\n");
		scanf_s("%d", &hora);
		switch (hora) {
		case 1:
			if (p->citas.v.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Viernes--> 08:00-09:00\n", especialidad);
				p->citas.v.h1 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 2:
			if (p->citas.v.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Viernes--> 09:00-10:00\n", especialidad);
				p->citas.v.h2 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 3:
			if (p->citas.v.h2 == 0) {
				fprintf(pf, "\t Cita en %s: Viernes--> 10:00-11:00\n", especialidad);
				p->citas.v.h3 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 4:
			if (p->citas.v.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Viernes--> 11:00-12:00\n", especialidad);
				p->citas.v.h4 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		case 5:
			if (p->citas.v.h1 == 0) {
				fprintf(pf, "\t Cita en %s: Viernes--> 12:00-13:00\n", especialidad);
				p->citas.v.h5 = dni;
				printf("\nSu cita ha sido registrada correctamente\n\n");
			}
			else printf("El horario ya ha sido seleccionado\n");
			break;
		}
		break;
	}
	dnic[0] = '\0';

	fclose(pf);
	return 0;
}

void consulta_medico(int dni, medico* p) {
	FILE *pf;
	errno_t error;
	int i;
	char txt[5] = ".txt";
	char dnic[13];
	char imprimir[300];
	char letra[23] = "TRWAGMYFPDXBNJZSQVHLCKE";
	int letradni;
	char consulta[1000];

	letradni = dni % 23;

	sprintf_s(dnic, 9, "%d", dni);
	strcat_s(dnic, 13, txt);

	error = fopen_s(&pf, dnic, "r");
	if (error == 0) {
		printf("Bienvenido al hospital.\n");
	}

	else {
		printf("No existe ningun usuario con ese DNI.\n\tAcuda a administracion para registrarse.\n");
		return 0;
	}

	while (!feof(pf)) {
		fgets(imprimir, 300, pf);
		printf("%s", imprimir);
	}
	printf("\n");

	fclose(pf);

	error = fopen_s(&pf, dnic, "a");

	printf("/n/n/tConsulta %s (indique brevemente los sintomas del paciente): \n", p->especialidad);
	getchar();
	gets(consulta);

	fprintf(pf, "/n%s: %s", p->especialidad, consulta);

	fclose(pf);
}



void menu_medico(medico* p) {
	int opcion;
	int dni;

	printf("Elija una de las siguientes opciones:\n\t1. Citas de la semana.\n\t2. Consulta del paciente.\n ");
	scanf_s("%d", &opcion);

	switch (opcion) {
	case 1: printf("\tCitas de la semana:\n\n");
		printf("\tLunes: \n\t\t08:00-09:00-> %d\t\t09:00-10:00-> %d\t\t10:00-11:00-> %d\t\t11:00-12:00-> %d\t\t12:00-13:00-> %d\n", p->citas.l.h1, p->citas.l.h2, p->citas.l.h3, p->citas.l.h4, p->citas.l.h5);
		printf("\tMartes: \n\t\t08:00-09:00-> %d\t\t09:00-10:00-> %d\t\t10:00-11:00-> %d\t\t11:00-12:00-> %d\t\t12:00-13:00-> %d\n", p->citas.m.h1, p->citas.m.h2, p->citas.m.h3, p->citas.m.h4, p->citas.m.h5);
		printf("\tMiercoles: \n\t\t08:00-09:00-> %d\t\t09:00-10:00-> %d\t\t10:00-11:00-> %d\t\t11:00-12:00-> %d\t\t12:00-13:00-> %d\n", p->citas.x.h1, p->citas.x.h2, p->citas.x.h3, p->citas.x.h4, p->citas.x.h5);
		printf("\tJueves: \n\t\t08:00-09:00-> %d\t\t09:00-10:00-> %d\t\t10:00-11:00-> %d\t\t11:00-12:00-> %d\t\t12:00-13:00-> %d\n", p->citas.j.h1, p->citas.j.h2, p->citas.j.h3, p->citas.j.h4, p->citas.j.h5);
		printf("\tViernes: \n\t\t08:00-09:00-> %d\t\t09:00-10:00-> %d\t\t10:00-11:00-> %d\t\t11:00-12:00-> %d\t\t12:00-13:00-> %d\n", p->citas.v.h1, p->citas.v.h2, p->citas.v.h3, p->citas.v.h4, p->citas.v.h5);

		break;
	case 2: printf("\tConsulta medica: \n");
		printf("\t\tIntroduzca el dni del paciente sin letra: ");
		scanf_s("%d", &dni);
		consulta_medico(dni, p); //Funciones que llaman a funciones
		break;
	}
}

int identificacion_medicos(medico* p) {
	char contrasena[6];
	int i,j=0;
	int opcion;
	printf("\n\tElija el modo de identificarse:\n\n");
	printf("\n\t1.-Mediante tarjeta\n\t  2.-Mediante contrasena\n\n");
	scanf_s("%d", &opcion);
	switch (opcion)
	{
	case 1:
		


		do {
			char *contrasena = leertarjeta();

			i = strcmp(p->contrasena, contrasena);
			if (i == 0) {
				printf("Tarjeta correcta\n");
				return 1;
			}
			else {
				printf("\n\tLa tarjeta no esta en nuestra base de datos o no corresponde a esta especialidad\n");
			}
			j++;
			printf("\n\tLe quedan %d intentos\n",4-j);
		} while (j<4);

		break;
	case 2:


		do {
			printf("Introduzca la contrasena: ");
			fflush(stdin);
			getchar();
			gets(contrasena);
			i = strcmp(p->contrasena, contrasena);
			if (i == 0) {
				printf("Contrasena correcta.\n");
				return 1;
			}
			else {
				printf("No valido\n");
			}
			j++;
			printf("\n\tLe quedan %d intentos\n", 4 - j);
		} while (j<4);

		break;

	default:
		printf("\n\tOPCION NO VALIDA");
		
		break;
	}

	printf("\n\tHa agotado todos los intentos\n\n");

	return 0;
}


char* leertarjeta() {

	//utilizando la libreria windows.h, comunicamos el arduino y el ordenador mediante un puerto serie, en este caso el COM3
	FILE *usuarios;

	HANDLE hComm;

	hComm = CreateFile("\\\\.\\COM3",                //el numero de puerto del arduino
		GENERIC_READ | GENERIC_WRITE, //leer o escribir
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	if (hComm == INVALID_HANDLE_VALUE) {// no puede abrir el puerto
		printf("\n\n\tError en la lectura\n\n");
		printf("\n\n\tSaliendo\n\n");
		return 0;
	}


	DCB dcbSerialParams = { 0 }; // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	dcbSerialParams.BaudRate = CBR_9600;  // Velocidad de comunicacion con el arduino 9600
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	SetCommState(hComm, &dcbSerialParams);
	char TempChar = 0; //El caracter que lee
	char SerialBuffer[256];//Cadena donde se almacenan los caracteres
	DWORD NoBytesRead;
	int i = 0;
	printf("\n\n \tLeyendo tarjeta\n\n");
	Sleep(30);

	while (TempChar != 'f')
	{
		ReadFile(hComm,
			&TempChar,
			sizeof(TempChar),
			&NoBytesRead,
			NULL);

		SerialBuffer[i] = TempChar;// alamacena el caracter que ha leido en la cadena
		i++;

	}


	Sleep(30);
	printf("\n\n\tLectura correcta\n\n");
	CloseHandle(hComm);//Cierra el puerto
	char identificacion[50] = { 0 };
	char basura[20];
	char idfichero[100];
	char nombre[100];

	i = 0;

	while (SerialBuffer[i] != 'f') {

		identificacion[i] = SerialBuffer[i];// copia la cadena de lectura en  una cadena con una longitud especifica

		i++;
	}

	printf("\n\n\tIdentificacion:  %s\n\n",identificacion);



	return identificacion;
}