#include <stdio.h>
#include <stdlib.h>

int main(){

	int i = 0;

	for( i =0; i<5; i = i +1){
	       printf("%d,", i);
	}
printf("Terminado\n");

//Traduccion a while

	i = 0;

	while(i<5){
		printf("%d," i);
		i = i + 1;
}

	printf("Terminado el while");


	return 0;
}
