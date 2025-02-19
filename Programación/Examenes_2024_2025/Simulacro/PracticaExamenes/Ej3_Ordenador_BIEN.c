#include <stdio.h>
#include <stdlib.h>

int main(){

	int tamaño;

	printf("Introduce el valor de la memoria: ");
	scanf("%d", &tamaño);
	if(tamaño <= 0){
		printf("Introduce un numero mayor o igual a 1\n");
		return 1;
	}

	double *valor = (double*) malloc(tamaño * sizeof(double));

	if(valor == NULL){
		printf("Error al reservar memoria\n");
		return 1;
	}

	for (int i = 0; i < tamaño; ++i){

	valor[i]=1.0 / (i+1);

	}

	for (int i = 0; i < tamaño; ++i){

	printf("Valor de [%d]: %f en la memoria %p\n", i + 1, valor[i], &valor[i]);

	}

	return 0;
}