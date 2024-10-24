#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int numeros = 0;
 	int multiplicacion = 1;// le da un valor por el que iniciar	

	for(numeros = 1; numeros <=10; numeros = numeros +=1 ){
		printf("%d * %d = %d\n", multiplicacion, numeros, multiplicacion*numeros);
		multiplicacion *=numeros;

	}
	
	return 0;
}
	
