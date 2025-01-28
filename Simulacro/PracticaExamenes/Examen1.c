#include <stdio.h>
#include <stdlib.h>

char capitalizar(char letra_minuscula) {
    if (letra_minuscula >= 'a' && letra_minuscula <= 'z') {
        letra_minuscula = letra_minuscula - ('a' - 'A'); // Convierte la letra minúscula a mayúscula
    }
    return letra_minuscula;
}

int main(int argc, char **argv) {
    int tamaño;

    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

    if (tamaño <= 0) {
        printf("Introduce un numero positivo, espabilao!\n");
        return 1; 
    }

    char *letra_minuscula = malloc((tamaño + 1) * sizeof(char));
    if (letra_minuscula == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    printf("Introduce una palabra de %d caracteres: ", tamaño);
    scanf("%s", letra_minuscula);  

    letra_minuscula[0] = capitalizar(letra_minuscula[0]);

    printf("Palabra con primera letra capitalizada: %s\n", letra_minuscula);

    free(letra_minuscula);

    return 0;
}
