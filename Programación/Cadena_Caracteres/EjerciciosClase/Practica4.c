#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char opcion[6];

	printf("¿iQue iquieres ver, un gato o un perro? ");
	scanf("%s" , opcion);
                 
	//strcmp esta comparando la opcion con la cadena de caracteres de "gato|Gato y perro|Perro" si opcion
	//es alguna de estas cadenas devolvera un 0 y ejecutara el printf si no es asi strcmp devolvera un
	//valor distinto a 0 y ejecutara el else final.
		
	if(strcmp(opcion, "gato") == 0){
			
	     	printf("  /|_/| \n");
		printf(" ( o o ) \n");
		printf(" ==_Y_== \n");
		printf("   `-' \n");
	
	}else if(strcmp(opcion, "Gato") == 0){
								
		printf("  /|_/| \n");                    
		printf(" ( o o ) \n"); 										
		printf(" ==_Y_== \n");                                                                  
		printf("   `-' \n");

	}else if(strcmp(opcion, "perro") == 0){
	       
	        printf("   __      _\n");
	 	printf(" o'')}____/|\n");
	        printf("  `_/      )\n");
		printf("  (_(_/-(_/\n");

	}else if(strcmp(opcion, "Perro") == 0){
	       
	        printf("   __      _\n");        
		printf(" o'')}____/|\n");                          		      
		printf("  `_/      )\n");                                      
	       	printf("  (_(_/-(_/\n");

	}else{
 	       printf("No has introducido ni un gato ni un perro\n");		
	}
	return 0;
}

















