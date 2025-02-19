#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // Solicitar al usuario los números n y m
    printf("Introduce el número de filas (n): ");
    scanf("%d", &n);

    printf("Introduce el número de columnas (m): ");
    scanf("%d", &m);

    // Verificar que los números sean positivos
    if (n <= 0 || m <= 0) {
        printf("Introduce números enteros positivos para las filas y columnas.\n");
        return 1;
    }

    // Reservar memoria dinámica para la matriz de n x m (usando un solo puntero)
    int *matriz = (int*) malloc(n * m * sizeof(int));  // Un solo puntero para la matriz

    if (matriz == NULL) {
        printf("Error al reservar memoria para la matriz.\n");
        return 1;
    }

    // Reservar memoria para el array de sumas de filas
    int *suma_filas = (int*) malloc(n * sizeof(int));
    if (suma_filas == NULL) {
        printf("Error al reservar memoria para el array de sumas.\n");
        return 1;
    }

    // Inicializar la matriz y calcular la suma de los elementos de cada fila
    for (int i = 0; i < n; i++) {
        suma_filas[i] = 0;  // Inicializar la suma de la fila

        for (int j = 0; j < m; j++) {
            int index = i * m + j;  // Cálculo del índice lineal
            matriz[index] = i + j;  // Cada posición es la suma de la fila y la columna
            suma_filas[i] += matriz[index];  // Acumular la suma de los elementos de la fila
        }
    }

    // Imprimir la matriz
    printf("\nMatriz de tamaño %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int index = i * m + j;  // Cálculo del índice lineal
            printf("%d ", matriz[index]);
        }
        printf("\n");
    }

    // Imprimir el array con las sumas por filas
    printf("\nSuma de los elementos de cada fila:\n");
    for (int i = 0; i < n; i++) {
        printf("Suma de la fila %d: %d\n", i + 1, suma_filas[i]);
    }

    // Liberar la memoria
    free(matriz);  // Liberar la memoria de la matriz
    free(suma_filas);  // Liberar la memoria del array de sumas

    return 0;
}
