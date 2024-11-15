#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int arr[5] = {1, 2, 3, 4, 5,};
	int *p = arr;

	//Recorrer el array y sumarlo
	
	//ESTE codigo daria un resultaod random
	//en la ultima vuelta debido a que se queda
	//sin tamaño

	//for(int *p = arr; *p <= 5 ;p++){
	//	printf("%d", *p);
	//}

	//Condicion para acabar el bucle, aqui
	//no acaba en 0

	int numElementos = sizeof(arr)/sizeof(int);

	for(int *p = arr; *p <= &arr[numElementos - 1]; p++){
		printf("%d", *p);
	}

	printf("Sizeof arr:%ld\n", sizeof(arr));
	printf("Sizeof int:%ld\n", sizeof(int));
	printf("Elementos del array: %ld\n", sizeof(arr)/sizeof(int));

	//LA condicion aqui acaba cuando sea \0
	//char acaba con \0

	char palabra[10] = "gratis";

	for (char *l = palabras; *l != '\0'; l++);{
			printf("%c", *l);
	}
	printf("\n");

	return 0;
}
