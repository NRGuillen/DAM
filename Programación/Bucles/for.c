#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//bucle repite una linea
	
	int i = 0;
	
	//** for (*valor inicial;Condicion;(Codigo a ejecutar entre vueltas)
	
	
	for(i = 0; i<5; i = i +1){
		
	printf("%d", i);
	}

	/**
	1) primero inicializo i=0
 	2) compruebo si i<5. Como se cumple, ejecuto el interiror del bucle
	3) printf
	4) Terminado el interior del bucle, ejecuto el "codigo entre vueltas": i=i+1
	5) Vuelvo al punto 2. Compuerbo si i<5. Se cumple porque i == 1. Ejecuto el interior
	6) printf
	7) Terminando el interior del bucle, ejecuto i=i+1. Ahora i vale 2.	
	8) cuando i vale 2 vuevlo a la condicion ¿i<5? Si. Interior del bucle.
	9) printf
	10) Terminando el interior del bucle, ejeuto i=i+1. Ahora i vale 3.
	11) Compruebo la condicion. ¿i<5?. Si. Ejecuto interior del bucle. 
	12)
	13)i vale 4 
	14) ¿i<5? Si. Interior del bucle 
	15)
	16)i vale 5
	17) ¿i<5? No. Salimos del bucle.
	**/
	return 0;
}
