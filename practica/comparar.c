#include <stdio.h>
#include <stdlib.h>

int main (){

	float num1;
	float num2;

	printf("Introduce el primer numero: ");
	scanf("%f", &num1);

	printf("Introduce el segundo numero: ");
	scanf("%f", &num2);

	if(num1 > num2){
		printf("El numero mayor es %f", num1);

	}else if(num1 <num2){
		printf("el numero mayor es %f", num2);
	}else if(num1 == num2){
		printf("Ambos numeros son iguales");
	}else{
		printf("Error, solo es valido numeros");
	}

	return 0;
}
