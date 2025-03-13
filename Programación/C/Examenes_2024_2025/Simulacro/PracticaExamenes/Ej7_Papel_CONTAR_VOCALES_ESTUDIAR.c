#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Función para contar las vocales en la palabra
int contar_vocales(char *palabra) {
    int contador = 0;
    
    // Recorrer cada carácter de la palabra
    for (int i = 0; palabra[i] != '\0'; i++) {
        // Convertir el carácter a minúscula y verificar si es una vocal
        char c = tolower(palabra[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    return contador;
}

int main() {
    int tamaño;

    // Solicitar al usuario el tamaño de la palabra
    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

    // Verificar que el tamaño sea positivo
    if (tamaño <= 0) {
        printf("Introduce un número entero positivo.\n");
        return 1;
    }

    // Reservar memoria dinámica para la palabra
    char *palabra = (char*) malloc((tamaño + 1) * sizeof(char));  // +1 para el '\0'
    if (palabra == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Solicitar al usuario que introduzca la palabra
    printf("Introduce la palabra: ");
    scanf("%s", palabra);  // Leer la palabra

    // Llamar a la función para contar las vocales
    int numero_vocales = contar_vocales(palabra);

    // Imprimir el número de vocales
    printf("La palabra '%s' tiene %d vocales.\n", palabra, numero_vocales);

    // Liberar la memoria utilizada
    free(palabra);

    return 0;
}