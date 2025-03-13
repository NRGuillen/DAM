#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char str1[4] = "hola";
	printf("%s\n", str1);
	printf("%c\n", str1[3]); //imprime el cuarto caracter, porque se empieza a contar en 0- str1[0] = 'h'.

	printf("%d\n", str1[4]);
	str1[4] = '$';//elimina el \0 y se sigue imprimiendo hasta que haya un \0 en la memoria.

	printf("%s\n", str1);


	return 0;
}
