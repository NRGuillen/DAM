#include <stdio.h>
#include <stdlib.h>

int main(){

	int numero, Niño, Adolescente, Adulto, Mayor;
	printf("Introduce el numero que quieres calificar como niño, adolescente, adulto o mayor: ");
	scanf("%d", &numero);

	if(numero <12){
	printf("Es menor\n");
	}else if(numero >=12 && numero <=17){
	printf("Es adolescente\n");
	}else if(numero >=18 && numero <=64){
	printf("Es adulto\n");
	}else if(numero >=65){
	printf("Es mayor\n");
	}
	return 0;
}
