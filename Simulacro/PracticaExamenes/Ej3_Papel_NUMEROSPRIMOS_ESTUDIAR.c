#include <stdio.h>
#include <stdlib.h>

// Función para verificar si un número es primo
int es_primo(int num) {
    if (num <= 1) return 0;  // No es primo
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;  // No es primo
    }
    return 1;  // Es primo
}

int main() {
    int n;

    // Solicitar el tamaño del array
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Introduce un numero mayor o igual a 1\n");
        return 1;
    }

    // Reservar memoria dinámica para el array
    int *array = malloc(n * sizeof(int));

    // Verificar si la memoria fue reservada correctamente
    if (array == NULL) {
        printf("Error al reservar memoria.\n");
        return 1; // Terminar si no se pudo reservar memoria
    }

    // Llenar el array con los primeros n números primos
    int num = 2; // El primer número primo es 2
    for (int i = 0; i < n; ) {
        if (es_primo(num)) {
            array[i++] = num;
        }
        num++;
    }

    // Mostrar los números primos
    printf("Los primeros %d números primos son:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar la memoria reservada
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