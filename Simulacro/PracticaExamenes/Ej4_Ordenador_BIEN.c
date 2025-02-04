#include <stdio.h>
#include <stdlib.h>

int main(){

	int tamaño;
	printf("Introduce el un numero para reservar memoria: ");
	scanf("%d", &tamaño);
	if(tamaño <= 0){
		printf("Introduce un numero mayor o igual a 1\n");
		return 1;
	}

	double *valor = (double*)malloc(tamaño * sizeof(double));
	if(valor == NULL){
		printf("Error al reservar memoria\n");
		return 1;

	}

	for (int i = 0; i < tamaño; ++i){

	valor[i]= 1.0/(i+1);

	}

	for (int i = 0; i < tamaño; ++i){

	printf("Valor en [%d]: %f en la memoria %p\n", i+1, valor[i], &valor[i]);

	}

	////////////////////////////////////////
	printf("\n\n");

	double *valor2 = (double*)realloc(valor, (tamaño * 2) * sizeof(double));
	if(valor2 == NULL){
		printf("Error al reservar memoria\n");
		return 1;

	}

	for (int i = 0; i < tamaño * 2; ++i){

	valor2[i]= 1.0/(i+1);

	}

	for (int i = 0; i < tamaño * 2; ++i){

	printf("Valor en [%d]: %f en la memoria %p\n", i+1, valor2[i], &valor2[i]);

	}

	free(valor2);

	return 0;
}

/*
1. ¿Qué ocurre en la memoria cuando usamos realloc() para expandir un array?
Cuando usamos realloc(), el sistema operativo intenta ampliar el bloque de memoria existente. Si hay suficiente
 espacio contiguo, realloc() extiende el bloque sin moverlo. Si no hay espacio suficiente, asigna un nuevo bloque más grande, copia los 
 datos del bloque original y libera el anterior.

¿Se conservan los valores anteriores?
Sí, si realloc() debe mover la memoria a una nueva ubicación, copia los valores antiguos al nuevo bloque antes de 
liberar la memoria anterior. Sin embargo, si realloc() falla y devuelve NULL, los datos originales se pierden si no se almacena 
una referencia al bloque viejo antes de la reasignación.

¿Siempre se puede expandir en el mismo bloque de memoria o se busca un espacio nuevo obligatoriamente?
No siempre se puede expandir en el mismo bloque. Si el espacio contiguo está ocupado, el sistema asigna un nuevo 
bloque en otro lugar y mueve los datos allí.

Comprobación de direcciones de memoria:
En el código proporcionado, se pueden observar las direcciones de memoria antes y después de realloc() para ver si el bloque 
se mantiene o cambia. Si la dirección impresa después de realloc() es diferente, significa que se asignó un nuevo espacio de memoria.
*/