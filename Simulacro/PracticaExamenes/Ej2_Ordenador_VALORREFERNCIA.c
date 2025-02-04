#include <stdio.h>
#include <stdlib.h>

void modificar_elementos(int valor) {
    valor += 10;  
}

void modificar_por_referencia(int *valor) {
    *valor += 10;  
}

int main() {
    int tamaño;

    printf("Ingrese un número entero positivo para el tamaño del array: ");
    scanf("%d", &tamaño);

    if (tamaño <= 0) {
        printf("El tamaño debe ser un número positivo.\n");
        return 1;
    }

    int *arr = (int *)malloc(tamaño * sizeof(int));
    if (arr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingrese %d números:\n", tamaño);
    for (int i = 0; i < tamaño; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray original:\n");
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }

    int valor = arr[tamaño - 1];

    modificar_elementos(valor);

    printf("\n\nDespués de modificar_elementos() (por valor):\n");
    printf("Último elemento: %d (sin cambios)\n", arr[tamaño - 1]); // No se modifica

    modificar_por_referencia(&arr[tamaño - 1]);

    printf("\nDespués de modificar_por_referencia() (por punteros):\n");
    printf("Último elemento: %d (modificado)\n", arr[tamaño - 1]); // Se modifica correctamente

    free(arr);

    return 0;
}


