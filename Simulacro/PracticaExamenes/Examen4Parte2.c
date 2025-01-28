#include <stdio.h>
#include <stdlib.h>

int main(){

	int num;

	printf("Introduce un numero para determinar el tamaño del array: ");
	scanf("%d", &num);

	if(num < 0){
		printf("Introduce un numero positivo :/\n");
	}

	double *valor = malloc(num* sizeof(double));

	if(valor == NULL){
		printf("No se pudo asignar la memoria\n");
	}

	for (int i = 0; i < num; ++i){

	valor[i] = (double) 1 / (i+1);

	printf("\nPosicion [%d]: %f con posicion de memoria en %p\n", i + 1, valor[i], &valor[i]);

	}

	printf("\n\nMemoria aumentada x2:\n");

	double *valor2 = malloc((num* 2) * sizeof(double));

	if(valor2 == NULL){
		printf("No se pudo asignar la memoria\n");
	}

	for (int i = 0; i < num * 2; ++i){

	valor2[i] = (double) 1 / (i+1);

	printf("\nPosicion [%d]: %f con posicion de memoria en %p\n", i + 1, valor2[i], &valor2[i]);

	}



	free(valor2);
	free(valor);

	return 0;
}