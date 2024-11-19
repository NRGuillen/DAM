#include <stdio.h>
#include <stdlib.h>

int main (){

	int num;
	int num2 = 0;

	printf("Introduce un numero para ver cuantos digitos totales tiene: ");
	scanf("%d", &num);
	
	while(num > 0){
		num = num / 10;
		num2++;
		printf("%d", num2);
	}

	return 0;
}

