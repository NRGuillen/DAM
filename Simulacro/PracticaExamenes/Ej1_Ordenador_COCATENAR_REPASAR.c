#include <stdio.h>
#include <stdlib.h>

int main(){

	int tamaño, tamaño2;

	printf("Intrduce el tamaño del array: ");
	scanf("%d", &tamaño);
	if(tamaño <= 0){
		printf("Introduce un numero mayor o igual a 1\n");
		return 1;
	}

	int *arr = (int*)malloc(tamaño * sizeof(int));
	if(arr == NULL){
		printf("No se pudo reservar memoria\n");
		return 1;

	}

	for (int i = 0; i < tamaño; ++i){

	printf("Introduce el valor en el primer array [%d]: ", i+1);
	scanf("%d", &arr[i]);

	}

	for (int i = 0; i < tamaño; ++i){

	printf("Valor del array [%d]: %d\n", i + 1, arr[i]);

	}

	/////////////////////////////////////////////////////////////////////////

	printf("Intrduce el tamaño del segundo array: ");
	scanf("%d", &tamaño2);
	if(tamaño2 <= 0){
		printf("Introduce un numero mayor o igual a 1\n");
		return 1;
	}

	int *arr2 = (int*)malloc(tamaño2 * sizeof(int));
	if(arr2 == NULL){
		printf("No se pudo reservar memoria\n");
		return 1;

	}

	for (int i = 0; i < tamaño2; ++i){

	printf("Introduce el valor en el segundo array [%d]: ", i+1);
	scanf("%d", &arr2[i]);

	}

	for (int i = 0; i < tamaño2; ++i){

	printf("Valor del array [%d]: %d\n", i + 1, arr2[i]);

	}

	//////////////////////////////////////////////////////////////////////////
	int opcion;

	printf("Introduce una opcion del menu\n");
	printf("1) Sumar coordenads\n");
	printf("2) Concatenar arrays\n");
	printf("3) Salir\n");

	printf("Seleccion:");
	scanf("%d", &opcion);
	
	switch(opcion){

	case 1:

	if(tamaño > tamaño2){

	int *arr3 = (int*)malloc(tamaño * sizeof(int));
	if(arr3 == NULL){
		printf("No se pudo reservar memoria\n");
		return 1;

	}

		for (int i = 0; i < tamaño; ++i){

		arr3[i] = arr[i] + arr2[i];

		printf("Suma de %d + %d en la posicion [%d]: %d\n",arr[i], arr2[i], i + 1, arr3[i]);

		}	
	free(arr3);
	}else{

	int *arr3 = (int*)malloc(tamaño2 * sizeof(int));
	if(arr3 == NULL){
		printf("No se pudo reservar memoria\n");
		return 1;
	}

		for (int i = 0; i < tamaño2; ++i){

		arr3[i] = arr[i] + arr2[i];

		printf("Suma de %d + %d en la posicion [%d]: %d\n",arr[i], arr2[i], i + 1, arr3[i]);

		}
	free(arr3);

	}

	break;

	case 2:

	int *arr4 = (int*)malloc((tamaño + tamaño2) * sizeof(int));
	if(arr4 == NULL){
		printf("No se pudo reservar memoria\n");
		return 1;
	}

	 for (int i = 0; i < tamaño; ++i){
        arr4[i] = arr[i];
        printf("Valor del array [%d]: %d\n", i + 1, arr4[i]);
    }

    for (int i = 0; i < tamaño2; ++i){
        arr4[tamaño + i] = arr2[i];  // Aquí agregamos los elementos de arr2 después de arr
        printf("Valor del array [%d]: %d\n", tamaño + i + 1, arr4[tamaño + i]);
    }

    free(arr4);
	break;

	default: 
	printf("Introduce un numero valido\n");
	break;
	}

	free(arr);
	free(arr2);


	return 0;
}
