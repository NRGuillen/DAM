#include <stdio.h>
#include <stdlib.h>

// Función para intercambiar la primera y última fila de la matriz
void intercambiar_filas(int *matriz, int n) {
    for (int i = 0; i < n; i++) {
        // Intercambiar el elemento de la primera fila con el de la última fila
        int temp = *(matriz + i);  // Primer elemento de la primera fila
        *(matriz + i) = *(matriz + (n - 1) * n + i);  // Primer elemento de la última fila
        *(matriz + (n - 1) * n + i) = temp;  // Asignar el valor intercambiado
    }
}

int main() {
    int n;

    // Solicitar al usuario el tamaño de la matriz
    printf("Introduce el tamaño de la matriz cuadrada (n): ");
    scanf("%d", &n);

    // Verificar que n sea positivo
    if (n <= 0) {
        printf("Introduce un número entero positivo.\n");
        return 1;
    }

    // Reservar memoria dinámica para la matriz cuadrada de n x n
    int *matriz = (int*) malloc(n * n * sizeof(int));
    if (matriz == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Rellenar la matriz con valores proporcionados por el usuario
    printf("Introduce los valores de la matriz %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento en la posición [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i * n + j]);  // Acceder al elemento de la matriz de manera lineal
        }
    }

    // Imprimir la matriz antes de intercambiar las filas
    printf("\nMatriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i * n + j]);
        }
        printf("\n");
    }

    // Intercambiar la primera y última fila
    intercambiar_filas(matriz, n);

    // Imprimir la matriz después de intercambiar las filas
    printf("\nMatriz después de intercambiar las filas:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i * n + j]);
        }
        printf("\n");
    }

    // Liberar la memoria de la matriz
    free(matriz);

    return 0;
}