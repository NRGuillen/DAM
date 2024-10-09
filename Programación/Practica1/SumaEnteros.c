#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int numero1, numero2, resultado_suma, resultado_resta, resultado_multiplicacion, resultado_division;
	
	printf("Introduzca el primer número entero que quieras calcular: ");
	scanf("%d", &numero1);
	
	printf("Introduza el segundo número entero que quieras calcular: ");
	scanf("%d", &numero2);

	resultado_suma  = numero1 + numero2;

	printf("Resultado de la suma: %d\n", resultado_suma);

	resultado_resta = numero1 - numero2;
	printf("Resultado de la resta: %d\n", resultado_resta);

	resultado_division = numero1 / numero2;
	printf("resultado de la division: %d\n", resultado_division);

	resultado_multiplicacion = numero1 * numero2;
	printf("resultado de la multiplicacion: %d\n", resultado_multiplicacion);

		return 0;







}
