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

void main() {
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int opcion;

	AltEnter();

	logo();
	Sleep(3000);

	system("PAUSE");
	system("cls");
	system("color 0F");

	printf(" \n\n");
	printf("Pulsa Alt+Enter o F11 en cualquier momento para salir de la pantalla completa");
	printf(" \n\n");
	printf(" \n\n");
	printf(" \tEscoja una de las siguientes opciones para identificarse: \n");
	printf(" \n\n");
	printf(" \t  1. Paciente\n\t  2. Equipo medico\n\t  3. Personal de servicios\n \t  4. Administracion\n \t  5. Salir\n\n");
	scanf_s("%d", &opcion);

	switch (opcion) {
	case 1:printf("  Se ha identificado como PACIENTE, ingrese:\n");
		identificacion();

		printf("Escoja una de las siguientes especialidades:\n");
		printf("   1. Medico de familia\n   2. Alergología\n   3. Cardiología\n   4. Cirugia\n   5. Dermatologia\n   6. Endocrinologia\n   7. Geriatria\n   8. Ginecologia\n   9. Oftalmologia\n   10. Oncologia\n   11.Pediatria\n   12. Psiquiatria\n   13. Rehabilitacion\n   14. Traumatologia\n   15. Urgencias\n");
		break;

	case 2: printf("Escoja una de las siguientes especialidades:\n");
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
		case 15: printf("Indique brevemente el problema:\n");
			//Habria que llevar esto (no se si con punteros) al fichero de problemas
		}
		break;
	case 3: printf("Escoja uno de los siguientes campos:\n");
		printf("   1. Limpieza\n   2. Lavanderia\n   3. Cocina\n   4. Mantenimiento\n\n");
		scanf_s("%d", &opcion);
		getchar();

		switch (opcion) {
		case 1: printf("  Se ha identificado como PERSONAL DE LIMPIEZA, ingrese:\n");
			identificacion();
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
		}
		break;


	case 4: printf("  Se ha identificado como PERSONAL DE ADMINISTRACION, ingrese:\n");
		identificacion();
			break;
	}

	system("PAUSE");

}

void identificacion() {
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int salir=0;
	

	while (1) { // pide usuario hasta que sale uno correcto
		

	printf("     Usuario: ");
	
	scanf_s("%s",&id.usuario,15); //el getchar no funciona aqui
	printf("\n     Contrasena: ");
	getchar();
	gets(id.contrasena);



		if (strcmp(id.usuario, "admin") == 0 && strcmp(id.contrasena, "1234") == 0) {
			printf("\nUsuario correcto\n\n");
			
			break;
		}

		else {

			printf("\n\tUsuario incorrecto\n\n");

			printf("\n\tVuelva a introducir usuario y contrasena\n\n");


		}
	}
	return 0;
}


void logo() {



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

void AltEnter()
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