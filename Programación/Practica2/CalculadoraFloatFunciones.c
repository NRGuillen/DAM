#include <stdio.h>
#include <stdlib.h>

float sumar(float a, float b){

	return a + b;
}

float resta(float a, float b){

	return a - b;
}

float dividir(float a, float b){

	return a / b;
}

float multiplicacion(float a, float b){

	return a * b;
}

int main (){

	float numero1, numero2;

		printf("Introduce el primer numero decimal o entero que quieras calcular: ");
		scanf("%f", &numero1);
		
		printf("Introduce el segundo numero decimal o entero que quieras calcular: ");
		scanf("%f", &numero2);
		

		float resultadoSuma = sumar(numero1, numero2);
		float resultadoResta = resta(numero1, numero2);
		float resultadoDivision = dividir(numero1, numero2);
		float resultadoMultiplicacion = multiplicacion(numero1, numero2);

		printf("El resultado de la suma es: %.2f\n", resultadoSuma);
		printf("El resultado de la resta es: %.2f\n",resultadoResta);
		printf("El resultado de la division es: %.2f\n", resultadoDivision);
		printf("El resultado de la multiplicacion es: %.2f\n", resultadoMultiplicacion);












	return 0;
}
