#include <stdio.h>
#include <stdlib.h>

int main(){

	/*
	###########################################
	#---------------Memoria 1-----------------#
	###########################################
	*/

	int tamaño;
	printf("\nIntroduce el tamaño de la primera memoria: ");
	scanf("%d", &tamaño);
	if(tamaño<=0){
		printf("Introduce un numero mayor o igual a 1\n");
		return 1;
	}

	int *arr=(int*)malloc(tamaño * sizeof(int));
	if(arr == NULL){
		printf("Error al reservar la memoria\n");
		return 1;
	}

	for (int i = 0; i < tamaño; ++i){

	printf("Introduce numeros primos a tu eleccion en la primera memoria en la posicion[%d]: ", i+1);
	scanf("%d", &arr[i]);

	}

	/*
	###########################################
	#---------------Memoria 2-----------------#
	###########################################
	*/

	int tamaño2;
	int contador = 0;
	printf("\nIntroduce el tamaño de la segunda memoria: ");
	scanf("%d", &tamaño2);
	if(tamaño2<=0){
		printf("Introduce un numero mayor o igual a 1\n");
		return 1;
	}

	int *arr2=(int*)malloc(tamaño2 * sizeof(int));
	if(arr2 == NULL){
		printf("Error al reservar la memoria\n");
		return 1;
	}

	for (int i = 0; i < tamaño2; ++i){

	printf("Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[%d]: ", i+1);
	scanf("%d", &arr2[i]);

		if(arr2[i] % 2 == 0){
			contador++;
		}
		if(contador > 2){
			printf("No es primo\n");
		}

	}

	/*
	###########################################
	#----------Visualizar memorias------------#
	###########################################
	*/
	printf("\nValores de la primera memoria:\n");

	for (int i = 0; i < tamaño; ++i){
	printf("Posicion[%d]: %d. Almacenado en la memoria %p\n", i+1, arr[i], &arr[i]);
	}

	printf("\nValores de la segunda memoria:\n");

	for (int i = 0; i < tamaño2; ++i){
	printf("Posicion[%d]: %d. Almacenado en la memoria %p\n",i+1, arr2[i], &arr2[i]);
	}

	/*
	###########################################
	#----------------Opciones-----------------#
	###########################################
	*/

	int opciones;
	printf("\n\tMenu\n");
	printf("1) Sumar las coordenadas de ambos arrays\n");
	printf("2) Concatenar ambos arrays\n");
	printf("Seleccion:");
	scanf("%d", &opciones);
	switch(opciones){

	/*
	###########################################
	#------------Sumar Arrays-----------------#
	###########################################
	*/

	case 1:

	printf("\n");

	if(tamaño > tamaño2){

	int *arr3 = (int*)malloc(tamaño * sizeof(int));
	if(arr3 == NULL){
		printf("No se pudo reservar memoria\n");
		return 1;

	}

		for (int i = 0; i < tamaño; ++i){

		arr3[i] = arr[i] + arr2[i];

		printf("Suma de %d + %d en la posicion [%d]: %d. Almacenado en la memoria %p\n",arr[i], arr2[i], i + 1, arr3[i], &arr3[i]);

		}	
	free(arr3);
	}else{

	int *arr3 = (int*)malloc(tamaño2 * sizeof(int));
	if(arr3 == NULL){
		printf("No se pudo reservar memoria\n");
		return 1;
	}

		for (int i = 0; i < tamaño2; ++i){

		arr3[i] = arr[i] + arr2[i];

		printf("Suma de %d + %d en la posicion [%d]: %d. Almacenado en la memoria %p\n",arr[i], arr2[i], i + 1, arr3[i], &arr3[i]);

		}
	free(arr3);

	}


	break;

	/*
	###########################################
	#--------------Concatenar-----------------#
	###########################################
	*/

	case 2:
	printf("\n");

	int *arr4= (int*)malloc((tamaño + tamaño2) * sizeof(int)); 
	if(arr4 == NULL){
		printf("No se ha podido reservar memoria\n");
		return 1;
	}

	for (int i = 0; i < tamaño; ++i){
	
	arr4[i] = arr[i];

	printf("Posicion[%d]: %d. Almacenado en la memoria %p\n", i + 1, arr4[i], &arr4[i]);

	}

	for (int i = 0; i < tamaño2; ++i){
        arr4[tamaño + i] = arr2[i];  
        printf("Posicion[%d]: %d. Almacenado en la memoria %p\n", tamaño + i + 1, arr4[tamaño + i], &arr4[tamaño + i] );
    }

	free(arr4);

	break;

	default:
	printf("Has introducido un numero invalido\n");
	break;

	}

	free(arr);
	free(arr2);

	return 0;
}


/*
	###########################################
	#-----Sumar Arrays Distinto Tamaño--------#
	###########################################

	Da 2 errores, ya que no estoy haciendo un realloc para almacenar el tamaño de las 2 memeorias en 1 sola, pero tampoco se como reservar
	dos tamaños de un malloc en un mismo realloc, por lo tanto no se como corregirlo.

	cfgs@Info1-Pc13>[ExamenRecuperacion]:valgrind ./ExamenRecuperacion.out
==20423== Memcheck, a memory error detector
==20423== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==20423== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==20423== Command: ./ExamenRecuperacion.out
==20423==

Introduce el tamaño de la primera memoria: 4
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[1]: 1
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[2]: 2
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[3]: 3
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[4]: 4

Introduce el tamaño de la segunda memoria: 5
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[1]: 1
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[2]: 2
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[3]: 3
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[4]: 4
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[5]: 5

Valores de la primera memoria:
Posicion[1]: 1. Almacenado en la memoria 0x4a8c8c0
Posicion[2]: 2. Almacenado en la memoria 0x4a8c8c4
Posicion[3]: 3. Almacenado en la memoria 0x4a8c8c8
Posicion[4]: 4. Almacenado en la memoria 0x4a8c8cc

Valores de la segunda memoria:
Posicion[1]: 1. Almacenado en la memoria 0x4a8c910
Posicion[2]: 2. Almacenado en la memoria 0x4a8c914
Posicion[3]: 3. Almacenado en la memoria 0x4a8c918
Posicion[4]: 4. Almacenado en la memoria 0x4a8c91c
Posicion[5]: 5. Almacenado en la memoria 0x4a8c920

        Menu
1) Sumar las coordenadas de ambos arrays
2) Concatenar ambos arrays
Seleccion:1

Suma de 1 + 1 en la posicion [1]: 2. Almacenado en la memoria 0x4a8c970
Suma de 2 + 2 en la posicion [2]: 4. Almacenado en la memoria 0x4a8c974
Suma de 3 + 3 en la posicion [3]: 6. Almacenado en la memoria 0x4a8c978
Suma de 4 + 4 en la posicion [4]: 8. Almacenado en la memoria 0x4a8c97c
==20423== Invalid read of size 4
==20423==    at 0x1096BC: main (ExamenRecuperacion.c:128)
==20423==  Address 0x4a8c8d0 is 0 bytes after a block of size 16 alloc'd
==20423==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20423==    by 0x109283: main (ExamenRecuperacion.c:20)
==20423==
==20423== Invalid read of size 4
==20423==    at 0x109747: main (ExamenRecuperacion.c:130)
==20423==  Address 0x4a8c8d0 is 0 bytes after a block of size 16 alloc'd
==20423==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20423==    by 0x109283: main (ExamenRecuperacion.c:20)
==20423==
Suma de 0 + 5 en la posicion [5]: 5. Almacenado en la memoria 0x4a8c980
==20423==
==20423== HEAP SUMMARY:
==20423==     in use at exit: 0 bytes in 0 blocks
==20423==   total heap usage: 5 allocs, 5 frees, 2,104 bytes allocated
==20423==
==20423== All heap blocks were freed -- no leaks are possible
==20423==
==20423== For lists of detected and suppressed errors, rerun with: -s
==20423== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)


	###########################################
	#--------Sumar Arrays Mismo Tamaño--------#
	###########################################

cfgs@Info1-Pc13>[ExamenRecuperacion]:valgrind ./ExamenRecuperacion.out
==15228== Memcheck, a memory error detector
==15228== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==15228== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==15228== Command: ./ExamenRecuperacion.out
==15228==
Introduce el tamaño de la primera memoria: 5
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[1]: 1
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[2]: 2
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[3]: 3
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[4]: 4
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[5]: 5

Introduce el tamaño de la segunda memoria: 5
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[1]: 1
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[2]: 2
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[3]: 3
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[4]: 4
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[5]: 5

Valores de la primera memoria:
Posicion[1]: 1
Posicion[2]: 2
Posicion[3]: 3
Posicion[4]: 4
Posicion[5]: 5

Valores de la segunda memoria:
Posicion[1]: 1
Posicion[2]: 2
Posicion[3]: 3
Posicion[4]: 4
Posicion[5]: 5

        Menu
1) Sumar las coordenadas de ambos arrays
2) Concatenar ambos arrays
Seleccion:1
==15228==
==15228== HEAP SUMMARY:
==15228==     in use at exit: 0 bytes in 0 blocks
==15228==   total heap usage: 4 allocs, 4 frees, 2,088 bytes allocated
==15228==
==15228== All heap blocks were freed -- no leaks are possible
==15228==
==15228== For lists of detected and suppressed errors, rerun with: -s
==15228== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/


/*
	###########################################
	#--------------Concatenar-----------------#
	###########################################

cfgs@Info1-Pc13>[ExamenRecuperacion]:valgrind ./ExamenRecuperacion.out
==15447== Memcheck, a memory error detector
==15447== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==15447== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==15447== Command: ./ExamenRecuperacion.out
==15447==
Introduce el tamaño de la primera memoria: 4
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[1]: 1
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[2]: 2
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[3]: 3
Introduce numeros primos a tu eleccion en la primera memoria en la posicion[4]: 4

Introduce el tamaño de la segunda memoria: 5
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[1]: 1
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[2]: 2
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[3]: 3
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[4]: 4
Introduce numeros primos a tu eleccion en la segunda memoria en la posicion[5]: 5

Valores de la primera memoria:
Posicion[1]: 1
Posicion[2]: 2
Posicion[3]: 3
Posicion[4]: 4

Valores de la segunda memoria:
Posicion[1]: 1
Posicion[2]: 2
Posicion[3]: 3
Posicion[4]: 4
Posicion[5]: 5

        Menu
1) Sumar las coordenadas de ambos arrays
2) Concatenar ambos arrays
Seleccion:2
Posicion[1]: 1
Posicion[2]: 2
Posicion[3]: 3
Posicion[4]: 4
Posicion[5]: 1
Posicion[6]: 2
Posicion[7]: 3
Posicion[8]: 4
Posicion[9]: 5
==15447==
==15447== HEAP SUMMARY:
==15447==     in use at exit: 0 bytes in 0 blocks
==15447==   total heap usage: 5 allocs, 5 frees, 2,120 bytes allocated
==15447==
==15447== All heap blocks were freed -- no leaks are possible
==15447==
==15447== For lists of detected and suppressed errors, rerun with: -s
==15447== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/