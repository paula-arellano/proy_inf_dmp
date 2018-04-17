#include <stdio.h>
#include <string.h>

struct perfil {
	char usuario[50];
	char contrasena[50];
};


struct perfil id;

void main() {


	char usuario[50];
	char contrasena[50];
	

	printf("     Usuario: ");
	gets(id.usuario);
	printf("\n     Contrasena: ");
	gets(id.contrasena);

	while (comprobarusuario(id.usuario, id.contrasena) == 1) {
		printf("     Usuario: ");
		gets(id.usuario);
		printf("\n     Contrasena: ");
		gets(id.contrasena);
	}


		printf("Ha iniciado sesion como %s\n\n", id.usuario);

		printf("Buenos dias %s\n\n",id.usuario);
		

		system("pause");


}


int comprobarusuario(char usuario[50],char contrasena[50]) {


	
		

		if (strncmp(usuario, "Miguel",50) == 0 && strncmp(contrasena,"1234",50)==0) {

			printf("\nUsuario correcto\n\n");

			return 0;

		}

		else {

			printf("\nUsuario incorrecto\n\n");

			return 1;

		}


}