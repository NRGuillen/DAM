#include <stdio.h>

int main() {

	char opcion;
	
	printf("¿Que quieres un gato o un perro? (g para gato, p para perro): ");
	scanf(" %c", &opcion);

	if(opcion == 'g'|| opcion == 'G' ){
		   printf(" /\\_/\\\n");
		   printf("( o.o )\n");
		   printf(" > ^ <\n");
	}

	else if(opcion == 'p' || opcion == 'P'){
		     printf(" / \\__\n");
	             printf("(    @\\___\n");
	             printf(" /         O\n");
	             printf("/   (_____/\n");
		     printf("/_____/   U\n");
	}
	else{
		printf("No has introducido ni g ni p");
	}
	
	return 0;

}
	

