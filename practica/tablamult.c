#include <stdio.h>
#include <stdlib.h>

int main(){

	int num, resultado;

	printf("Introduce el numero tabla");
	scanf("%d", &num);

	for(int i = 0; i <= 10; i++){
	
		resultado = i * num;

		printf(" %d x %d = %d\n", num, i, resultado);

	}
	return 0;
}
