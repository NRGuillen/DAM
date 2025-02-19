#include <stdio.h>
#include <stdlib.h>

void valorInt(int *pNumero){

	printf("El valor de int es : %d con la direccion de memoria en %p", *pNumero, &pNumero);

}

void valorFloat(int *pNumero2){

	printf("El valor de int es : %d con la direccion de memoria en %p", *pNumero2, &pNumero2);
	
}

void valorChar(int *pString){

	printf("El valor de int es : %d con la direccion de memoria en %p", *pString, &pString);
	
	
}
	
int main(){

	int numero;
	float numero2;
	char string[10];

	int *pNumero = &numero;
	float *pNumero2 = &numero2;
	char *pString = string;

	printf("Introduce el valor del int: ");
	scanf("%d", &numero);

	valorInt(*pNumero);

	printf("Introduce el valor del float: ");
	scanf("%f", &numero2);

	valorFloat(*pNumero2)

	printf("Introduce el valor del string (10 caracteres maximo): ");
	scanf("%s", string);

	valorChar(*pString);



	return 0;
}