#include <stdio.h>
#include <stdlib.h>

char capitalizar(char letra_minuscula){

char a = 'A';

return letra_minuscula - ('a' - a);

}

int main (){

char minuscula, mayuscula;

printf("Introduce la letra que quieras pasar a mayúscula: ");
scanf("%c", &minuscula);

mayuscula = capitalizar(minuscula);

printf ("La letra en mayúsculas es: %c\n", mayuscula);

return 0;
}
