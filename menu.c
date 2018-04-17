#include<stdio.h>

struct perfil {
	char usuario[15];
	char contrasena[15];
};

void main() {
	
	
	logotipo();
	

	
	struct perfil id;  //Estructura para almacenar el usuario y contraseña ingresados.
	int opcion;


	printf("\n\n Escoja una de las siguientes opciones para identificarse: \n\n");
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


int logotipo(){


printf("   _										\n");
printf("   d8b   ,.										\n");
printf("   d8b   88[    __           ______                  _oo       _	\n");
printf("   d8b   88b   d888b   ,ooL d8888888. ,8b d888888888o888b     88P\n");
printf("   Y8booo88b  d8P Y88.,88P' 888b  `88.]88  'Y8b''''d8P d8b    88[\n");
printf("   `88PPP888[ d8b  88[Y8b_  8888od888']88    88[  d88__i88.   Y8b\n");
printf("    d8b   88[ d8b  88[ Y888LY888P ''  ]88    d8b  d8888888b   d8b\n");
printf("    ]88   Y8b Y88_d88'   ]88b888b     ]88    Y8b  d8b   `88.  Y8b\n");
printf("    `8P   Y8P  Y888P  dd8888PY888      88[    88' `88o   Y8b   88booo.\n");
printf("                     ` ''    YPP      Y8P     '   ` '    `'   `PPPPPP\n");
printf(" \n");
printf(" \n");
printf(" \n");
printf(" \n");
																																																																				printf(" \n");

	system("pause");
	
	system("cls");

return 0;

}
