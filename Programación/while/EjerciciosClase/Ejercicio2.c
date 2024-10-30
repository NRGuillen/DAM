#include <stdio.h>
#include <stdlib.h>

//RESULTADO DE PROFE

int main (){

	int numero, cociente, resto;

	printf("Introduce un numero: ");
	scanf("%d", &numero);
	
	do{ //!= Distinto
		cociente = numero / 10;
		resto += numero % 10;
		numero = cociente;
	}while (cociente != 0);

	printf("d\n", resto);

	return 0;
}


//int main(){

//	int opcion;
// 	int opcion2; 
//	int opcion3;
//	int opcion4;

//	printf("Introduce un numero entero positivo para sumar sus digitos: ");
//	scanf("%d", &opcion);

//	while(opcion > 99){
		
//		opcion2 = opcion % 100;
//		opcion3 = opcion2 % 10;
		
		
//		printf("%d\n", opcion);
//	}
	
//	return 0;
//}
