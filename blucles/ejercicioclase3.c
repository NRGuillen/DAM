#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int numeros = 1;

	for(numeros = 1; numeros<=9; numeros = numeros += 1){
		printf("%d+", numeros);
	}

	printf("=%d.\n", numeros++);

	return 0;
}
