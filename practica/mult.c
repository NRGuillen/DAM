#include <stdio.h>
#include <stdlib.h>

int main (){

	int num;
	int mult;

	printf("Introduce que tabla de multiplicar quieres ver: ");
	scanf("%d", &num);

	for(int i = 0; i <= 10; i++){
		
	mult = num * i;

		printf("%d x %d = %d\n", num, i, mult);
	}	

	return 0;
}
