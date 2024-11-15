#include <stdio.h>
#include <stdlib.h>

int main(){

int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;

	printf("Elemento 1: %d\n", *p);     // 1
	p++;
	
	printf("Elemento 2: %d\n", *p);     // 2
	p += 2;
	
	printf("Elemento 4: %d\n", *p);     // 4
					    
	printf("Elemento posicion 0: %d\n", p[0]);
	printf("Elemento posicion 0: %d\n", p[-2]);
	printf("Elemento posicion 0: %d\n", p[1]);

	p = arr; //p[0] vuelve a ser 1
		 
	return 0;
}

