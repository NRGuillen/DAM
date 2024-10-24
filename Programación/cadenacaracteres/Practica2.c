#include <stdio.h>
#include <stdlib.h>

int main(){

	char a[11];
	
	//Ponemos una cadena de caracteres de 11 para que haya espacio si intoducen una cadena de 10, y se pueda imprimir nuestro \0

	int caracteres;
	printf("Escribe una palabra de no mas de 10 caracteres: ");
	scanf("%s", a);

	printf("¿Cuantos caracteres tiene tu palabra? ");
	scanf("%d", &caracteres);

	a[10] = '\0';

	//Si el usuario ha introducido una cadena de 10 caracteres el decimo (en este caso el ultrimo) sera un \0 que cierra la cadena

	printf("%s\n", a);

										
										
	return 0;
}
