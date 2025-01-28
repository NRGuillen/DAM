#include <stdio.h>
#include <stdlib.h>

//TERMINADO ARPOX EN 28MINUTOS SIN AYUDA EXTERNA

/*Parte 1 Ejercicio en papel Tiempo estimado: 20 minutos) (3 p.)
 Escriba un programa en C que realice las siguientes acciones:
Solicite al usuario un número entero positivo, el cual determinará el
tamaño de un array de enteros.
Cree un array con el tamaño especificado.
Solicite al usuario que ingrese los valores para llenar cada posición del
array.
Nota: No es necesario imprimir nada por pantalla durante la ejecución del
programa; solo se requiere la lectura de los datos. Se valorará la utilización
correcta de la memoria dinámica.
*/

int main(){

	int tamaño;

	printf("Introduce el tamaño del array: ");
	scanf("%d", &tamaño);

	int arr[tamaño];		
	int *pArr = arr;

	for (int i = 0; i < tamaño; ++i){

	printf("Introduce el valor [%d]: ", i + 1);
	scanf("%d", &pArr[i]);

	}

	printf("\n\n");

	for (int i = 0; i < tamaño; ++i){

	printf("Valor del array [%d] es de: %d con la memoria %p\n", i + 1, pArr[i], &pArr[i]);

	}

	return 0;
}