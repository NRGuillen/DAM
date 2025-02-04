#include <stdio.h>
#include <stdlib.h>

int es_primo(int num) {
    if (num <= 1) return 0;  // No es primo
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;  // No es primo
    }
    return 1;  // Es primo
}

int main() {
    int n;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Introduce un numero mayor o igual a 1\n");
        return 1;
    }

    int *array = malloc(n * sizeof(int));

    if (array == NULL) {
        printf("Error al reservar memoria.\n");
        return 1; 
    }

    int num = 2; 
    for (int i = 0; i < n; ) {
        if (es_primo(num)) {
            array[i++] = num;
        }
        num++;
    }

    printf("Los primeros %d números primos son:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}


//Al liberar la memoria con free(), ¿los datos almacenados en el array desaparecen inmediatamente? ¿Qué ocurre si intentamos acceder a ellos después de liberar la memoria?

/*
Cuando llamamos a free(arr),el sistema marca como liberado el bloque reservado por malloc, por lo que significa es que esa memoria ya puede ser utilizada
 por otras operaciones de asignacion en el programa.

Los datos no se borran inmediatamente: Después de llamar a free(), los datos almacenados en la memoria liberada no se borran de inmediato. 
El contenido de la memoria podría seguir existiendo temporalmente en esa dirección, pero ya no podemos garantizar que sea accesible o coherente. 
*/