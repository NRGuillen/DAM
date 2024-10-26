#include <stdio.h>
#include <stdlib.h>
//Libreria para poder usar el strcmp y comparar 2 cadenas de caracteres
#include <string.h>
int main(){
	
	char palabra1 [100];
	char palabra2 [100];

	printf("Introduce una palabra: ");
	scanf("%s", palabra1);

	printf("Introduce otra palabra: ");
	scanf("%s", palabra2);
	
	//Si hubiese puesto if(strcmp(palabra1 == palabra2) == 0) no hubiese valido debido a que estaria comparando 
	//las direcciones de memoria donde se guardan las cadenas y no estaria comparando las cadenas. Como son 2 
	//variables estan ubicadas en distintas memorias 
	//Y el == 0 representa que si las dos cadenas son iguales devuelva un 0 y el if se ejecute, de lo contrario 
	//devolvera otro numero si son distintas y ejecutara el else. 
	
	if(strcmp(palabra1,palabra2) == 0){
		printf("La palabra '%s' y '%s' son iguales\n", palabra1, palabra2);
	}else{
		printf("La palabra '%s' y '%s' no son iguales\n", palabra1, palabra2);
	}

	return 0;
}
