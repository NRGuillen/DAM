#include <stdio.h>
#include <stdlib.h>

int main(){

	float x = 10;
	int *p; //Genera un warning pero puedes ejercutarlo
	p = &x;

	printf("Valor de la variable: %f\n", x);
	printf("Direccion: %p\n", &x);
	printf("Valor apuntado: %d\n", *p); //La traduccion binaria de 0 y 1 de el primer printf

	return 0;
}
