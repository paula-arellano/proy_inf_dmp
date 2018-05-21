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
								//La funcion devuelve 0 si es correcto, devuelve un 1 si no lo es
	int comprobardni(int dni) {
		int num;
		for (int i = 10; i < 10000 * 10000; i = i * 10) {
			if ((dni % i) / (i / 10) < 0 || (dni % i) / (i / 10) > 9)
				return 1;
		}
		return 0;
	}
