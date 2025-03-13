#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int *array, int a_buscar, int ini, int fin);

int main() {
    int array[10] = {-5, 1, 9, 10, 11, 12, 17, 120, 150, 1500};
    int a_buscar = 1500;
    int encontrado = busqueda_binaria(array, a_buscar, 0, 9);

    if (encontrado != -1) {
        printf("Número encontrado en la posición: %d\n", encontrado+1);
    } else {
        printf("Número no encontrado.\n");
    }

    return 0;
}

int busqueda_binaria(int *array, int a_buscar, int ini, int fin) {
    if (ini > fin) {
        return -1; 
    }

    int mitad = (ini + fin) / 2;

    if (array[mitad] == a_buscar) {
        return mitad;
    } else if (a_buscar < array[mitad]) {
        return busqueda_binaria(array, a_buscar, ini, mitad - 1);
    } else {
        return busqueda_binaria(array, a_buscar, mitad + 1, fin);
    }
}

