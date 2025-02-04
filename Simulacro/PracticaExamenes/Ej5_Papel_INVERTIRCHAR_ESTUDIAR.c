#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* invertir(char *palabra) {
    int longitud = strlen(palabra);  // Longitud de la palabra
    char *invertida = (char*) malloc((longitud + 1) * sizeof(char));  // Reservar memoria para la palabra invertida

    if (invertida == NULL) {  // Verificar si hubo un error al reservar memoria
        printf("Error al reservar memoria\n");
        exit(1);  // Salir del programa si no se puede reservar memoria
    }

    for (int i = 0; i < longitud; i++) {
        invertida[i] = palabra[longitud - 1 - i];  // Asignar el carácter invertido
    }

    invertida[longitud] = '\0';  // Asegurar que la palabra invertida termine con '\0'

    printf("Palabra invertida: %s\n", invertida);

    return invertida;  // Devolver el puntero a la palabra invertida
}

int main() {
    int tamaño;

    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

    if (tamaño <= 0) {
        printf("Introduce un número entero positivo válido\n");
        return 1;  // Salir si el tamaño no es válido
    }

    char *palabra = (char*) malloc((tamaño + 1) * sizeof(char));

    if (palabra == NULL) {  // Verificar si hubo un error al reservar memoria
        printf("Error al reservar memoria\n");
        return 1;  // Salir si no se puede reservar memoria
    }

    printf("Introduce una palabra: ");
    scanf("%s", palabra);  // Leer la palabra

    printf("Palabra original: %s\n", palabra);

    char *palabra_invertida = invertir(palabra);

    free(palabra);
    free(palabra_invertida);

    return 0;
}
