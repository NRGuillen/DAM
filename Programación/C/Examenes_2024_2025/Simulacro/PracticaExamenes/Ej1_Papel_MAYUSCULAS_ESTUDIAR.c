#include <stdio.h>
#include <stdlib.h>

// Función para capitalizar un carácter
char capitalizar(char letra_minuscula) {
    letra_minuscula = letra_minuscula + 'Z' - 'z';  
    
    return letra_minuscula;
}

int main() {
    int tamaño;

    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

    if (tamaño <= 0) {
        printf("El tamaño debe ser un número entero positivo mayor que 0.\n");
        return 1;
    }

    char *letra_minuscula = (char *)malloc((tamaño + 1) * sizeof(char));  // +1 para '\0'
    if (letra_minuscula == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("Introduce la palabra: ");
    scanf("%s", letra_minuscula);  // Asume que la palabra no tiene espacios

    for (int i = 0; i < tamaño; i++) {
        letra_minuscula[i] = capitalizar(letra_minuscula[i]);  // Modificar la palabra en memoria
    }

    printf("\nPalabra capitalizada: %s\n", letra_minuscula);

    free(letra_minuscula);

    return 0;
}

/*
¿Los cambios que realiza la función capitalizar son persistentes al terminar la función?

Sí, los cambios son persistentes en memoria. La razón de esto es que la función capitalizar modifica directamente 
el contenido de la memoria a la que apunta el puntero letra_minuscula, que fue pasado a la función desde el main. 
Los punteros en C se pasan por referencia, lo que significa que cualquier cambio realizado sobre el puntero en la 
función afectará directamente a los datos en memoria, que son los caracteres de la palabra introducida por el usuario.

En el caso del código, la palabra se pasa por el puntero letra_minuscula y, cuando la función capitalizar cambia 
la letra, esta modificación es realizada sobre los caracteres que están en la memoria asignada para la palabra, por lo que es persistente.

¿Qué ocurre si se introduce una palabra de más longitud de la reservada?

Si el usuario introduce una palabra que tiene una longitud mayor a la memoria reservada por malloc, se provocará un desbordamiento 
de buffer (buffer overflow). Esto ocurre porque el scanf no controla los límites del buffer y se seguirá escribiendo en memoria más 
allá del espacio reservado para la palabra, lo que puede sobrescribir otras variables o incluso partes del programa, provocando un 
comportamiento inesperado o errores de memoria.
*/