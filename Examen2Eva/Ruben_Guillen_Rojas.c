/*


IMPORATANTE: ME HE CONFUNDIDO Y HE USADO MODIFICAR_POR_REFERENCIA PARA PASAR POR VALOR Y VICEVERSA, NO ME DA TIEMPO A CAMBIARLO 11:20



*/

#include <stdio.h>
#include <stdlib.h>

void modificar_elemento(int arr, int valor, int tamaño);
void modificar_por_referencia(int tamaño, int *arr);

int main(){

//1

int tamaño;

printf("Introduce un numero entero positivo para asignar a la memoria dinamica: ");
scanf("%d", &tamaño);

if(tamaño < 0){
	printf("Has introducido un numero invalido\n");
}

//2

int *arr = malloc(tamaño * sizeof(int));

//3


for (int i = 0; i < tamaño; ++i){



	printf("Introduzca un numero entero y positivo para el valor de la memoria [%d]: ", i + 1);
	scanf("%d", &arr[i]);

		if(tamaño < 0){
		printf("Has introducido un numero invalido\n");
		}

}

for (int i = 0; i < tamaño; ++i){

	printf("\nLos datos introducidos son ");
	printf("Memoria [%d]: %d", i + 1, arr[i]);

}

printf("\n\n");

//5

printf("\tModificar por referencia, valores: \n\n");

for (int i = 0; i < tamaño; ++i){

	printf("Memoria [%d]: %d\n", i + 1, arr[i]);


	}


printf("\n\tValores por referencia con punteros:\n\n");

modificar_por_referencia(tamaño, arr);

//4

printf("\n\tValores por valor: \n\n");

printf("\n\nValor inicial: \n");

for (int i = 0; i < tamaño; ++i){

	printf("\nLos datos introducidos son ");
	printf("Memoria [%d]: %d", i + 1, arr[i]);

}

int valor;
printf("\n");
printf("\nIntroduce un numero para sumarlo a los arrays: ");
scanf("%d", &valor);

if(valor < 0){
		printf("Has introducido un numero invalido\n");
		}



modificar_elemento(*arr, valor, tamaño);

printf("\n\n\tCOMPARACION: \n\n");

printf("\nPOR VALOR: \n");

modificar_por_referencia(tamaño, arr);

printf("\nPOR REFERENCIA: \n");

modificar_elemento(*arr, valor, tamaño);

printf("\n");

free(arr);
return 0;
}


void modificar_por_referencia(int tamaño, int *arr){

	for (int i = 0; i < tamaño; ++i){

	printf("Memoria con punteros [%d]: %d\n",i + 1, arr[i]);

	}

}

void modificar_elemento(int arr, int valor, int tamaño){


	arr = valor + tamaño;

	for (int i = 0; i < tamaño; ++i){

	printf("Memoria con punteros [%d]: %d\n",i + 1, arr);

	}

}

// 1
//Explica lo que pasa:
//Cuando paso por valor, la variable cambia unicamente en el void, por lo que en el main seguira siendo el mismo valor, si valor = 1 y en el void es = 2, en el main sera 1

//Cuando paso por referencia, la variable con puntero cambia globalmente, es decir modifica la variable en el void y la pasa tambien al main.


// 2
//Ocupa 4 bytes, se puede calcular con un sizeof(double) -> double *arr = malloc(10 * sizeof(double))