#include <stdio.h>
#include <stdlib.h>

int main(){

	int num;
	int anterior_del_anterior = 0;
	int anterior = 1;

	for(int i = 1; i<=10; i++){
		num = anterior + anterior_del_anterior;

		printf("%d", num);
		
		anterior_del_anterior = anterior;
		anterior = num;
	}

	printf("%d", anterior+anterior_del_anterior);

	return 0;
}
