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
        arr[i] = 2*i+1;
    }
    
int * arr_ampliado = realloc(arr,100*sizeof(int));

if (arr_ampliado == NULL) {
        free(arr); 
        
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;

}

arr = arr_ampliado; 

for (int i = 0; i < n; ++i){
    arr[i] = 2*i+1;
    printf("arr[%d]: %d\n", i, arr_ampliado[i]);
}


free(arr_ampliado);

return 0;
}