#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>


//int login(struct usuario * user);
//int confirmacion();
int comprobardni();

/////////////////////////////////////////////////////////////////////////////////////////          MAIN          ////////////////////////////////////////////////////////////////////////////////////////////


	void main() {
		int dni;
		printf("Introducir dni sin letra\n");
		scanf_s("%d", &dni);

		int status = comprobardni(dni);
		printf("El resultado es %d\n", status);
		system("PAUSE");
	}

	int comprobardni(int dni) {
		int num;
		for (int i = 10; i < 10000 * 10000; i = i * 10) {
			if ((dni % i) / (i / 10) < 0 || (dni % i) / (i / 10) > 9)
				return 1;
		}
		return 0;
	}

/*
void main() {
	FILE * parking;
	errno_t parking_error404;

	int state = 1, loop = 1;
	char opcion, tipo, matric[8], vector[30], aux[30];

	struct Plaza {
		int estado;
		char tipo;
		char matricula[8];
	};
	struct usuario {
		char nickname[50];
		char password[50];
	};
	struct usuario user;

	// Usuario: admin		Password: password

	parking_error404 = fopen_s(&parking, "parking.txt", "r");
	fclose(parking);

	if (parking_error404 != 0) {
		printf("No se ha podido abrir el registro del parking\n");
		Sleep(1500);
	}

	system("cls");

	while (loop == 1) {
		int conf;
		printf("Register - R\t Login - L\n");
		scanf_s("%c", &opcion);
		getchar();

		if (opcion >= 'a' && opcion <= 'z')
			opcion -= 32;

		switch (opcion) {
		case 'R':
			printf("Introduzca su usuario\n");
			gets(vector);
			printf("Es este su usuario %s?\n", vector);
			conf = confirmacion();
			if (conf == 0) {}

			else break;

			printf("Introduzca su contraseña\n");
			gets(aux);
			printf("Es esta su contraseña %s?\n\t Y  -  N", vector);
			conf = confirmacion();
			if (conf == 0) {
				fopen_s(&parking, "parking.txt", "a");
				fprintf_s(parking, "\n%s", vector);
				fprintf_s(parking, "|");
				fprintf_s(parking, "%s", aux);
				fclose(parking);
				loop = 0;
			}
			break;

		case 'L':
			printf("Introduzca su usuario");
			scanf_s("%s", user.nickname, 50);

			printf("Introduzca la contraseña");
			scanf_s("%s", user.password, 50);

			state = login(parking, user);
			if (state == 0) { loop = 0; }

		default:
			printf("Opcion no valida");
			Sleep(1000);
			system("cls");
		}
	}
	system("PAUSE");
}





	int login(FILE * parking, usuario * user) {

	struct usuario {
		char nickname[50];
		char password[50];
	};
	struct usuario user;

	char aux[30];
	int i = 0;
	while (fgetc(parking) != EOF) {
		for (i; fgetc(parking) != '|'; i++) {
			aux[i] = fgetc(parking);
		}
		if (aux == user.nickname) {

		}

	}
}

	int confirmacion() {		// 0 == TRUE    -    1 == FALSE
		char opcion;
		int loop = 1;
		while (loop == 1) {
			printf("\n Y (yes)   -   N (no)\n");
			scanf_s("%c", &opcion);
			getchar();
			if (opcion >= 'a' && opcion <= 'z') {
				opcion -= 32;
			}
			system("cls");
			switch (opcion) {
			case 'Y':
				return 0;
				break;

			case 'N':
				return 1;
				break;

			default:
				printf("No se reconoce la opccion seleccionada.\nIntroduzca una de las opciones listadas por favor.\n");
				Sleep(1500);
				break;
			}
		}
	}
	*/
