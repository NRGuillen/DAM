#include <stdio.h>
#include <stdlib.h>	
#include <math.h>

//declaro todas las funciones que luego llamaremos en el main para hacer los calculos

int es_mayuscula(char letra);
void calcular_factorial();
int encontrar_maximo(int num1, int num2);
double convertir_celsius_a_fahrenheit(double celsius);
void intercambiar_numeros();
double calcular_potencia(double base, int exponente);

int main (){
	
	//declaro opciones que sera el numero que introduzca para seleccionar una opcion 1-7
	
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
	
	//se escanea el numero que hemos puesto
	
	scanf("%d", &opciones);
	
	//se selecciona un caso dependiendo del numero que seleccionemos

	switch(opciones){
		case 1:{ 
	
		//se declara letra, para el scanf y se llama a la funcion es_mayuscula, que es la que realizara los calculos en una funcion aparte de int.

		char letra;
		
		printf("Introduce un carácter: ");
		scanf(" %c", &letra);
		
		es_mayuscula(letra);
		
	break;
	}	
		//se declara numero para el scanf y se llama a la funcion calcular_factorial fuera del main

		case 2:{
		
		int numero;
	
		printf("Intoruce un número entero positivo: ");
		scanf("%d", &numero);

		calcular_factorial();

	break;
        }
	
		//se declaran 2 variables num1 y numb2 para calcular con esos numeros en la funcion encontrar_maximo(num1,num2)

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

		// se declaran 2 variables para cacular con esos numeros en convertir_celsius_a_fahrenheit
		case 4:{

		double celsius, fahrenheit;

		printf("Introduce la temperatura en Celsius: ");
		scanf("%lf", &celsius);

		fahrenheit = convertir_celsius_a_fahrenheit(celsius);
	
		printf("La temperatura en Fahrenheit es:%.2lf\n", fahrenheit);
	
	break;
	}
		
		//declaro 2 variables para calcular con esos numeros en intercambiar_numeros

		case 5:{
		
		float num1, num2;

		printf("Introduce el primer número: ");
		scanf("%f", &num1);
		printf("Introduce el segundo número: ");
		scanf("%f", &num2);

		intercambiar_numeros;

		printf("Después de intercambiar, el primer número es el %.2f, el segundo número es el %.2f\n", num2, num1);
	break;
       }

		//declaro en double base, resultado (me lo pide el ejercicio) y el exponente para calcularlo en calcular_potencia(base,exponente)

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
		case 7:{

		printf("Saliendo del programa...\n");
		return 0;
	}
	
		default:{
		printf("Opcion no valida.\n)");
		break;
	}
}
return 0;
	}

int es_mayuscula(char letra){
		
	//este codigo se leeria como si la letra esta entre la A mayuscula y la Z mayuscula la letra es mayuscula, y viceversa pero con minusculas y si no es una letra daria error

	if(letra >='A' && letra <= 'Z'){
	printf("El carácter %c es una mayúscula\n", letra);
	return 1;
	}else if(letra >='a' && letra <= '<'){
	printf("El carácter %c es una minuscula\n", letra);
	return 0;
	}else{
	printf("No has introducido una letra\n");
	}
	}
void calcular_factorial(){
//no se como expresar la formula factorial para que calcule un numero entero, y lo que he buscado por internet son cosas que no hemos dado todavia y no comprendo realmente como funcionan.
printf("A espera de explicacion en clase\n");
}

int encontrar_maximo(int num1, int num2){

	if(num1 > num2){
	return num1;
	}else if(num1 < num2){
	return num2;
	}else{
	printf("Error\n");

	}	 
}

//retorna una multiplicacion simple

double convertir_celsius_a_fahrenheit(double celsius){
	
	 return celsius * 1.8 + 32;

}

void intercambiar_numeros() {
//No se si se puede hacer lo que he hecho, pero basicamente no necesito hacer nada aqui porque he intercambiado las variables num2,num1 en el ultimo printf, por lo que lo que hayas puesto en numero 1 ahora iria en el 2 y viceversa.
}
	

double calcular_potencia(double base, int exponente){

	//seria como decir: si el exponente es un 0 el resultado siempre sera un 1. Realmente no entiendo muy bien el codigo he tenido que buscarlo pero con pow seria muchisimo mas simple y te lo he dejado abajo.

	         if (exponente == 0) {
	         return 1.0;
	         }
	       
	         return base * calcular_potencia(base, exponente - 1);
	                             }

	//return pow(base, exponente); // al usar la libreria de math hay que añadir un -lm al final de gcc.

