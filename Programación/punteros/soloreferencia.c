#include <stdio.h>
#include <stdlib.h>

//EJEMPLO DE PASO DE UN ARGUMENTO A UNA FUNCION POR VALOR

//Quiero que realmente incremente la variable dada como argumento.

	void incrementar(int *n){
		printf("Valor recibido: %d\n", *n);
		//(*n)++;
	
		*n = *n + 1;

		printf("Valor incrementado en la funcion: %d\n", *n);
}
	int main(){
		int valor = 10;
		incrementar(&valor); 
		printf("Valor en el main: %d\n", valor); //la funcion incrementar recibe la memoria
							 //"10", el cambio del 10 al 11 es para 
							 //siempre 
	
	return 0;
}

