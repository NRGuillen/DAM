#include <stdio.h>
#include <stdlib.h>

int main (){

	int operacion;
	float num1;
	float num2;
	float resultado;

	printf("Introduce la operacion que quieras realizar 1 (para sumar) 2 (para restar) 3 (para multiplicar) 4 (para dividir): ");
	scanf("%d", &operacion);
	
	switch(operacion){
		
		case 1:
	
		printf("Introduce el primer numero a calcular: ");
		scanf("%f", &num1);

		printf("Introduce el segundo numero a calcular: ");
		scanf("%f", &num2);

		resultado = num1 + num2;

		printf("La suma entre %f y %f es: %f",num1, num2, resultado);
		
		break;

		case 2:

		printf("Introduce el primer numero a calcular: ");
		scanf("%f", &num1);
		
		printf("Introduce el segundo numero a calcular: ");
		scanf("%f", &num2);

		resultado = num1 - num2;

		printf("La resta entre %f y %f es: %f",num1, num2, resultado);

		break;

		case 3:

		printf("Introduce el primer numero a calcular: ");
		scanf("%f", &num1);

		printf("Introduce el segundo numero a calcular: ");
		scanf("%f", &num2);

	        resultado = num1 * num2;

		printf("La multiplicacion entre %f y %f es: %f",num1, num2, resultado);

		break;

		case 4:

		printf("Introduce el primer numero a calcular: ");
		scanf("%f", &num1);

		printf("Introduce el segundo numero a calcular: ");
		scanf("%f", &num2);

		resultado = num1 / num2;

		printf("La division entre %f y %f es: %f",num1, num2, resultado);

		break;

		default:
			
		printf("Error, introduzca un numero entre el 1-4\n");
	}
	

	return 0;
}
