#include <stdio.h>
#include <stdlib.h>

//TERMINADO APROX EN 50 MINUTOS CON AYUDA DE CHATGPT EN arr[i] = (float)i / numero; pq no me dividia
//FALTA PASARLO A MEMORIA DINAMICA

/*Parte 2 Ejercicio en ordenador Tiempo estimado: 45 minutos) (5 p.)
Implemente un programa en C que realice las siguientes tareas:
 Solicite al usuario un número entero positivo que determinará el tamaño de
un array de números de punto flotante ( float ).
 Cree un array de float con el tamaño especificado.
 Rellene el array con valores comprendidos entre 0 y 1, de forma que cada
elemento sea inversamente proporcional a su posición en el array. Por
ejemplo, si el tamaño del array es 5, los valores serán:
Posición 0 0/5 0.0
Posición 1 1/5 0.2
Posición 2 2/5 0.4
Posición 3 3/5 0.6
Simulacro Examen 2
Posición 4 4/5 0.8
 Imprima en pantalla el contenido del array.
 Reduzca el tamaño del array a la mitad (puede redondear como desee).
 Imprima en pantalla el contenido del array tras reducir su tamaño.*/

int main(){

	int numero;

	printf("Introduce un numero entero: ");
	scanf("%d", &numero);

	float arr[numero];

	for (int i = 0; i < numero; ++i){

	arr[i] = i / numero; //	arr[i] = (float)i / numero;

	printf("Posicion %d: %d/%d = %.1f en la posicion de memoria %p\n", i, i, numero, arr[i], &arr[i]);

	}

	printf("\n\tMemoria divida a la mitad\n\n");

	for (int i = 0; i < numero / 2; ++i){

	arr[i] = i / numero; //	arr[i] = (float)i / numero;

	printf("Posicion %d: %d/%d = %.1f en la posicion de memoria %p\n", i, i, numero, arr[i], &arr[i]);

	}



	return 0;
}