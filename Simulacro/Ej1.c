#include <stdio.h>
#include <stdlib.h>

int main(){

	int numero;
	float * arrNumero = (float*)malloc(10 * sizeof(numero));

	printf("Introduce el tamaño del array: ");
	scanf("%d", &numero);

	for (int i = 0; i < numero; ++i){

		printf("\nIntroduce un numero en el array[%d]: ", i + 1);
		scanf(" %f", &arrNumero[i]);

		printf("\n\tLa posicion del array [%d] tiene un valor de : %.2f\n en la posicion de memoria %p", i+1, arrNumero[i] / numero, arrNumero);

	}
		


	float * arrNumeroMitad = (float*)malloc(10 * sizeof(arrNumero) /2);

	printf("\n\nPARTE DEL ARRAY REDUCIDO\n");


	for (int i = 0; i < numero; ++i){

		arrNumeroMitad[i] = arrNumero[i];

		printf("\n\tLa posicion del array [%d] tiene un valor de : %.2f\n en la posicion de memoria %p", i+1, arrNumeroMitad[i] / numero, arrNumeroMitad);
	}

	printf("\n\n");

	free(arrNumero);
	free(arrNumeroMitad);

	return 0;
}
