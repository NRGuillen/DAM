#include <stdio.h>
#include <stdlib.h>

int main(){

	char a[10];
	int caracteres;
	printf("Escribe una palabra de no mas de 10 caracteres: ");
	scanf("%s", a);

	printf("¿Cuantos caracteres tiene tu palabra? ");
	scanf("%d", &caracteres);

	caracteres[10] = '\0';

	printf("%s\n", a);

	
	
	

return 0;
}
