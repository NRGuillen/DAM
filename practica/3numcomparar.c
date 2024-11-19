#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int num, num2, num3;

	printf("introduce el num1: ");
	scanf("%d", &num);

	printf("introduce el num2: ");
	        scanf("%d", &num2);

	printf("introduce el num3: ");
	        scanf("%d", &num3);

	if(num > num2 && num > num3){
		printf("%d es mayor\n", num);
	}else if(num2 > num && num2 > num3){
		printf("%d es mayo\n", num2);
	}else if(num3 > num && num3 > num2){ 
		printf("%d es mayor\n", num3);
	}else{ printf("Error\n");
	}
	return 0;
}
