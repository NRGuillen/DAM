#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0;

	i = i+1
	printf("%d\n", i); //vale 1
	
	i +=1; //incrementa en 1
	printf("%d\n",i); //2
	
	i +=3; //incrementa en 3
	printf("%d\n",i); // 5 (2+3)

	i -= 5; //Decrementa en 5 
	printf("%d\n",i); //0 (5-5)

	i++; //i+= 1; i = i +1 Son 3 formas equivalentes
	     //
	printf("%d\n", i); //1
	i--; // i-=1 ; i= i- 1
	printf("%d\n", i); //0
			   //
	//NIVEL AVANZADO
	//
	
	printf("Nivel avandado: \n");
	printf("%d\n", i++); // 0 porque incrementa despues de leer el valor	
			     // 
	printf("%d\n", i); // 1
	printf("d\n", ++1); // 2 porque primero incrementa y despuies devuelve el valor.
			    //
			    // analoggamente ocurre con i--; --i;
	return 0;
}
