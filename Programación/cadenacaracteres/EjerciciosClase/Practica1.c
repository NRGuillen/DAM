#include <stdio.h>
#include <stdlib.h>

 	int main(){

		char a[10];
		int b;
		char c;
					

		printf("Introduzca una palabra: ");
		scanf("%s", a);

		printf("¿Que posicion desea modificar?");
		scanf("%d", &b);

		printf("¿Que caracter desea poner?");
		scanf(" %c", &c);

		a[b] = c;

    //la "a" seria nuestro indice de la palabra que introduzcamos en el char a. Por ejemplo
    //introduzco la palabra hola, "a" = hola.
    //la "b" seria la posicion de nuestro indice que queremos modificar. Por ejemplo 
    //introduzco el numero 2, se modificaria la letra "l".
    //'0' = h
    //'1' = o
    //'2' = l
    //'3' = a
    //'4' = \0												  	  		  		  		  		  		  		  		  	     	 //y la "c" es la que se encargar de reemplazar el nuevo caracter que hayamos introducido
													
													  	  		  		  		  		  		  		  		  		  	printf("La nueva palabra es: %s\n", a);
														  	  		  		  		  		  		  		  		  		  		
														  	  		  		  		  		  		  		  		  
																													        //en este printf se pone la "a" y no la "c" debido a que la variable "a" es la que contiene la 	palabra 
														  	  		  		  		  		  		  		  		  	//completa y la "c" solo contiene el caracter que se va a cambiar, aparte de que un char a secas solo 
														  	  		  		  		  		  		  		  		  	//puede printear una sola letra.
													  	  		  		  		  		  		  		  		  		  						
													
														  	  		  		  		  		  		  		  		  		  	return 0;					  	  		  		  		  		  		  		  		  		  				
}
