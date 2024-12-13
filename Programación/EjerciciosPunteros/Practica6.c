#include <stdio.h>
#include <stdlib.h>

int main() {

    int reserva;
    char cadena;
    
    printf("Reserva de memoria: ");
    scanf("%d", &reserva);
    int *arr = (int *)malloc(reserva * sizeof(int));
    
    //SIEMPRE HAY QUE HACER EL ERROR
    if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;
    }
    
    for (int i = 0; i < reserva; i++) {
        printf("Numero para memoria[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Cadena almacenada:\n");
    for (int i = 0; i < reserva; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    
    free(arr);
    
    return 0;
}
