#include <stdio.h>
#include <stdlib.h>

int por_valor(int valor){

	valor += 10;

}

int por_referencia(int *valor){

	*valor += 10;

}

int main(){

	int tamaño;
	printf("Introduce el valor de la memoria: ");
	scanf("%d", &tamaño);

	int *arr = (int*)malloc(tamaño * sizeof(int));

	for (int i = 0; i < tamaño; ++i)
	{
		printf("Introduce los valores del array[%d]: ", i+1);
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < tamaño; ++i)
	{
		printf("Valores de [%d]: %d\n", i+1, arr[i]);
	}

	int valor = arr[tamaño -1];

	por_valor(valor);

	printf("Valor por por_referencia:%d\n", arr[tamaño -1]);

	por_referencia(&arr[tamaño - 1]);

	printf("Valor por_valor: %d\n", arr[tamaño - 1]);

	return 0;
}