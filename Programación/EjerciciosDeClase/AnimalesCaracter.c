#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char dibujo[5];
	
	printf("Introduce que dibujo quieres ver (perro o gato)");
	scanf("%s", dibujo;

	if(dibujo if (dibujo[0] == 'g' && dibujo[1] == 'a' && dibujo[2] == 't' && dibujo[3] == 'o' && dibujo[4] == '\0') {
        printf("  /^ ^\\\n");
        printf(" / 0 0 \\\n");
        printf(" V\\ Y /V\n");
        printf("  / - \\\n");
        printf(" /    |\n");
        printf("V__) ||\n");
    } else if (dibujo[0] == 'p' && dibujo[1] == 'e' && dibujo[2] == 'r' && dibujo[3] == 'r' && dibujo[4] == 'o' && dibujo[5] == '\0') {
        printf("   __\n");
        printf("o-''|\\_____/)\n");
        printf(" \\_/|_)     )\n");
        printf("    \\  __  /\n");
        printf("    (_/ (_/\n");
    } else {
        printf("No has introducido ni gato ni perro\n");
    }

    return 0;
    }
