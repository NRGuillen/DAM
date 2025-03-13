#include <stdio.h>

int main() {
    int numero = 10;
    int trampa = 30;

    //Declara como constante el contenido de ptr, puede cambiar desde la variable numero pero no puedo cambiarla desde ptr.

    //No puede cambiar ni el contenido de int ni la memoria de ptr
    
    const int * const ptr = &numero;  // El valor apuntado es constante
    
    //numero 10 = 10
    //declaro como const un  puntero y consy es el int * el contenido
    //lo que no puedo modificar es el contenido de la direccion de la memoria desde el puntero
    //pero si puedo modificar el contenido de la  direccion de la memoria desde la variable 

    printf("Valor: %d\n", *ptr);

    //*ptr = 20;  // Esto daría un error porque el valor es constante
    numero = 20;   // Cambiar el valor directamente es válido
    printf("Nuevo valor: %d\n", *ptr);

    //VAMOS A TRAMEPAR

    //ptr = &trampa;

    *ptr = 30;

    printf("Nuevo valor:%d\n", *ptr);

    return 0;
}