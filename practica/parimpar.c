#include <stdio.h>
#include <stdlib.h>

int main (){

	int num;

	printf("Introduce num: ");
	scanf("%d", &num);

	if(num % 2 == 0){
		printf("Es par\n");
	}else{
		printf("Es impar\n");
	}

	return 0;
}
