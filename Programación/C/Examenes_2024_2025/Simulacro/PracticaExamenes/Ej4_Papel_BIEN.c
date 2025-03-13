#include <stdio.h>
#include <stdlib.h>
	

int main(){

	int tamaño;

	printf("Introduce el tamaño del array: ");
	scanf("%d", &tamaño);

	if(tamaño < 0){
		printf("Introduce un numero valido, entero y positivo\n");
		return 1;
	}

	int *arr = (int*) malloc(tamaño * sizeof(int));
	if(arr == NULL){
		printf("Error al reservar memoria\n");
		return 1;
	}

	for (int i = 0; i < tamaño; ++i){

	printf("Introduce los valores para el array en la posicion [%d]: ", i+1);
	scanf("%d", &arr[i]);

	}

	printf("\n\n");

	for (int i = 0; i < tamaño; ++i){

	printf("El valor de la posicion [%d] es: %d\n", i+1, arr[i]);

	}	

	free(arr);

	return 0;
}