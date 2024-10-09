#include <stdio.h>
#include <stdlib.h>

int main() {

	float numero1, numero2;
        int resultado_resta, resultado_suma, resultado_division, resultado_multiplicacion;
	printf("Introduce el primer numero entero o decimal =");
	scanf("%f", &numero1);
	
	printf("Introduce el segundo numero entero o decimal =");
	scanf("%f", &numero2);
	
	resultado_resta = numero1 - numero2;
	printf("El resultado de la resta es = %d\n", resultado_resta);
	
	resultado_suma = numero1 + numero2;
	printf("El resultado de la suma es = %d\n", resultado_suma);

	resultado_division = numero1 / numero2;
	printf("El resultado de la division es = %d\n", resultado_division);

	resultado_multiplicacion = numero1 * numero2;
	printf("El resultado de la multiplicacion es = %d\n", resultado_multiplicacion);

	return 0;
}
