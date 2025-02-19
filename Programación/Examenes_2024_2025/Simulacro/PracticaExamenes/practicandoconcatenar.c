#include <stdio.h>
#include <stdlib.h>

int main(){

	int tamaño;
	printf("Intrduce el tamaño del array: ");
	scanf("%d", &tamaño);

	if (tamaño <= 0){
		printf("Error\n");
		return 1;
	}

	int *arr = (int*)malloc(tamaño * sizeof(int));
	if(arr == NULL){
		printf("ERROR\n");
		return 1;

	}

	for (int i = 0; i < tamaño; ++i){

	printf("Introduce el valor del array [%d]: ", i+1);
	scanf("%d", &arr[i]);

	}

	///////////////////////////////////////////////////////

	int tamaño2;
	printf("\nIntrduce el tamaño del segundo array: ");
	scanf("%d", &tamaño2);

	if (tamaño2 <= 0){
		printf("Error\n");
		return 1;
	}

	int *arr2 = (int*)malloc(tamaño2 * sizeof(int));
	if(arr2 == NULL){
		printf("ERROR\n");
		return 1;
	}

	for (int i = 0; i < tamaño2; ++i){

	printf("Introduce el valor del array [%d]: ", i+1);
	scanf("%d", &arr2[i]);

	}

	///////////////////////////////////////////////////////

	printf("\nValor 1º Array:\n");

	for (int i = 0; i < tamaño; ++i){

	printf("Valor de [%d]: %d\n", i+1, arr[i]);

	}

	printf("\nValor 2º Array:\n");

	for (int i = 0; i < tamaño2; ++i){

	printf("Valor de [%d]: %d\n", i+1, arr2[i]);
	}

	////////////////////////////////////////////////////////

	int opcion;
	printf("Menu:\n");
	printf("1) Sumar coordenadas\n");
	printf("2) Concatenar coordenadas\n");
	printf("Opcion: ");
	scanf("%d", &opcion);

	switch(opcion){

	case 1:

	if(tamaño > tamaño2){

	int *arr3 =(int*)malloc((tamaño)*sizeof(int));
	if(arr3 == NULL){
		printf("Error\n");
		return 1;
	}

	for (int i = 0; i < tamaño; ++i){

	arr3[i] = arr[i] + arr2[i];

	printf("Valor en [%d]: %d\n", i+1, arr3[i]);

	}
	free (arr3);
	}

	if(tamaño2 > tamaño){

	int *arr3 =(int*)malloc((tamaño2)*sizeof(int));
	if(arr3 == NULL){
		printf("Error\n");
		return 1;
	}

	for (int i = 0; i < tamaño2; ++i){

	arr3[i] = arr[i] + arr2[i];

	printf("Valor en [%d]: %d\n", i+1, arr3[i]);

	}
	free (arr3);
	}

	break;

	case 2:

	int *arr4 = (int*)malloc((tamaño + tamaño2)*sizeof(int));

	for (int i = 0; i < tamaño; ++i){
	arr4[i] = arr[i];
	printf("Valor en [%d]: %d\n", i+1, arr4[i]);
	}

	for (int i = 0; i < tamaño2; ++i){

	arr4[i+tamaño]=arr2[i];
	printf("Valor en [%d]: %d\n", tamaño+i+1, arr4[i]);
	}

	free(arr4);

	break;

	default:
	break; 

	}

	free (arr);
	free(arr2);

	return 0;
}