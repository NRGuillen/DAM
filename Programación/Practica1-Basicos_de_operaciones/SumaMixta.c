#include <stdio.h>
#include <stdlib.h>

int main() {

	int numero1, numero2;
        float resultado_resta, resultado_suma, resultado_division, resultado_multiplicacion;
	printf("Introduce el primer numero entero =");
	scanf("%d", &numero1);
	
	printf("Introduce el segundo numero entero =");
	scanf("%d", &numero2);
	
	resultado_resta = numero1 - numero2;
	printf("El resultado de la resta es = %f\n", resultado_resta);
	
	resultado_suma = numero1 + numero2;
	printf("El resultado de la suma es = %f\n", resultado_suma);

	resultado_division = numero1 / numero2;
	printf("El resultado de la division es = %f\n", resultado_division);

	resultado_multiplicacion = numero1 * numero2;
	printf("El resultado de la multiplicacion es = %f\n", resultado_multiplicacion);

	return 0;
}

