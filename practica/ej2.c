#include <stdio.h>
#include <stdlib.h>

int main (){

	int numero;
	printf("Introduce un numero para saber si es par o impar");
	scanf("%d", &numero);

	if(numero % 2 == 0 ){
		printf("Es par\n");

	}else{ printf("Es impar\n");
		}

	return 0;
}
