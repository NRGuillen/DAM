#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
######################################################
#-----EXPLICACION DE CIFRAZO AL FINAL DEL CODIGO-----#
######################################################
*/

void cifrarPalabra(char *arr, int clave);
void restarChar(char *cadena, int tamano);

int main() {
    int clave, tamaño;//variables para memoria dinamica

    printf("Introduce el tamaño de la palabra que vas a intrudcir: ");
    scanf("%d", &tamaño);
     if (tamaño <= 0) {
        printf("El tamaño debe ser mayor o igual que 1.\n");
        return 1;
    }


    char *arr = (char *)malloc(tamaño * sizeof(char)); 
    if (arr == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }


    printf("Introduce el texto: ");
    restarChar(arr, tamaño); 


    printf("Introduce la clave (desplazamiento): ");
    scanf("%d", &clave);


    clave = clave % 27;


    cifrarPalabra(arr, clave);
    printf("Texto cifrado: %s\n", arr);


    cifrarPalabra(arr, -clave);
    printf("Texto descifrado: %s\n", arr);


    free(arr);

    return 0;
}

void cifrarPalabra(char *arr, int clave) {
    for (int i = 0; arr[i] != '\0'; i++) { //bucle que recorre toda la palabra hasta que encuentra el \0

        if (arr[i] >= 'a' && arr[i] <= 'z') { //aplica solo a las minusculas
            arr[i] = ((arr[i] - 'a' + clave) % 27 + 27) % 27 + 'a'; //Explicacion abajo   
        }

        else if (arr[i] >= 'A' && arr[i] <= 'Z') { //aplica solo a las mayusculas
            arr[i] = ((arr[i] - 'A' + clave) % 27 + 27) % 27 + 'A';  
        }
    }
}

void restarChar(char *cadena, int tamano) {
    fgets(cadena, tamano, stdin);
    if (cadena[strlen(cadena) - 1] == '\n') { //Si hay un salto de linea
        cadena[strlen(cadena) - 1] = '\0'; //se reemplazara por un \0, asi aseguramos que no tenemos un salto de linea para evitar problemas
                                           //- 1 -> para acceder al ultimo caracter, ya que la cadena inicia en 0 y no en 1
    }
}


/*

arr[i] = ((arr[i] - 'a' + clave) % 26 + 26) % 26 + 'a';   

arr[i] - 'a' -> convierte la letra al numero del afabeto, es decir a -> 0, b -> 1
+ clave -> suma el valor que el usuario introduzca, positivo -> derecha, negativo -> izquierda
% 27 ->  se utiliza por si el valor del usuario es muy grande, que no sobrepase el 27 (27 -> z)
+ 27 -> se utiliza para asegurar que siempre va a estar en el rango de 0-27
segundo % 27 -> se utiliza para asegurar que esta en el rango 
+ 'a' -> se utiliza para convertir el numero a letra ASCII 


*/