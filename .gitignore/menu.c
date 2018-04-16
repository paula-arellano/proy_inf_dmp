void main() {
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int opcion;
	

	printf(" Escoja una de las siguientes opciones para identificarse: \n");
	printf("   1. Paciente\n   2. Equipo medico\n   3. Personal de servicios\n   4. Administracion\n   5. Salir\n\n");
	scanf_s("%d", &opcion);

	switch (opcion) {
	case 1: printf("Escoja una de las siguientes especialidades:\n");
		printf("   1. Medico de familia\n   2. ");
		break;
	case 2: printf("Escoja una de las siguientes especialidades:\n");
		printf("   1. Medico de familia\n   2. ");

	case 3: printf("Escoja uno de los siguientes campos:\n");
		printf("   1. Limpieza\n   2. Lavanderia\n   3. Cocina\n   4. Mantenimiento\n\n");
		scanf_s("%d", &opcion);
		getchar();

			switch (opcion) {
			case 1: printf("  Se ha identificado como PERSONAL DE LIMPIEZA, ingrese:\n");
				printf("     Usuario: ");
				gets(id.usuario);
				printf("\n     Contrasena: ");
				gets(id.contrasena);
				//Comprobacion usuario y contrasena con string compare (del fichero)
				break;

			case 2: printf("  Se ha identificado como PERSONAL DE LAVANDERIA, ingrese:\n");
				printf("     Usuario: ");
				gets(id.usuario);
				printf("\n     Contrasena: ");
				gets(id.contrasena);
				//Comprobacion usuario y contrasena con string compare (del fichero)
				break;

			case 3: printf("  Se ha identificado como PERSONAL DE COCINA, ingrese:\n");
				printf("     Usuario: ");
				gets(id.usuario);
				printf("\n     Contrasena: ");
				gets(id.contrasena);
				//Comprobacion usuario y contrasena con string compare (del fichero)
				break;

			case 4: printf("  Se ha identificado como PERSONAL DE MANTENIMIENTO, ingrese:\n");
				printf("     Usuario: ");
				gets(id.usuario);
				printf("\n     Contrasena: ");
				gets(id.contrasena);
				//Comprobacion usuario y contrasena con string compare (del fichero)
				break;
			}
		break;


	case 4: printf("  Se ha identificado como PERSONAL DE ADMINISTRACION, ingrese:\n");
		printf("     Usuario: ");
		gets(id.usuario);
		printf("\n     Contrasena: ");
		gets(id.contrasena);

		//Comprobacion usuario y contrasena con string compare (del fichero)
		break;
	}

	system("PAUSE");

}
