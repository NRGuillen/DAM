#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int *array, int a_buscar, int ini, int fin);

int main(){

	int array[10] = {-5,1,9,10,11,12,17,120,150,1500};
	int a_buscar = 120;
	int encontrado = busqueda_binaria(array, 120 , 0, 9);

	printf("Numero encontrado: %d\n", *array);

	return 0;
}

	int busqueda_binaria(int *array, int a_buscar, int ini, int fin){

		int mitad = (ini + fin)/2;

		if (a_buscar == array[mitad]){

		return 1;

		}else if(a_buscar < array[mitad]){

			int ret = busqueda_recusrvisva(array, a_buscar, ini, mitad);

		 

		}else{

			int ret = busqueda_recusrvisva(array, a_buscar, ini, fin);

		}

	return;

}

