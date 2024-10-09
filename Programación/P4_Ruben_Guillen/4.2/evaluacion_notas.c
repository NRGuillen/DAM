#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaro la variable calificacion
	int calificacion;
	
	//Escanea la variable, que en este caso seria un numero
	printf("Introduce la calificacion: ");
	scanf("%d", &calificacion);
	
	//(calificacion >=5) es como decir si el scanf es igual o mayor a 5 es verdadero, verdadero en este caso se llama "Aprobado" y falso "Suspenso"
	printf("Resultado: %s\n", (calificacion >= 5) ? "Aprobado" : "Suspendido");

	return 0;

}

