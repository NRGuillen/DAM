#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero1, resultado_suma;
	char a = 'A';
	printf("Indica el numero que quieres sumar a la letra A: ");
	scanf("%d", &numero1);

	resultado_suma = a + numero1;

	printf("El resultado es: %c\n", resultado_suma);
	printf("El resultado es: %i\n", resultado_suma);

	return 0;

}
