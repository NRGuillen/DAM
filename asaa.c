#include <stdio.h>
#include <stdlib.h>

#define TAMANO 10

// Función para limpiar la pantalla en sistemas Unix/Linux
void limpiarPantalla() {
    system("clear");  // O usa "cls" si estás en Windows
}

// Función para imprimir el tablero
void imprimirTablero(char tablero[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

// Función para inicializar el tablero con bordes '*' y el centro '#'
void inicializarTablero(char tablero[TAMANO][TAMANO], int *x, int *y) {
    // Llenamos el tablero con '*'
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            tablero[i][j] = '*';
        }
    }

    // Colocamos el '#' en el centro
    *x = TAMANO / 2;
    *y = TAMANO / 2;
    tablero[*x][*y] = '#';
}

int main() {
    char tablero[TAMANO][TAMANO];
    int x, y;
    char movimiento;

    // Inicializamos el tablero
    inicializarTablero(tablero, &x, &y);

    // Bucle principal de juego
    while (1) {
        limpiarPantalla();
        imprimirTablero(tablero);

        // Leer el movimiento del usuario
        printf("\nUsa 'w' (arriba), 'a' (izquierda), 's' (abajo), 'd' (derecha) para mover. 'q' para salir.\n");
        printf("Movimiento: ");
        scanf(" %c", &movimiento);

        // Verificamos el movimiento y actualizamos la posición del '#'
        if (movimiento == 'q') {
            break;  // Salir del juego
        }

        // Limpiamos la posición actual del '#'
        tablero[x][y] = '*';

        // Movemos el '#'
        if (movimiento == 'w' && x > 0) {
            x--;
        } else if (movimiento == 'a' && y > 0) {
            y--;
        } else if (movimiento == 's' && x < TAMANO - 1) {
            x++;
        } else if (movimiento == 'd' && y < TAMANO - 1) {
            y++;
        }

        // Colocamos el '#' en la nueva posición
        tablero[x][y] = '#';
    }

    printf("Juego terminado.\n");
    return 0;
}

