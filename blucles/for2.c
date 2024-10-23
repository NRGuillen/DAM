#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//bucle repite una linea
	
	
	
	//** for (*valor inicial;Condicion;(Codigo a ejecutar entre vueltas)
	
	
	for(int i = 0; i<100; i = i + 2){
	//** Este bucle, asi escrito no imprmie el 100
	//en la ultima ejecucion del bucle i vale 98
	//Por tanto, al incrementar i, i vale 100
	//Y no cumple la condicion 
	
	//Para imprimir el 100 hay 2 posibilidades:
	//		i<= 100 en la condicion
	//		i<  101

	printf("%d", i);
	}

	printf("Terminado\n");

	return 0;
}
