#include <stdio.h>
#include <stdlib.h>	
#include <math.h>

int es_mayuscula(char letra);
void calcular_factorial();
int encontrar_maximo(int num1, int num2);
double convertir_celsius_a_fahrenheit(double celsius);
void intercambiar_numeros();
double calcular_potencia(double base, int exponente);

int main (){
	
	int opciones;

	printf("Selecciona una opcion:\n");
	printf("1.Verificar si un carácter es mayúcula.\n");
	printf("2.Calcular el factorial de un número.\n");
	printf("3.Encontrar el máximo de dos números.\n");
	printf("4.Convertir grados Celsius a Fahranheit.\n");
	printf("5.Intercambiar dos números.\n");
	printf("6.Calcular la potencia de un número.\n");
	printf("7.Salir.\n");
	printf("Opción: ");

	scanf("%d", &opciones);
	
	switch(opciones){
		case 1:{ 
		
		char letra;
		
		printf("Introduce un carácter: ");
		scanf(" %c", &letra);
		
		es_mayuscula(letra);
		
	break;
	}	

		case 2:{
		
		int numero;
	
		printf("Intoruce un número entero positivo: ");
		scanf("%d", &numero);

		calcular_factorial();

	break;
        }
	
		case 3:{

		int num1, num2;
		
		printf("Introduce el primer número: ");
		scanf("%d", &num1);
		printf("Introduce el segundo número: ");
		scanf("%d", &num2);

		int maximo = encontrar_maximo(num1, num2);
		
		printf("El número maximo entre %d y %d es:%d\n", num1, num2, maximo);

	break;
        }

		case 4:{

		double celsius, fahrenheit;

		printf("Introduce la temperatura en Celsius: ");
		scanf("%lf", &celsius);

		fahrenheit = convertir_celsius_a_fahrenheit(celsius);
	
		printf("La temperatura en Fahrenheit es:%.2lf\n", fahrenheit);
	
	break;
	}

		case 5:{
		
		float num1, num2;

		printf("Introduce el primer número: ");
		scanf("%f", &num1);
		printf("Introduce el segundo número: ");
		scanf("%f", &num2);

		intercambiar_numeros;

		printf("Después de intercambiar, el primer número es el %f, el segundo número es el %f\n", num2, num1);
	break;
       }

		case 6:{
		
		double base, resultado;
		int exponente;

		printf("Introduce la base: ");
		scanf("%lf", &base);
		printf("Introduce el exponente: ");
		scanf("%d", &exponente);

		resultado = calcular_potencia(base, exponente);

		printf("%.2lf elevado a la %d es %.2lf\n", base, exponente, resultado);
		       
	break;
	}
return 0;
	}

int es_mayuscula(char letra){

	if(letra >='A' && letra <= 'Z'){
	printf("El carácter %c es una mayúscula\n", letra);
	return 1;
	}else{
	printf("El carácter %c no es una mayúscula\n", letra);
	return 0;
	}
}

void calcular_factorial(){
//no se como expresar la formula factorial para que calcule un numero entero, y lo que he buscado por internet son cosas que no hemos dado todavia
printf("A espera de explicacion en clase\n");
}

int encontrar_maximo(int num1, int num2){

	if(num1 > num2){
	return num1;
	}else if(num2 > num1){
	return num2;
	}
	else{
	printf("Error\n");

}
}

double convertir_celsius_a_fahrenheit(double celsius){

	 return celsius * 1.8 + 32;

}

void intercambiar_numeros() {
//No se si se puede hacer lo que he hecho, pero basicamente no necesito hacer nada aqui porque he intercambiado las variables num2,num1 en el ultimo printf, por lo que lo que hayas puesto en numero 1 ahora iria en el 2 y viceversa.
}
	


























