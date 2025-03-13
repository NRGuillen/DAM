#include <stdio.h>
#include <stdlib.h>

/*
PRINCIPALES ERRORES

1. ##################################################################################################################################################

	Estaba siempre escribiendo la memoria de la primera posicion porque tenia:

			printf("\n\tLa posicion del array [%d] tiene un valor de : %.2f\n en la posicion de memoria %p", i+1, arrNumero[i] / numero, arrNumero);

	Por lo tanto estaba accediendo a la memoria del mismo array siempre, la solucion es &arrNumero[i], para acceder a la memoria de todo el array.

2. ##################################################################################################################################################

	Estaba declarando el malloc de numero antes de usarlo, es decir antes de darle un valor.
	Estaba dando un tamaño dinamico de 10, en vez de darle el tamaño del usuario (numero) malloc(10 * sizeof(numero) -> malloc(numero * sizeof(float)

	int numero;
		float * arrNumero = (float*)malloc(10 * sizeof(numero));

		printf("Introduce el tamaño del array: ");
		scanf("%d", &numero);

	CORRECCION

	int numero;

		printf("Introduce el tamaño del array: ");
		scanf("%d", &numero);

		float * arrNumero = (float*)malloc(numero * sizeof(float));

3. ##################################################################################################################################################

	En el segundo bucle estaba causando un desbordamiento debido a que tenia un bucle con el tamaño de (numero) en vez de con el tamaño modificado / 2

	for (int i = 0; i < numero; ++i){

		arrNumeroMitad[i] = arrNumero[i];

		printf("\n\tLa posicion del array [%d] tiene un valor de : %.2f\n en la posicion de memoria %p", i+1, arrNumeroMitad[i] / numero, arrNumeroMitad);
	}

	CORRECCION
	
	for (int i = 0; i < numeroMitad; ++i){

		arrNumeroMitad[i] = arrNumero[i];

		printf("\n\tLa posicion del array [%d] tiene un valor de : %.2f\n en la posicion de memoria %p", i+1, arrNumeroMitad[i] / numero, &arrNumeroMitad[i]);
	}

4. ##################################################################################################################################################

	ACLARACION

	La memoria dinamica se tiene que adaptar al tipo de varibale:

	EJEMPLOS:

	int *arrNumero = (int *)malloc(numero * sizeof(int));
	float * arrNumero = (float*)malloc(numero * sizeof(float));
	char *arrCaracteres = (char *)malloc(numero * sizeof(char));


*/

int main(){

	int numero;

	printf("Introduce el tamaño del array: ");
	scanf("%d", &numero);

	float * arrNumero = (float*)malloc(numero * sizeof(float));


	for (int i = 0; i < numero; ++i){

		printf("\nIntroduce un numero en el array[%d]: ", i + 1);
		scanf(" %f", &arrNumero[i]);

		printf("\n\tLa posicion del array [%d] tiene un valor de : %.2f\n en la posicion de memoria %p", i+1, arrNumero[i] / numero, &arrNumero[i]);

	}
		
	int numeroMitad = numero /2;

	float * arrNumeroMitad = (float*)malloc(numeroMitad * sizeof(float));

	printf("\n\nPARTE DEL ARRAY REDUCIDO\n");


	for (int i = 0; i < numeroMitad; ++i){

		arrNumeroMitad[i] = arrNumero[i];

		printf("\n\tLa posicion del array [%d] tiene un valor de : %.2f\n en la posicion de memoria %p", i+1, arrNumeroMitad[i] / numero, &arrNumeroMitad[i]);
	}

	printf("\n\n");

	free(arrNumero);
	free(arrNumeroMitad);

	return 0;
}