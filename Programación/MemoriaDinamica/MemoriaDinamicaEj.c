#include <stdio.h>
#include <stdlib.h> // Para malloc, free, etc.

int main() {
   
   //Declara un array de tamaño 3 utilizando memoria dinamica

int n = 3;
int *arr = (int *)malloc(3*sizeof(int));

//SIEMPRE HAY QUE HACER EL ERROR

if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

free(arr);

return 0;
}
