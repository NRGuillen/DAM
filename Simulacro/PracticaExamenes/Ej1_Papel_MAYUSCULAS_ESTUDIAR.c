#include <stdio.h>
#include <stdlib.h>

// Función para capitalizar un carácter
char capitalizar(char letra_minuscula) {
    letra_minuscula = letra_minuscula + 'A' - 'a';  
    
    return letra_minuscula;
}

int main() {
    int tamaño;

    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

    if (tamaño <= 0) {
        printf("El tamaño debe ser un número entero positivo mayor que 0.\n");
        return 1;
    }

    char *letra_minuscula = (char *)malloc((tamaño + 1) * sizeof(char));  // +1 para '\0'
    if (letra_minuscula == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("Introduce la palabra: ");
    scanf("%s", letra_minuscula);  // Asume que la palabra no tiene espacios

    for (int i = 0; i < tamaño; i++) {
        letra_minuscula[i] = capitalizar(letra_minuscula[i]);  // Modificar la palabra en memoria
    }

    printf("\nPalabra capitalizada: %s\n", letra_minuscula);

    free(letra_minuscula);

    return 0;
}