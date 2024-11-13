#include <stdio.h>
#include <stdlib.h>

//EJEMPLO DE PASO DE UN ARGUMENTO A UNA FUNCION POR VALOR

	void incrementar(int n){
		printf("Valor recibido: %d\n", n);
		n++;
		printf("Valor incrementado en la funcion: %d\n", n);
}
	int main(){
		int valor = 10;
		incrementar(valor); //Le estoy dando el valor 10, no la variable
		printf("Valor: %d\n", valor); //Imprime un 10 
	
	return 0;
}

