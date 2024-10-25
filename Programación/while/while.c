#include <stdio.h>
#include <stdlib.h>

int main(){

	int opcion = 0;
	//Es necesario (no obligatorio) inicializar la variable porque el primer fuso de la variable es de lectura

	while(opcion != 4){
	
		//codigo  a ejecutar
		//si pones una letra se crea un bucle porque no mete un enter
		printf("Introduce una opcion: (4 para salir)\n");
		scanf("%d", &opcion);
	} 

	return 0;
}
