#include<stdio.h>

struct perfil {
	char usuario[15];
	char contrasena[15];
};

void identificacion();

void main() {
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int opcion;


	printf(" Escoja una de las siguientes opciones para identificarse: \n");
	printf("   1. Paciente\n   2. Equipo medico\n   3. Personal de servicios\n   4. Administracion\n   5. Salir\n\n");
	scanf_s("%d", &opcion);

	switch (opcion) {
	case 1:printf("  Se ha identificado como PACIENTE, ingrese:\n");
		identificacion();
		
		printf("Escoja una de las siguientes especialidades:\n");
		printf("   1. Medico de familia\n   2. Alergología\n   3. Cardiología\n   4. Cirugia\n   5. Dermatologia\n   6. Endocrinologia\n   7. Geriatria\n   8. Ginecologia\n   9. Oftalmologia\n   10. Oncologia\n   11.Pediatria\n   12. Psiquiatria\n   13. Rehabilitacion\n   14. Traumatologia\n   15. Urgencias\n");
		break;

	case 2: printf("Escoja una de las siguientes especialidades:\n");
		printf("   1. Medico de familia\n   2. Alergología\n   3. Cardiología\n   4. Cirugia\n   5. Dermatologia\n   6. Endocrinologia\n   7. Geriatria\n   8. Ginecologia\n   9. Oftalmologia\n   10. Oncologia\n   11.Pediatria\n   12. Psiquiatria\n   13. Rehabilitacion\n   14. Traumatologia\n   15. Informar de un problema\n");
		
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
		identificacion()
		break;
	}

	system("PAUSE");

}

void identificacion() {
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	printf("     Usuario: ");
	gets(id.usuario);
	printf("\n     Contrasena: ");
	gets(id.contrasena);

	if (strncmp(id.usuario,/*lo que haya en el fichero*/,15 ) == 0 && strncmp(id.contrasena, /*lo que haya fichero*/, 15) == 0) {
		printf("\nUsuario correcto\n\n");
			return 0;
	}

	else {
		printf("\nUsuario incorrecto\n\n");
		return 1;
	}
}