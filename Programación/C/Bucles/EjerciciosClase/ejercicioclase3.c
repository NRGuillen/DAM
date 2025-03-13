#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int numeros = 0;
 	int suma = 0;// le da un valor por el que iniciar	

	for(numeros = 0; numeros <=10; numeros = numeros +1 ){
		printf("%d + %d = %d\n", suma, numeros, suma+numeros); //El printf se pone delante de la operacion para que lea primero la suma( seria el numero que da de resultado en la operacion anterior), luego lee el numero que sigue la cade de 1, 2, 3, 4, 5, 6, 7, 8, 9 y 10  y por ultimo da el resultado de la suma y el numero 
		suma += numeros;	
	}
	printf("La suma total es:%d\n", suma);
	
	return 0;
}

// SOLUCION PROFESOR
//#include <stdio.h>
//int main() {
//    	int suma = 0;
//      for (int i = 1; i <= 10; i++) {
//            suma += i;
//       }
//       printf("La suma es: %d\n", suma);
//       return 0;
//       }
