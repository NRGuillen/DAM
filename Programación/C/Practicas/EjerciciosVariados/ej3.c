#include <stdio.h>
#include <stdlib.h>

int main (){

	float precio;
	float descuento;
	float total;
	printf("Introduce la cantidad total de tu compra: ");
	scanf("%f", &precio);

	if(precio > 100){

		descuento = precio * 0.20;
		total = precio - descuento;
		printf("Precio total de %f con 20 prociento de descuento incuido %f\n",precio, total);
	}
	else if(precio <= 100){
		printf("Precio total: %f\n", precio);
	}
	else{printf("Error\n");
	}


	return 0;
}
