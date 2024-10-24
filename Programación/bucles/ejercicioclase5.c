#include <stdio.h>
#include <stdlib.h>

int main(){

	int num;
	int resultado = 1;

	printf("Introduce un numero: ");
      	scanf("%d",&num);	      

	for(int i = 1; i <=num; i++){
		resultado = resultado * i;
	}

	printf("%d = %d\n", num, resultado);

	return 0;
}
