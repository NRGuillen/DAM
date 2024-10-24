#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int altura = 0;
	int anchura = 0;
	int numero;

	printf("Introduce el tamaño del cuadrad. ");
	scanf("%d", &numero);

	for(anchura = 0; anchura < numero; anchura++){
	for(altura = 0; altura < numero; altura++){
		printf("* ");// el espacio no es necesario, pero queda mejor esteticamente al ejecutar el codigo
	}

		printf("\n");// sin este printf todos los astericos se escribiran en una misma linea, es decir ********* en vez de  ***
//  ***
//  ***
	}

	return 0;

}
	
