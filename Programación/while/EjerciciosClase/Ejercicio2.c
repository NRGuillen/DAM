#include <stdio.h>
#include <stdlib.h>

int main(){

	int opcion;
 	int opcion2; 
	int opcion3;
	int opcion4;

	printf("Introduce un numero entero positivo para sumar sus digitos: ");
	scanf("%d", &opcion);

	while(opcion > 99){
		
		opcion2 = opcion % 100;
		opcion3 = opcion2 % 10;
		
		
		printf("%d\n", opcion);
	}
	
	return 0;
}
