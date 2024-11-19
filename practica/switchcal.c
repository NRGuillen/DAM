#include <stdio.h>
#include <stdlib.h>

int main (){

	int calificacion;

	printf("Que nota has sacado: ?");
	scanf("%d", &calificacion);

	switch(calificacion / 10){

		case 10:
			if(calificacion = 100){
				printf("Excelente\n");
			}
			break;
		case 9:
			if (calificacion >= 90 && calificacion <= 99){
				printf("Excelente\n");
			}

			break;
		case 8:
                       if (calificacion >= 80 && calificacion <=89){
			       printf("Muy Bien\n");					 
		       }

		       break;
		case 7:
		       if (calificacion >= 70 && calificacion <= 79){
                               printf("Bien\n");											                        
		       }	

		       break;
		case 6:
		       if(calificacion >=60 && calificacion <= 69){
			       printf("Suficiente\n");
		       }
		break;
		default:
		       if(calificacion >=0 && calificacion <= 59){
			       printf("Insuficiente");
		       }
		break;

	}

		

	
	return 0;
}
