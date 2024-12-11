#include <stdio.h>
#include <stdlib.h> // Para malloc, free, etc.

int main() {
   
int n ;
int *arr = (int *)malloc(100*sizeof(int));

scanf("%d", &n);

if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;
}

    for (int i = 0; i < n; i++) {
        arr[i] = 2*i;
    }
   
int * arr_ampliado = realloc(arr,100*sizeof(int));

if (arr_ampliado == NULL) {
        free(arr); //Realloc no libera la memoria antigua.
        
        /*
        Se pone dentro porque si realloc falla, el programa tiene que liberar 
        la memoria reservada por lo tanto si hay un error antes de terminar el 
        programa libero todo lo que haya.
        */
        
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;

}

arr = arr_ampliado; 

for (int i = 0; i < n; ++i){
    arr[i] = 2*i;
    printf("arr[%d]: %d\n", i, arr_ampliado[i]);
}

int * arr_impar = realloc(arr,100*sizeof(int));

if (arr_ampliado == NULL) {
        free(arr); //Realloc no libera la memoria antigua.
        
        /*
        Se pone dentro porque si realloc falla, el programa tiene que liberar 
        la memoria reservada por lo tanto si hay un error antes de terminar el 
        programa libero todo lo que haya.
        */
        
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;

}

arr = arr_ampliado; 

for (int i = 0; i < n; ++i){
    arr[i] = 2*i+1;
    printf("arr[%d]: %d\n", i, arr_impar[i]);
}


free(arr_ampliado);

return 0;
}

