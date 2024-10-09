#include <stdio.h>
#include <stdlib.h>

int main() {

    //Usamos float para los numeros decimales ya que una compra puede ser 12.432
    //Usamos char para que pueda introducir un caracter en este caso como solo puedo escribir uno he simplificado la     palabra a la primera letra de cada una(no se hacerlo con la palabra completa)

    float monto, monto_final;
    char rol;

    //Lee el numero de la compra que vayamos a poner    

    printf("Introduce el monto total de la compra: ");
    scanf("%f", &monto);
	
   //Lee el caracter para aplicar el descuento, en este caso solo se pueden introducir los 3 caracteres que he puesto	, si introduces otro dara un "error" 	
    
    printf("Introduce tu rol en minuscula (e para Estudiante, p para Profesor, o para Otro): ");
    scanf(" %c", &rol);  

   //los descuentos 15 y 10 son igual a 0.85 y 0.90(100-15=85 > 0.85)

   //El codigo se leeria algo como esto:
   //si(rol es igual a e){ el resto final es el numero introducido en scanf * 0.85;}
   //si es otra cosa(rol es igual a p) {el resto final es el numero de scanf * 0.90;}
   
    if (rol == 'e') {
        monto_final = monto * 0.85;  
        printf("Se aplicó un descuento del 15 porciento. ");
    } else if (rol == 'p') {
        monto_final = monto * 0.90;  
        printf("Se aplicó un descuento del 10 porciento. ");
    } else if (rol == 'o') {
        monto_final = monto;  
        printf("No se aplicó ningún descuento. ");
    } else {
        printf("Error\n");
        return 1;  
    }

    //Escribe la cantidad que tienes que pagar el %.2 es para que solo escriba 2 decimales y no 300000    

    printf("Debes pagar: %.2f\n", monto_final);

    return 0;
}

