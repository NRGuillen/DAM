#include <stdio.h>
#include <stdlib.h>

int main (){
	
	//char declara variables matematicas
	//double declara numeros decimales con mayor presicion que float	
	char operacion;
	double numero1, numero2;
	
	//escanean el primer numero el sgundo y la operacion matematica
	printf("Introduce el primer numero\n");
	scanf("%lf", &numero1);
	printf("Introduce el segundo numero\n");
	scanf("%lf", &numero2);
	printf("Introduce el operado(+, -, *, /\n");
	scanf(" %c", &operacion);
	
	//switch permite ejecutar 1 bloque u otro bloque dependiendo del valor de la variable. Por ejemplo si uso '+' solo se ejecuta el primer bloque.
	//el .2 es para que solo tenga 2 decimales.
	switch(operacion){

	case '+':
	printf("%.2lf + %.2lf = %.2lf\n", numero1, numero2, numero1 + numero2);
	break;

	case '-':
	printf("%.2lf - %.2lf = %.2lf\n", numero1, numero2, numero1 - numero2);
	break;

	case '*':
	printf("%.2lf * %.2lf = %.2lf\n", numero1, numero2, numero1 * numero2);
	break;

	case '/':
	printf("%.2lf / %.2lf = %.2lf\n", numero1, numero2, numero1 / numero2);
	break;

	//si no ingresas +, -, / o * escribira "operador no valido"
	default:
	printf("Operador no valido\n");
	break;
	}
	
	return 0;
}
