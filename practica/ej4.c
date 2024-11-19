#include <stdio.h>
#include <stdlib.h>

int main (){

	int edad;
	printf("Introduce tu edad: ");
	scanf("%d", &edad);

	if(edad >= 0 && edad <= 13){
		printf("Categoria: Niño\n");
	}else if(edad >=14 && edad <=17){
		printf("Categoria: Adolescente\n");
	}else if(edad >=18){
		printf("Categoria: Adulto\n");
	}else{
		printf("Introduce un numero valido\n");
	}
	return 0;
}
