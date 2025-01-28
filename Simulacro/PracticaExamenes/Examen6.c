#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Función para invertir la cadena
void invertirCadena(char cadena[]) {
    int longitud = strlen(cadena);
    int i;
    for (i = 0; i < longitud / 2; i++) {
        char temporal = cadena[i];
        cadena[i] = cadena[longitud - i - 1];
        cadena[longitud - i - 1] = temporal;
    }
}

int main() {
    int num;

    // Solicitar el tamaño de la cadena
    printf("Introduce el tamaño de tu string: ");
    scanf("%d", &num);

    // Reservar memoria para la cadena (incluyendo el espacio para '\0')
    char *cadena = malloc((num + 1) * sizeof(char)); 

    if (cadena == NULL) {
        printf("Error al reservar memoria.\n");
        return 1; // Salir si la memoria no se ha reservado correctamente
    }

    // Solicitar la cadena del usuario
    printf("Introduce la cadena: ");
    scanf("%s", cadena);  // Usamos %s para leer la cadena sin espacios

    printf("Normal: %s\n", cadena);

    // Llamar a la función para invertir la cadena
    invertirCadena(cadena);

    // Imprimir la cadena invertida
    printf("Invertida: %s\n", cadena);

    // Liberar la memoria reservada
    free(cadena);

    return 0;
}
