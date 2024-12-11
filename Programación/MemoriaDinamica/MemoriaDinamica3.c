#include <stdio.h>
#include <stdlib.h> // Para malloc, free, etc.

int main() {
   
   //Declara un array de tamaño 3 utilizando memoria dinamica

int n = 3;
int *arr = (int *)malloc(3*sizeof(int));

//SIEMPRE HAY QUE HACER EL ERROR

if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;
}
//INICIALIZO LOS VALORES DEL

//1º opcion

arr[0] = 1;
arr[1] = 3;
arr[2] = 5;

printf("arr[0] = %d\n",arr[0]);
printf("arr[1] = %d\n", arr[1]);
printf("arr[2] = %d\n", arr[2]);

//2º opcion 

    /*
    for (int i = 0; i < 3; i++) {
        arr[i] = 2*i+1;
    }
    */

//VAMOS A AMPLIAR EL ARRAY A 5 ELEMENTOS

int * arr_ampliado = realloc(arr,5*sizeof(int));

if (arr_ampliado == NULL) {
        //free(arr); //Realloc no libera la memoria antigua.
        /*
        Se pone dentro porque si realloc falla, el programa tiene que liberar 
        la memoria reservada por lo tanto si hay un error antes de terminar el 
        programa libero todo lo que haya.
        */
        printf("Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;

}

arr = arr_ampliado; 

arr[3] = 7;
arr[4] = 9;

printf("<--ARRAY AUMENTADO A 5-->\n");
printf("arr[0] = %d\n",arr[0]);
printf("arr[1] = %d\n", arr[1]);
printf("arr[2] = %d\n", arr[2]);
printf("arr[3] = %d\n", arr[3]);
printf("arr[4] = %d\n", arr[4]);

/*
for (int i = 0; i < 5; ++i){
    printf("arr[%d]: %d", i, arr_ampliado[i]);
}
*/

free(arr_ampliado);
free(arr);

return 0;
}
