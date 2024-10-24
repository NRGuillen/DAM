#include <stdio.h>
#include <stdlib.h>

int main(){
	
	for(int i = 0; i<=18; i+= 2){
		
		//al ser 0 hay que poner i+'=' para que no haya un bucle de 0

	printf("%d, ", i);
	}
	
	for(int i = 20; i<=20; i+= 2){

	printf("%d.\n", i);
	}

	printf("Cadena terminada\n");
	
	return 0;
}

//* Solcuion del profesor
//
//	for(int i = 0; i<21, i++){ 	//20 vueltas
//		if(i%2== 0) 
//			printf("%d," ,i);
//
//		
//
//
//
//		Es mas eficiente el segundo
//	
//		for(int i = 0; i<21; i+=2  	// 10 vueltas
//		printf("%d,",i);
//
//		if(i<20){
//			printf("%d,", i);
//		}else{
//			printf("%d.", i);
//			}
//		}
//
//		
//
//		Solucion B 
//		
//		int i = 0;
//		for (i=0; i<19; i+=2){
//			printf("%d,", i);
//			}
//		//Al salir del bucle, i vale 20
//		printf("%d.", i);
//
//
