#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int numeros = 0;
	int suma = 0;//le asignamos un numero por el que debe de empezar( 0 + 1, 0 + 2...)
	
	printf("Introduce un numero para sumar en bucle, si introduces un numero negativo parara el bucle dejara de sumar: ");	
	scanf("%d", &numeros);

	for(int numeros2 = 1; numeros2 <= numeros; numeros = numeros2++){
	
	suma += numeros2;

	}
	
	printf("La suma sucesiva de 1 + %d es:%d\n",numeros, suma);

	return 0;

}
	
