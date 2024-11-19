#include <stdio.h>
#include <stdlib.h>

int main (){

	int num;
	int num2 = 0;
	int suma = 0;

	printf("introduce un numero que sume su propio numero");
	scanf("%d", &num);

	while(num2 < num){
		num2++;
	
		suma += num2;
	}
	printf("%d", suma);

	return 0;
}

