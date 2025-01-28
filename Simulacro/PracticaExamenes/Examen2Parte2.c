#include <stdio.h>
#include <stdlib.h>

int main(){

	int mem;

	printf("Ingresa un numero que determine el tamaño del array: ");
	scanf("%d", &mem);

	if(mem < 0){
		printf("No puedes asignar un numero negativo.\n");
		return 1;
	}

	double *arr = malloc(mem * sizeof(double));

	if(arr = NULL){
		printf("No se a podido asignar memoria.\n");
		return 1;
	}

	for (int i = 0; i < mem; ++i){

	arr[i] = 1/(i+1);

	printf("Valor del array: %f\n", arr[i]);

	}

	return 0;
}