#include <stdio.h>
#include <stdlib.h>	
void es_vocal(char letra); 
void calcular_area_figura();
void calcular_promedio();

int main (){
	
	char opciones;

	printf("Selecciona una opcion:\n");
	printf("1.Verificar si es una Letra es vocal.\n");
	printf("2.Calcular el área de una figura (círculo o cuadrad\n");
	printf("3.Calcular el promedio de 3 o 4 números.\n");
	printf("4.Convertir una hora  en formato de 24 horas a 12 horas.\n");
	printf("5.Verificar si un número menor de 10 es primo.\n");
	printf("6.Comparar tres números.\n");
	printf("7.Salir.\n");
	printf("Opción: ");

	scanf("%c", &opciones);
	
	if(opciones == '1'){char letra;es_vocal(letra);
	}else if(opciones == '2'){calcular_area_figura();
	}else if(opciones == '3'){calcular_promedio();}

return 0;
}
void es_vocal(char letra){

	printf("Introduce una vocal: ");
	scanf(" %c", &letra); //tengoo que dejar un espacio delante del %c, porque si no salta de linea y no se ejecuta el numero 1. Pongo un espacio antes del c porque el ultimo scanf habra dejado en el bugger de entrada un carater \n que si no pongo el espacio se guardaria en la variable letra	
		
	if(letra == 'a'){
		printf("Es una vocal\n");
	}else if(letra == 'e'){
		printf("Es una vocal\n");
	}else if(letra == 'i'){
		printf("Es una vocal\n");
	}else if(letra == 'o'){
		printf("Es una vocal\n");
	}else if(letra == 'u'){
		printf("Es una vocal\n");
	}else{
		printf("No has introducido una vocal\n");
	}
}
void calcular_area_figura(){
	
	int numero;
	float radio, lado, resultado_lado, resultado_area;

	printf("Introduce la figura que quieras calcular (círculo = 1, cuadrado = 2) ");
	scanf("%d", &numero);

	switch(numero){

		case 1:
		printf("Introduce el radio del círculo: ");
		scanf("%f", &radio);

		resultado_area = 3.14159 * radio * radio;

		printf("El area del círculo con area %.2f es: %f\n", radio, resultado_area);
		break;

		case 2:
		printf("Introduce el lado del cuadrado: ");
		scanf("%f", &lado);

		resultado_lado = lado * lado;

		printf("El area del cuadrado con lado %.2f es: %f\n", lado, resultado_lado);
		break;

		default:
		printf("Error\n");
}

}

double calcular_promedio_dos_num(double num1, double num2){

	return (num1 + num2) / 2;
}

void calcular_promedio(){
	
	int numero;
	double num1, num2;
	
	printf("De cuántos números quiere hacer el promedio? (2, 3 o 4): ");
	scanf("%d", &numero);

	switch(numero){
		
		case 2:
		printf("Introduzca el primer número: ");
		scanf("%lf", &num1);
		printf("Introduzca el segundo número: ");
		scanf("%lf", &num2);
		
		printf("El promedio de %lf, %lf es %lf\n", num1, num2, calcular_promedio_dos_num(num1, num2));
		break;

		default:
		printf("Error\n");
		break;
	}
		
}











//























