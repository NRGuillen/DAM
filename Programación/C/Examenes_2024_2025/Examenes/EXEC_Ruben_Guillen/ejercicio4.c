#include <stdio.h>
#include <stdlib.h>

int main (){
 
	// declaro variables e inicializo suma  a 0 para que cada vez que de la vuelta sea 0
        int num;
        int suma = 0;

        scanf("%d", &num);

	//Cuando i sea menor a numero incrementa
	
        for( int i = 1; i <= num; i++){

	//suma almacena y suma todos los numeros que incremente i
	
                suma += i;
        }
        printf("La suma de los primeros %d números es %d.\n",num, suma);

        return 0;
}
