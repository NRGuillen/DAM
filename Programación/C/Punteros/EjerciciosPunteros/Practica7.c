#include <stdio.h>
#include <stdlib.h>

int main() {
    int reserva;

    printf("Reserva de memoria (debe ser mayor que 0): ");
    scanf("%d", &reserva);

    if (reserva <= 0) {
        printf("Error: la cantidad de memoria a reservar debe ser mayor que 0.\n");
        return EXIT_FAILURE;
    }

    int *arr = (int *)malloc(reserva * sizeof(int));

    if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < reserva; i++) {
        printf("Numero para memoria[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Numeros almacenados:\n");
    for (int i = 0; i < reserva; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}
