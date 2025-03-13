#include <stdio.h>
#include <stdlib.h>

modificar_elemento(int valor){

	valor += 10;
}

modificar_por_referencia(int *valor){

	valor += 10;
}

int main(){

	int tamaño;
	printf("Introduce el tamaño del array: ");
	scanf("%d", &tamaño);

	int *arr=(int*)malloc(tamaño*sizeof(int));

	for (int i = 0; i < tamaño; ++i){

	printf("Introduce un valor para el array [%d]: ", i + 1);
	scanf("%d", arr[i]);

	}

	printf("\n\n");

	for (int i = 0; i < tamaño; ++i){

	printf("Valor [%d]: %d\n", i + 1, arr[i]);

	}

	modificar_elemento = modificar_elemento(valor - 1 -i);

	printf("Por valor: %d", valor);

	return 0;
}