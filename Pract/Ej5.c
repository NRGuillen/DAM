#include <stdio.h>
#include <stdlib.h>

void sumaPrimeraFila(int *arr, int columna, int *suma);
void sumaUltimaFila(int *arr, int fila, int columna, int *suma); 
void sumaPrimeraColumna(int *arr, int fila, int columna, int *suma); 
void sumaUltimaColumna(int *arr, int fila, int columna, int *suma);
void calcularContorno(int sumaPrimeraFila, int sumaUltimaFila, int sumaPrimeraColumna, int sumaUltimaColumna, int *contorno);

int main() {
    int fila, columna;//variables para memoria dinamica 

    printf("Introduce el numero de filas: ");
    scanf("%d", &fila);
    printf("Introduce el numero de columnas: ");
    scanf("%d", &columna);

    int *arr = (int *)malloc(fila * columna * sizeof(int));
    if (arr == NULL) {
        printf("No se ha podido reservar memoria\n");
        return 1;
    }

    for (int i = 0; i < fila; i++) { //Bucle que reccore las filas
        for (int j = 0; j < columna; j++) { //Bucle que reccorre las columnas de cada fila
            arr[i * columna + j] = rand() % 10;//rand() % 10 genera numeros aleatorios desde 0-9, el % limita el rango es decir si fuese 100, seria de 0 - 100
                                               //lo hemos puesto a 10, porque es mas estetico para una tabla(matriz)
        }
    }


    printf("Matriz generada:\n");
    for (int i = 0; i < fila; i++) {//Bucle que reccore las filas
        for (int j = 0; j < columna; j++) {//Bucle que reccorre las columnas de cada fila
            printf("%d ", arr[i * columna + j]);//calcula la posicion de la fila i y la columna j
        }
        printf("\n");
    }

    int sumaFila1, sumaFilaN, sumaColumna1, sumaColumnaN, sumaContorno;

    sumaPrimeraFila(arr, columna, &sumaFila1);
    printf("Suma de la primera fila: %d\n", sumaFila1);

    sumaUltimaFila(arr, fila, columna, &sumaFilaN);
    printf("Suma de la última fila: %d\n", sumaFilaN);

    sumaPrimeraColumna(arr, fila, columna, &sumaColumna1);
    printf("Suma de la primera columna: %d\n", sumaColumna1);

    sumaUltimaColumna(arr, fila, columna, &sumaColumnaN);
    printf("Suma de la última columna: %d\n", sumaColumnaN);

    calcularContorno(sumaFila1, sumaFilaN, sumaColumna1, sumaColumnaN, &sumaContorno);
    printf("La suma del contorno es: %d\n", sumaContorno);

    free(arr);

    return 0;
}

// Funcion para sumar la primera fila
void sumaPrimeraFila(int *arr, int columna, int *suma) {
    *suma = 0;
    for (int j = 0; j < columna; j++) {//bucle para recorrer la primera fila
        *suma += arr[0 * columna + j];  // 0 * columna -> Estamos en la [0] fila y le sumamos j para acceder a la columna especifica,0 -> columna  
    }
}

// Funcion para sumar la última fila
void sumaUltimaFila(int *arr, int fila, int columna, int *suma) {
    *suma = 0;
    if (fila > 1) {  //comprueba que si solo hay una fila no se realice ningun calculo e imprima la fila directamente
        for (int j = 0; j < columna; j++) {//bucle para recorrer la ultima fila
            *suma += arr[(fila - 1) * columna + j];//fila - 1 = ultima fila, el -1 porque el array comienza desde 0 y no 1
                                                            //* columna -> Multiplica el numero de la fila por numero de columnas, para acceder al inicio de la fila
                                                            // +j -> accedemos a las columnas de la ultima fila
        }
    }
}

// Funcion para sumar la primera columna
void sumaPrimeraColumna(int *arr, int fila, int columna, int *suma) {
    *suma = 0;
    for (int i = 1; i < fila - 1; i++) {  //Bucle para recorrer filas
        *suma += arr[i * columna];//i * columna -> calcula la posicion
    }
}

// Funcion para sumar la última columna
void sumaUltimaColumna(int *arr, int fila, int columna, int *suma) {
    *suma = 0;
    if (columna > 1) {  //comprueba que si hay una columna no se realice niguna suma, ya que la ultima columna tambien es la primera(no se si me he explicado)
        for (int i = 1; i < fila - 1; i++) {  //bucle que reccorre las filas
            *suma += arr[i * columna + (columna - 1)];//i * columna -> accedemos a la posicion, columna - 1-> la ultima columna
        }
    }
}

// Funcion para calcular la suma del contorno
void calcularContorno(int sumaPrimeraFila, int sumaUltimaFila, int sumaPrimeraColumna, int sumaUltimaColumna, int *contorno) {
    *contorno = sumaPrimeraFila + sumaUltimaFila + sumaPrimeraColumna + sumaUltimaColumna;//suma total, contorno
}

