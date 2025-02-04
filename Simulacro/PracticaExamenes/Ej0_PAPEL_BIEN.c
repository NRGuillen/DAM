#include <stdio.h>
#include <stdlib.h>

int main(){

	int tamaño;

	printf("Introduce un numero para determinar el tamaño del array: ");
	scanf("%d", &tamaño);
	if(tamaño <= 0){
		printf("Introduce un numero mayor o igual a 1\n");
		return 1;
	}

	int *arr = (int*)malloc(tamaño * sizeof(int));
	if(arr == NULL){
		printf("No se ha podido reservar la memoria\n");
		return 1;
	}

	for (int i = 0; i < tamaño; ++i){

	printf("Introduce en valor de [%d]: ",i+1);
	scanf("%d", &arr[i]);

	}

	printf("\n\n");

	for (int i = 0; i < tamaño; ++i){

	printf("Valor de [%d]: %d\n", i+1, arr[i]);

	}


	free(arr);
	return 0;
}