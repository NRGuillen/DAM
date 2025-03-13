#include <stdio.h>
#include <stdlib.h>

int contar_consonantes(char *palabra, int tamaño, int contador, int vueltas) {

    if (palabra[contador] == '\0'){
        return vueltas;
    }

    if(contador == tamaño){
    	return vueltas;
    }
        
    if( palabra[contador] != 'a' && palabra[contador] != 'A' && palabra[contador] != 'e' && palabra[contador] != 'E' && palabra[contador] != 'i' && palabra[contador] != 'I' && 
        palabra[contador] != 'o' && palabra[contador] != 'O' && palabra[contador] != 'u' && palabra[contador] != 'U' ){

    vueltas++;
}
    
    return contar_consonantes(palabra, tamaño, contador + 1, vueltas);
}

int main() {

    int tamaño, contador = 0, vueltas = 0;

    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

    char *palabra = (char *)malloc((tamaño + 1) * sizeof(char));

    printf("Introduce una palabra de no más de %d caracteres: ", tamaño);
    scanf("%s", palabra);

    printf("Consonantes: %d\n", contar_consonantes(palabra, tamaño, contador, vueltas));

    free(palabra);
    return 0;
}
