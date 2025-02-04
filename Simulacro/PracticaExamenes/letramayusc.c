#include <stdio.h>
#include <stdlib.h>

char capitalizar (char letra_minuscula){
	letra_minuscula = letra_minuscula + 'Z' - 'z';
	return letra_minuscula;
}

int main(int argc, char**argv){

int tamaño;
printf("Introduce el tamaaño del array: ");
scanf("%d", &tamaño);

char* letra_minuscula=(char*)malloc(tamaño + 1 * sizeof(char));

printf("introduce la palabra: ");
scanf("%s", letra_minuscula);

for (int i = 0; i < tamaño; ++i){

letra_minuscula[i] = capitalizar(letra_minuscula[i]);

}

printf("%s", letra_minuscula);

free(letra_minuscula);


}