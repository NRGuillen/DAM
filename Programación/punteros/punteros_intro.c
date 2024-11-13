#include <stdio.h>
#include <stdlib.h>

int main(){

	int x = 10;
	int *p; //Esta varible es de tipo "int *", es decir, puntero a entero. 
		//Esto quiere decir que va a almacenar la direccion de memerioa de una variable de tipo entero.
		
	p = &x;
	printf("Valor de x: %d\n", x); // 10
	printf("Direccion de x: %p\n", &x); //0x7fffbe446b1c
					    //1111111111101111101001010101101010101
	printf("Valor de p: %p\n", p);	//0x7fffbe446b1c

	//Como accedo al contenido de una direccion de memoria?
	
	printf("Contenido de p: %d\n", *p); 

	printf("Direccion de memoria de la variable p: %p\n", &p);

	//printf("Conteniddo de x: %d\n", *x); // no puede acceder a la memoria

	//scanf("%d", &x);

	return 0;
}
