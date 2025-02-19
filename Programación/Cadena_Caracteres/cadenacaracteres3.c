#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char str1[100];
	char str2[100];

	printf("Introduce una palabra: ");
	scanf("%s", str1);// no hace falta & el porque la variable marca la direccion de la cadena en la memeoria y no hace falta mas informacion. 
	scanf("%s", str2);//este scanf esta por si haces un espacio en la frase.
	printf("%s%s\n", str1, str2);

	return 0;
}
