#include <stdio.h>
#include <stdlib.h>

int main(){

	//Declaro la variable

	int numero;

	scanf("%d", &numero);

	if(numero >= 1){//Si el numero es mayor o igual a 1 es positivo
		printf("El número %d es positivo.\n", numero);
	}else if(numero <= -1){//Si el numero es menor o igual a  -1 es negativo
		printf("El número %d es negativo.\n", numero);
	}else if(numero == 0) {//Si el numero es igual a 0 printf
		printf("El número ingresado es cero.\n");
	}else{//Todo lo demas es un error
		printf("Error.\n");
	}
	return 0;
}
