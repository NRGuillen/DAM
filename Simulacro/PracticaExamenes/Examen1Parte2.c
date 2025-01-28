#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int numero;

	//MEMORIA 1

	printf("Introduce un numero entero para determinar el tamaño del array: ");
	scanf("%d", &numero);

	int *arr = malloc(numero* sizeof(int));

		printf("\nRellene el array:\n\n");
		
		for (int i = 0; i < numero; ++i){

		printf("\tPosicion [%d]: ", i+1);
		scanf("%d", &arr[i]);

		}

		printf("\nValores introducidos en el primer array:\n\n");
		for (int i = 0; i < numero; ++i){

		printf("\tEn la posicion del array [%d]: %d\n", i + 1, arr[i]);

		}

	//MEMORIA 2

	int numero2;

	printf("\n\nIntroduce un numero entero para determinar el tamaño del segundo array: ");
	scanf("%d", &numero2);

	int *arr2 = malloc(numero2* sizeof(int));

		printf("\nRellene el array 2:\n\n");
		
		for (int i = 0; i < numero2; ++i){

		printf("\tPosicion [%d]: ", i+1);
		scanf("%d", &arr2[i]);

		}

		printf("\nValores introducidos en el segundo array:\n\n");
		for (int i = 0; i < numero2; ++i){

		printf("\tEn la posicion del array [%d]: %d\n", i + 1, arr2[i]);

		}

	int opcion;

	printf("\nIntroduzca una opcion:\n");
	printf("\t1) para sumar coordenada a coordenada\n");
	printf("\t2) para concratenar\n");
	printf("\t3) para salir\n");
	printf("\nHa introducido: ");
	scanf("%d", &opcion);

	switch(opcion){

	case 1:

	if(numero>numero2){

		int *arr3 = malloc(numero * sizeof(int));

		printf("\nEl valor del tamaño para el array 3 es de: %d\n\n", numero);

		for (int i = 0; i < numero; ++i){

		arr3[i] = arr[i] + arr2[i];
		
		printf("\tValor primer array [%d]: %d + Valor del segundo array [%d]: %d = Posicion del tercer array [%d] con valor: %d\n", i + 1, arr[i], i + 1, arr2[i],i + 1, arr3[i]);
	
		}

	}else if(numero2>numero){
		int *arr3 = malloc(numero2 * sizeof(int));

		printf("\nEl valor del tamaño para el array 3 es de: %d\n", numero2);


		for (int i = 0; i < numero2; ++i){

		arr3[i] = arr[i] + arr2[i];
		
		printf("\tValor primer array [%d]: %d + Valor del segundo array [%d]: %d = Posicion del tercer array [%d] con valor: %d\n", i + 1, arr[i], i + 1, arr2[i],i + 1, arr3[i]);
	
		}
	}



	break;

	case 2:

	int *arr3 = malloc((numero + numero2) * sizeof(int));

	for (int i = 0; i < numero; ++i){

		arr3[i] = arr[i];

		printf("Valor del primer array en la posicion[%d] : %d\n", i + 1, arr3[i]);

		}
		
	for (int i = 0; i < numero2; ++i){

		arr3[i] = arr2[i];

		printf("Valor del segundo array en la posicion[%d] : %d\n", i + 1, arr3[i]);

		}

	break;


	case 3:
	printf("Saliendo del programa...\n");
	break;

	default:
	printf("Has introducio un numero invalido\n");
	break;

	}

	free(arr);
	free(arr2);
	free(arr3);

	return 0;
}