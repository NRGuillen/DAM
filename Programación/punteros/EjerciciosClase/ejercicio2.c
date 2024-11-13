#include <stdio.h>
#include <stdlib.h>

int main(){

	//De 4 en 4 bytes
	
	int arr[5] = {10, 20, 30, 40, 50}; // Equivalente a int *arr = {..
	int *p = arr;
	int suma = 0;

	for (int i = 0; i < 5; i++) {
	printf("Elemento %d: %d (en la dirección %p)\n", i, *(p + i),p+i);	
		suma += *(p+i);
	}

	

	printf("%d\n", suma);

	return 0;
}
