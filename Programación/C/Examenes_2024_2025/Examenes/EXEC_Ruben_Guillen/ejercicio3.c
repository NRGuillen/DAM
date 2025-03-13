#include <stdio.h>
#include <stdlib.h>

int main(){

	//declaro la variable numero

	int numero;

	scanf("%d", &numero);

	//si el numero es divisible entre dos es par y si no es impar.
	
	numero: numero % 2 ? printf("El número %d es impar.\n", numero) : printf("El número %d es par.\n", numero);

	return 0;
}
