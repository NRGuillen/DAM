#include <stdio.h>
#include <stdlib.h>

int main(){

	int opcion;
	//No es necesario inicializar la variable opcion, porque el primer uso de la variable es de escritura.

	do{	

		printf("Introduce una opcion: (4 para salir)\n");
		scanf("%d", &opcion);
	} while(opcion !=4);

	return 0;
}
