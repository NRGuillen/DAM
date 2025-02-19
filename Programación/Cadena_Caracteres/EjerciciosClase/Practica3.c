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

// EJERCICIO RESUELTO POR PROFEROR
//
// int main(){
//	
//	char str1[8] = "iguales"; 
//	char str2[8] = "iguales";
//	char str3[8];
//	
//	//son distintas porque las memorias en tienen almacenado las palabras
//	 en distintas posiciones de las memorias y al compararla no estan en el mismo sitio por ejemplo
//  	i g u a l e s
//          	i g u a l e s
//
//	if(str1 == str2){
//		printf("Son iguales");
//	}else
//		pintf("Son distintas");
//	}
//	
//	//str1 es mayo porque str1 se guarda en la memoria antes que str2 esto no suele occurrir
//	siempre pero es lo normal
//
//	if (str1 < str2){
//		printf("str1 es menor\n");
//	}else{
//		printf("str2 es menor\n");
//	}
//
//	for (int i = 0; i<8; i++){
//		if(str1[i] == str2[i]){
//			printf("%c", str1[i]);
//		}
//	}
//
//	ESTA ASIGNACION NO ESTA PERMITIDA
//
//	str3 = str1;
//	str1[0] = 'I';
//	printf("c", str3[0]);
//	
//
// return 0;
// }
