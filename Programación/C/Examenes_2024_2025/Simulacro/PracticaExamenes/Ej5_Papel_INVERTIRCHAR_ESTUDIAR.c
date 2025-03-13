#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* invertir(char *palabra) {
    int longitud = strlen(palabra);  
    char *invertida = (char*) malloc((longitud + 1) * sizeof(char));  

    if (invertida == NULL) {  
        printf("Error al reservar memoria\n");
        return 1;  
    }

    for (int i = 0; i < longitud; i++) {
        invertida[i] = palabra[longitud - 1 - i];  
    }

    invertida[longitud] = '\0';  

    printf("Palabra invertida: %s\n", invertida);

    return invertida;  
}

int main() {
    int tamaño;

    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

    if (tamaño <= 0) {
        printf("Introduce un número entero positivo válido\n");
        return 1;  
    }

    char *palabra = (char*) malloc((tamaño + 1) * sizeof(char));

    if (palabra == NULL) {  
        printf("Error al reservar memoria\n");
        return 1;  
    }

    printf("Introduce una palabra: ");
    scanf("%s", palabra);  // Leer la palabra

    printf("Palabra original: %s\n", palabra);

    char *palabra_invertida = invertir(palabra);

    free(palabra);
    free(palabra_invertida);

    return 0;
}
