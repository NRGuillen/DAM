#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char str1[4] = "hola";
	printf("%s\n", str1);
	printf("%c\n", str1[3]); //imprime el cuarto caracter, porque se empieza a contar en 0- str1[0] = 'h'
	
	str1[2] = '\0'; //El \0 para la ejecucion del codigo por ende solo se printeara ho
	//ho\0a
	printf("%s\n", str1);



	return 0;
}
