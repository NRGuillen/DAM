#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int dia;

	printf("Introduce un número (1-7): ");
	scanf("%d", &dia);

	//switch lee el valor dia que escanea en scanf, el scanf se hace con %d porque solo quiero que haya numeros enteros.
	//Los casos significan el numero que introduces en el scanf, si introduces el 1, se ejecutara el case 1.

	switch(dia){

		case 1:
		printf("Resultado: Lunes\n");
		break;

		case 2:
		printf("Resultado: Martes\n");
		break;

		case 3:
		printf("Resultado: Miercoles\n");
		break;

		case 4:
		printf("Resultado: Jueves\n");
		break;

		case 5:
		printf("Resultado: Viernes\n");
		break;

		case 6:
		printf("Resultado: Sabado\n");
		break;

		case 7:
		printf("Resultado: Domingo\n");
		break;

		default:
		printf("Numero inválido\n");
		break;
	}

	return 0;
}

