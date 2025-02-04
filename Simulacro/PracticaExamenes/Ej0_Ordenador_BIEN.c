#include <stdio.h>
#include <stdlib.h>

int main(){

	int tamaño;
	printf("Introduce un numero para determinar el tamaño de la memoria: ");
	scanf("%d", &tamaño);
	if(tamaño <= 0){
		printf("El valor introducido tiene que ser mayor o igual a 1\n");
		return 1;
	}

	float *arr = (float*)malloc(tamaño * sizeof(float));
	if(arr == NULL){
		printf("No se ha podido reservar la memoria\n");
		return 1;
	}


	for (int i = 0; i < tamaño; ++i){

	arr[i] = (float)i/tamaño;

	printf("Posicion[%d]: %.1f en la memoria %p\n", i+1, arr[i], &arr[i]);

	}

//////////////////////////////////////////////////////////////
	printf("\n\n");

	float *arr2 = (float*)realloc(arr, (tamaño / 2) * sizeof(float));
	if(arr2 == NULL){
		printf("No se ha podido reservar la memoria\n");
	}

	for (int i = 0; i < tamaño/2; ++i){

	arr2[i] = (float)i/tamaño;

	printf("Posicion[%d]: %.1f en la memoria %p\n", i+1, arr2[i], &arr2[i]);

	}

	free(arr2);

	return 0;
}

/*
1. ¿Qué ocurre con los valores que ocupaban las posiciones que ya no forman parte del array?
Posiciones eliminadas: Los valores que ocupaban las posiciones de memoria eliminadas ya no son accesibles desde el array. 
Esto significa que, tras la llamada a realloc(), si el tamaño se reduce, las posiciones adicionales ya no contienen valores válidos.
Si accedes a esas posiciones después de la reducción, obtienes un comportamiento indefinido. No debes acceder a esas posiciones, 
ya que la memoria puede haber sido liberada o reusada por el sistema operativo.

2. ¿Siguen ahí?
No. La memoria para esas posiciones se considera "liberada" o "no asignada", y ya no se puede garantizar que los valores 
permanezcan ahí. Aunque podría ser que el sistema no sobrescriba inmediatamente esa memoria, el acceso a estas posiciones es incorrecto.

3. ¿Es correcto acceder a ellas?
No es correcto. Después de reducir el tamaño del array, las posiciones de memoria fuera del nuevo tamaño deben considerarse no válidas. Acceder a ellas podría causar errores en tiempo de ejecución o un comportamiento inesperado. Nunca debes acceder a memoria que ha sido liberada o que ya no forma parte de tu array.
*/