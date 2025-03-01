#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"

#define MAX_NOMBRE 50
#define MAX_DESCRIPCION 1000
#define MAX_DRAGONES 3
#define MAXNOMBRE 50
#define MAXARMA 20
#define MAXATAQUE 20
#define MAXVIDA 100
#define MAXORO 600
#define MAXDESCRPCION 200
#define MAXDESC 256  

// Colores estándar ANSI
#define NEGRO     "\033[30m"
#define ROJO      "\033[31m"
#define VERDE     "\033[32m"
#define AMARILLO  "\033[33m"
#define AZUL      "\033[34m"
#define MAGENTA   "\033[35m"
#define CIAN      "\033[36m"
#define BLANCO    "\033[37m"

// Colores personalizados RGB
#define NARANJA   "\033[38;2;255;128;0m"
#define ROSA      "\033[38;2;255;151;203m"
#define AZUL_C    "\033[38;2;53;149;240m"
#define VERDE_C   "\033[38;2;17;245;120m"
#define GRIS      "\033[38;2;176;174;174m"
#define VIOLETA   "\033[38;2;148;0;211m"
#define MARRON    "\033[38;2;139;69;19m"
#define TURQUESA  "\033[38;2;64;224;208m"
#define DORADO    "\033[38;2;255;215;0m"
#define LIMA      "\033[38;2;50;205;50m"
#define CELESTE   "\033[38;2;135;206;250m"
#define LAVANDA   "\033[38;2;230;230;250m"
#define SALMON    "\033[38;2;250;128;114m"
#define CHOCOLATE "\033[38;2;210;105;30m"

// Reset (para volver al color original)
#define SC        "\033[0m"

typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    int vida;
    int daño;
    int resistencia;
    char pasiva[MAX_DESCRIPCION];
    char descripcion[MAX_DESCRIPCION];
    int oro;
} Dragon;


typedef struct{
    int ID;
    char nombre[MAXNOMBRE + 1];
    char arma[MAXARMA + 1];
    int ataque;
    int vida;
    int oro;
    char descripcion[MAXDESCRPCION + 1];
} Cazador;

void inicializarCazador(Cazador *datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion);
void cazadorIMPRIMIR (const Cazador * cazador_a_imprimir);
void inicializarCazadores(Cazador ** cazadores, int *totalCazadores);
void cazadorSELEC(Cazador *cazadores, int totalCazadores);

void añadirCazador(Cazador **cazadores, int *totalCazadores);
void inicializarDragon(Dragon *dragon, int id,  char *nombre, int vida, int daño, int resistencia,  char *pasiva,  char *descripcion, int oro);
void mostrarDragon(Dragon *dragon);
void visualizarDragones(void);
void añadir_dragon(Dragon **dragones, int *totalDragones);
void seleccionarDragon(Dragon *dragones, int totalDragones);

void añadir_dragon(Dragon **dragones, int *totalDragones) {
    Dragon nuevoDragon;
    int seleccion;

    printf(AMARILLO"\nIntroduzca los datos del nuevo dragon: \n"SC);

    printf(AZUL_C"\tID: %d\n", 1 + MAX_DRAGONES);

    getchar();  

    // NOMBRE
    printf(AZUL_C"\tNOMBRE: ");
    scanf("%[^\n]", nuevoDragon.nombre);

    // VIDA
    do {
        printf(AZUL_C"\tVIDA: ");
        if (scanf("%d", &nuevoDragon.vida) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.vida < 0 || nuevoDragon.vida > 100) {
            printf(ROJO"\tEl rango de vida tiene que estar entre 0-100\n\n"SC);
        }
    } while (nuevoDragon.vida < 0 || nuevoDragon.vida > 100);

    getchar(); 

    // DAÑO
    do {
        printf(AZUL_C"\tDAÑO: ");
        if (scanf("%d", &nuevoDragon.daño) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.daño < 0 || nuevoDragon.daño > 50) {
            printf(ROJO"\tEl rango de daño tiene que estar entre 0-50\n\n"SC);
        }
    } while (nuevoDragon.daño < 0 || nuevoDragon.daño > 50);

    getchar(); 

    // RESISTENCIA
    do {
        printf(AZUL_C"\tRESISTENCIA: ");
        if (scanf(" %d", &nuevoDragon.resistencia) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.daño < 0 || nuevoDragon.resistencia > 20) {
            printf(ROJO"\tEl rango de resistencia tiene que estar entre 0-20\n\n"SC);
        }
    } while (nuevoDragon.resistencia < 0 || nuevoDragon.resistencia > 20);

    getchar(); 


    // PASIVA
    printf(AZUL_C"\tPASIVA:\n");
    printf(ROJO"\t  1) +25%% resistencia a ataques\n");
    printf(ROJO"\t  2) +25%% daño\n");
    printf(ROJO"\t  3) Se curará un 5%% de su vida después de cada ataque\n");
    printf(ROJO"\t  4) Sin pasiva\n");
    printf(MAGENTA"\tSelección: "SC);
    scanf("%d", &seleccion);
    getchar(); 

    switch (seleccion) {
        case 1:
            strcpy(nuevoDragon.pasiva, SC"+25% resistencia a ataques");
            break;
        case 2:
            strcpy(nuevoDragon.pasiva, SC"+25% daño");
            break;
        case 3:
            strcpy(nuevoDragon.pasiva, SC"Se curará un 5% de su vida después de cada ataque");
            break;
        default:
            strcpy(nuevoDragon.pasiva, SC"Sin pasiva");
            break;
    }

    // DESCRIPCIÓN
    printf(AZUL_C"\tDESCRIPCIÓN: ");
    scanf("%[^\n]", nuevoDragon.descripcion);
    getchar(); 

    // RECOMPENSA 
    do {
        printf(AZUL_C"\tRECOMPENSA: ");
        if (scanf("%d", &nuevoDragon.oro) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.oro < 0 || nuevoDragon.oro > 200) {
            printf(ROJO"\tEl rango de recompensa tiene que estar entre 0-200\n\n"SC);
        }
    } while (nuevoDragon.oro < 0 || nuevoDragon.oro > 200);

    nuevoDragon.id = (*totalDragones) + 1;

    *dragones = (Dragon *)realloc(*dragones, (*totalDragones + 1) * sizeof(Dragon));
    if (*dragones == NULL) {
        printf(ROJO"\tError al asignar memoria\n\n");
        return;
    }

    memcpy(&((*dragones)[*totalDragones]), &nuevoDragon, sizeof(Dragon));

    (*totalDragones)++;

    printf(NARANJA"\n\tDragón agregado:\n");
    mostrarDragon(&nuevoDragon);
}

 void inicializarCazadores(Cazador ** cazadores, int *totalCazadores){
    
    *cazadores = (Cazador*) malloc (*totalCazadores * sizeof(Cazador));
    if (*cazadores == NULL){
        printf("ERROR CATASTRÓFICO: No se pudo asignar memoria.\n");
        exit(EXIT_SUCCESS);} //Salimos con código de error.

    inicializarCazador(&(*cazadores)[0], 1, "Mushashi", "Iaido", 20, 120, 100, "Un caballero audaz y letal, cuya fuerza arrolladora destruye cualquier defensa. Ataca con velocidad y precisión, sin dar tregua a sus enemigos.");
    inicializarCazador(&(*cazadores)[1], 2, "Conan", "Atlantean", 15, 150, 100, "Un caballero imponente y resistente, cuya armadura absorbe cualquier golpe. Avanza sin miedo, protegiendo a sus aliados con su inquebrantable defensa.");
    inicializarCazador(&(*cazadores)[2], 3, "Sauron", "Narsil", 10, 90, 100, "Un sabio y compasivo curandero, cuyo poder restaura heridas y protege a sus aliados. Su magia divina es un faro de esperanza en la batalla.");
 }


void inicializarDragon(Dragon *dragon, int id,  char *nombre, int vida, int daño, int resistencia,  char *pasiva,  char *descripcion, int oro) {
    dragon->id = id;
    strcpy(dragon->nombre, nombre);
    dragon->vida = vida;
    dragon->daño = daño;
    dragon->resistencia = resistencia;
    strcpy(dragon->pasiva, pasiva);
    strcpy(dragon->descripcion, descripcion);
    dragon->oro = oro;
}

void mostrarDragon(Dragon *dragon) {
    printf(ROJO"\tID:"SC" %d\n", dragon->id);
    printf(ROJO"\tNombre:"SC" %s\n", dragon->nombre);
    printf(ROJO"\tVida:"SC" %d\n", dragon->vida);
    printf(ROJO"\tDaño:"SC" %d\n", dragon->daño);
    printf(ROJO"\tResistencia:"SC" %d%%\n", dragon->resistencia);
    printf(ROJO"\tPasiva:"SC" %s\n", dragon->pasiva);
    printf(ROJO"\tDescripción:"SC" %s\n", dragon->descripcion);
    printf(ROJO"\tRecompensa:"SC" %d de oro\n\n", dragon->oro);
}

void visualizarDragones() {
    Dragon *dragones = (Dragon*) malloc(3 * sizeof(Dragon));
    if(dragones == NULL){
        printf("Error al reservar memoria\n");
        exit(EXIT_SUCCESS);
    }

    inicializarDragon(&dragones[0], 1, "Nightmare", 100, 10, 15, "+25% resistencia a ataques", "Nightmare es un dragón proveniente de las pesadillas más oscuras, ningún caballero quiere desafiarle.", 50);
    inicializarDragon(&dragones[1], 2, "Cryonyx", 100, 15, 15, "+25% daño", "Cryonyx es un dragón temido debido a su alto poder, vive en las montañas en solitario desarrollando aún más su fuerza.", 125);
    inicializarDragon(&dragones[2], 3, "Velkhanos", 100, 10, 15, "Se curará un 5% de su vida después de cada ataque", "Velkhanos es un dragón histórico, proveniente de Asia, ningún otro dragón ha podido derrotarle.", 200);

    printf(NARANJA"\nDRAGONES DISPONIBLES:\n"SC);
    system("chafa -f symbols -s 50x30 Nightmare.jpg"); 
    mostrarDragon(&dragones[0]);
    system("chafa -f symbols -s 50x30 Cryonyx.jpg");
    mostrarDragon(&dragones[1]);
    system("chafa -f symbols -s 50x30 Velkhanos.jpg");
    mostrarDragon(&dragones[2]);

    seleccionarDragon(dragones, 3);

    free(dragones);
}

void seleccionarDragon(Dragon *dragones, int totalDragones) {
    int seleccion;
    int valido = 0;

    do {
        printf(NARANJA"Introduzca el ID del dragon con el que va a jugar: ");
        scanf("%d", &seleccion);

        if (seleccion >= 1 && seleccion <= totalDragones) {
            switch(seleccion) {
                case 1:
                    printf("\n\nDragon seleccionado: %d\n", seleccion);
                    printf("\n");
                    system("chafa -f symbols -s 50x30 Nightmare.jpg");
                    break;
                case 2:
                    printf("\n\nDragon seleccionado: %d\n", seleccion);
                    printf("\n");
                    system("chafa -f symbols -s 50x30 Cryonyx.jpg");
                    break;
                case 3:
                    printf("\n\nDragon seleccionado: %d\n", seleccion);
                    printf("\n");
                    system("chafa -f symbols -s 50x30 Velkhanos.jpg");
                    break;
            }

            mostrarDragon(&dragones[seleccion - 1]);

            valido = 1;
        } else {
            printf(ROJO"Has introducido un dragón que no existe.\n\n"SC);
        }
    } while (!valido);
}

// En cazadores.c o juego.c (solo en uno)
void inicializarCazador(Cazador *datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion) {
    datos->ID = ID;
    strncpy(datos->nombre, nombre, MAXNOMBRE);
    strncpy(datos->arma, arma, MAXARMA);
    datos->ataque = ataque;
    datos->vida = vida;
    datos->oro = oro;
    strncpy(datos->descripcion, descripcion, MAXDESCRPCION);
    datos->descripcion[MAXDESCRPCION] = '\0';  // Asegurar terminación segura
}


//VISUALIZAR CAZADOR
void cazadorIMPRIMIR(const Cazador *cazador) {
    printf("\n" AMARILLO "Nombre: %s" SC, cazador->nombre);
    printf("\n" AMARILLO "Arma: %s" SC, cazador->arma);
    printf("\n" AMARILLO "Ataque: %d" SC, cazador->ataque);
    printf("\n" AMARILLO "Vida: %d" SC, cazador->vida);
    printf("\n" AMARILLO "Descripción: %s\n" SC, cazador->descripcion);
}

void cazadorSELEC(Cazador *cazadores, int totalCazadores) {
    int seleccion;

    // Mostrar todos los cazadores disponibles
    do {
        printf(VERDE "\nCazadores disponibles:\n" SC);
        for (int i = 0; i < totalCazadores; i++) {
            printf(AMARILLO "%d. " SC, i + 1);
            cazadorIMPRIMIR(&cazadores[i]); // Pasamos puntero
        }

        printf("\nSelecciona un cazador (1-%d): ", totalCazadores);
        if (scanf("%d", &seleccion) != 1 || seleccion < 1 || seleccion > totalCazadores) {
            printf(ROJO "\tSelección inválida. Intenta nuevamente.\n" SC);
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        } else {
            break;
        }

    } while (1);

    // Mostrar el cazador seleccionado
    printf(GRIS "\nCazador seleccionado:\n" SC);
    cazadorIMPRIMIR(&cazadores[seleccion - 1]); // Pasamos puntero
}

//AÑADIR CAZADORES
void añadirCazador(Cazador **cazadores, int *totalCazadores) {
    int intentos = 3;
    Cazador nuevoCazador;
    printf(AMARILLO "\nIntroduzca los datos del nuevo cazador: \n" SC);

    // ID
    nuevoCazador.ID = *totalCazadores + 1;
    printf(AZUL_C "\t ID:" SC " %d.\n", nuevoCazador.ID);

    // NOMBRE
    do {
        printf(AZUL_C "\t NOMBRE: " SC);
        scanf(" %[^\n]", nuevoCazador.nombre);

        int esValido = 1;
        for (int i = 0; i < strlen(nuevoCazador.nombre); i++) {
            if (isdigit(nuevoCazador.nombre[i])) {
                esValido = 0;
                break;
            }
        }

        if (strlen(nuevoCazador.nombre) < 1 || strlen(nuevoCazador.nombre) > MAXNOMBRE) {
            printf(ROJO "Valor inválido, el nombre no puede ser menor a 1 o mayor a %d.\n" SC, MAXNOMBRE);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

    // ARMA
    do {
        printf(AZUL_C "\t ARMA: " SC);
        scanf(" %[^\n]", nuevoCazador.arma);

        if (strlen(nuevoCazador.arma) < 1 || strlen(nuevoCazador.arma) > MAXARMA) {
            printf(ROJO "Valor inválido, el nombre del arma no puede ser menor a 1 o mayor a %d.\n" SC, MAXARMA);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

    // ATAQUE
    do {
        printf(AZUL_C "\t DAÑO: " SC);

        if (scanf("%d", &nuevoCazador.ataque) != 1) {
            printf(ROJO "Entrada inválida. Debe ingresar un número.\n" SC);
            while (getchar() != '\n');
            intentos--;
        } else if (nuevoCazador.ataque < 1 || nuevoCazador.ataque > MAXATAQUE) {
            printf(ROJO "Valor inválido, el ataque no puede ser menor a 1 o mayor a %d.\n" SC, MAXATAQUE);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

    // VIDA
    do {
        printf(AZUL_C "\t VIDA: " SC);

        if (scanf("%d", &nuevoCazador.vida) != 1) {
            printf(ROJO "Entrada inválida. Debe ingresar un número.\n" SC);
            while (getchar() != '\n');
            intentos--;
        } else if (nuevoCazador.vida < 1 || nuevoCazador.vida > MAXVIDA) {
            printf(ROJO "Valor inválido, la vida no puede ser menor a 1 o mayor a %d.\n" SC, MAXVIDA);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

    // ORO (valor fijo)
    nuevoCazador.oro = 100;
    printf(AZUL_C "\t ORO:" SC " %d monedas.\n", nuevoCazador.oro);

    // DESCRIPCIÓN
    do {
        printf(AZUL_C "\t DESCRIPCIÓN: " SC);
        scanf(" %[^\n]", nuevoCazador.descripcion);

        if (strlen(nuevoCazador.descripcion) < 1 || strlen(nuevoCazador.descripcion) > MAXDESCRPCION) {
            printf(ROJO "Valor inválido, la descripción no puede ser menor a 1 o mayor a %d.\n" SC, MAXDESCRPCION);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

    // **Asigna memoria para el nuevo cazador**
    Cazador *temp = realloc(*cazadores, (*totalCazadores + 1) * sizeof(Cazador));
    if (temp == NULL) {
        printf(ROJO "ERROR CATASTRÓFICO. No se pudo asignar memoria.\n" SC);
        free(*cazadores);
        exit(EXIT_FAILURE);
    }
    *cazadores = temp;

    // **Añadir el nuevo cazador al array**
    (*cazadores)[*totalCazadores] = nuevoCazador;
    (*totalCazadores)++;

    // **Imprimir cazador añadido**
    printf(NARANJA "\nCAZADOR AGREGADO:\n" SC);
    cazadorIMPRIMIR(&(*cazadores)[*totalCazadores - 1]);
}


 void BIENVENIDA(){
    system("clear");
    system("chafa -f symbols -s 90x50 Erebor.jpg");
    printf(CURSIVA"Tras la caída del gran dragón codicioso, los cielos sobre la Montaña Solitaria permanecieron en silencio por generaciones. Sin embargo, los ecos de su avaricia no desaparecieron tras su muerte a manos de Bardo. Los hijos del monstruo, nacidos en las sombras de su padre, regresan ahora, decididos a reclamar lo que consideran suyo: el oro que una vez perteneció al rey enano Thráin II.\n"

        "\nEl tesoro, una vez custodiado por un solo ser, ahora se ve protegido por una legión de dragones con la misma insaciable hambre que su antecesor. La Montaña, que guardó el silencio por tanto tiempo, vuelve a rugir con la furia de aquellos que ansían lo que no les pertenece.\n"

        "\nLos cazadores, sabiendo que esta vez el desafío es aún mayor, se preparan para enfrentar a una fuerza más peligrosa que cualquier que hayan conocido. No luchan solo por el oro, sino por evitar que la sombra de la codicia del dragón se apodere nuevamente de la tierra.\n\n"SC);
    }

//MENÚ
int totalCazadores;

 void MENU(){
    Cazador *cazadores = NULL;//Tenemos que inicializar el puntero donde vamos a guradar a los cazadores en el main, como todavía no tiene 'nada', lo inicializamos en nulo.
    inicializarCazadores(&cazadores, &totalCazadores);

    int opcion;

    printf(MAGENTA"\t MENÚ: \n"
            AZUL_C"\t 1) Seleccionar un cazador.\n"
                  "\t 2) Añadir cazador.\n"
                  "\t 3) Salir.\n"SC
           MAGENTA"\t OPCIÓN: "SC);
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            cazadorSELEC(cazadores, totalCazadores);  // Llamada a la función definida en cazador.c
            break;
        case 2:
            añadirCazador(&cazadores, &totalCazadores);
            break;
        case 3:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción inválida.\n");
            break;
    }
 free (cazadores);
 }


int main() {
    int opcion;
    Dragon *dragones = NULL; 
    Cazador *cazadores = NULL;

    int totalDragones = 0;
    int totalCazadores = 3;
  
    BIENVENIDA();
    MENU();

    printf(MAGENTA"\tMENÚ:\n");
    printf(AZUL_C"\t1) Seleccionar un dragón predefinido\n");
    printf(AZUL_C"\t2) Crear un nuevo dragón\n");
    printf(AZUL_C"\t3) Salir\n");
    printf(MAGENTA"\tSeleccion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            visualizarDragones();
            break;

        case 2:
            añadir_dragon(&dragones, &totalDragones);
            break;

        case 3:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción inválida.\n");
            break;
    }

    free(dragones);
    free(cazadores);
    return 0;
}

