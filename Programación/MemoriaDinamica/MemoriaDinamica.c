#include <stdio.h>
#include <stdlib.h> // Para malloc, free, etc.

int main() {
    int *p_error = malloc(sizeof(int)); // Reservar espacio para un int
    //aqui hay un casting implicito
    //malloc devuelve un void* hay que convertirlo para poder utilizarlo

    int p* = (int*)malloc(sizeof(int));
    //Esta es la buena práctica

    if(p == NULL){//Malloc ha falldo porque no hay memoria disponible.
    	printf("ERROR FATAL JEJE\n");
    	return 1;//El programa ha fallado
    }

    *p=42; // usamos la memoria
    printf("El valor es %d\n", *p);
    free(p); //Liberamos la memoria reservada
    free(p_error);//Liberamos 
}
