#include <stdio.h>

struct perfil {
	char usuario[50];
	char contrasena[50];
};

void main() {

	struct perfil id;

	char usuario[50];
	char contrasena[50];
	

	printf("     Usuario: ");
	gets(usuario);
	printf("\n     Contrasena: ");
	gets(contrasena);

	while (comprobarusuario(usuario, contrasena) == 1) {
		printf("     Usuario: ");
		gets(usuario);
		printf("\n     Contrasena: ");
		gets(contrasena);
	}

	

		strcpy(id.usuario, usuario);
		strcpy(id.contrasena, contrasena);

		printf("Ha iniciado sesion como %s\n\n", id.usuario);

		printf("Buenos dias %s\n\n",id.usuario);
		

		system("pause");


}


int comprobarusuario(char usuario[50],char contrasena[50]) {


	
		

		if (strncmp(usuario, "Miguel") == 0 && strncmp(contrasena, "1234")==0) {

			printf("\nUsuario correcto\n\n");

			return 0;

		}

		else {

			printf("\nUsuario incorrecto\n\n");

			return 1;

		}


}