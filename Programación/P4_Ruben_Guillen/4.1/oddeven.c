#include <stdio.h>
#include <stdlib.h>

int main(){

	int numero;
	printf("Introduce un numero entero para determinar si es par o impar: ");
	scanf("%d", &numero);

	if(numero % 2 == 0){
	printf("El numero es Par\n");
	}else{
	printf("El numero es Impar\n");
	}
	return 0;
}
