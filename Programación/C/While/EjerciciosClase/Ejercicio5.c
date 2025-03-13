#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//RESULTADO DE PROFE

int main (){

	int r;
	
	srand(time(NULL)); //semilla, la funcion time cambia cada segundo 

	for (int i = 0; i<4; i++){
		
		//srand(10); Esto provocaria que se calculara siempre el mismo numero aleatorio
		
		r = (rand() % 5) +1; 
		
		//da numeros aleatorios del resultado de todos los numeros posibles del resto del 8, 
		//1-2-3-4-5-6-7.
	
		//rand()%5 genera aleatorio entre 0 y 4 incluidos. Al sumar 1, consigo numeros aleatorios
		//entre 1 y 5.

		printf("%d\n", r);
	}

	return 0;
}

//contruir una funcion que calcule un numero aleatorio entre dos valores dados como argumento.
