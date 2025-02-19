#include <stdio.h>
#include <stdlib.h>

int main()

{
  int arr[5] = {10, 20, 30, 40, 50};
  //La variable p tiene que apuntar al final
  // 1 solucion int p = arr + 5;
  // 2 solucion int p = &arr[5];
  int p*;
  // arr + 5 es mejor porque &arr[5] esta accediendo a la sexta memoria y puede dar core dump porque
  // esa memoria esta reservada
  p = arr +5;

  for (int i = 5; i >0; i--) {
    printf("Elemento %d: %d\n", i, *(p - i));

  }
}
