#include <stdio.h>
#include <stdlib.h>

//RESULTADO DE PROFE

int main (){

	int numero, cociente, resto;

	printf("Introduce un numero: ");
	scanf("%d", &numero);
	
	do{ //!= Distinto
		cociente = numero / 10;
		resto = resto * 10 + (numero % 10);
		numero = cociente;
	}while (cociente != 0);

	printf("d\n", resto);

	return 0;
}

