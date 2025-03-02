#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMBRE 50
#define MAX_DESCRIPCION 1000
#define MAX_DRAGONES 3
#define MAXNOMBRE 50
#define MAXARMA 20
#define MAXATAQUE 20
#define MAXVIDA 100
#define MAXORO 600
#define MAXDESCRIPCION 200
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
#define CURSIVA   "\033[3m"

// Reset (para volver al color original)
#define SC        "\033[0m"

typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    int vida;
    int ataque;
    int resistencia;
    char pasiva[MAX_DESCRIPCION];
    char descripcion[MAX_DESCRIPCION];
    int oro;
} Dragon;


typedef struct {
    int ID;
    char nombre[MAXNOMBRE + 1];
    char arma[MAXARMA + 1];
    int ataque;
    int vida;
    int oro;
    int defensa;
    char descripcion[MAXDESCRIPCION + 1];
} Cazador;

void comenzarBatalla(Cazador *cazador, Dragon *dragon);
void inicializarCazador(Cazador *datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion);
void cazadorIMPRIMIR(const Cazador *cazador_a_imprimir);
void inicializarCazadores(Cazador **cazadores, int *totalCazadores);
Cazador* cazadorSELEC(Cazador *cazadores, int totalCazadores);
void añadirCazador(Cazador **cazadores, int *totalCazadores);
void inicializarDragon(Dragon *dragon, int id, char *nombre, int vida, int ataque, int resistencia, char *pasiva, char *descripcion, int oro);
void mostrarDragon(Dragon *dragon);
Dragon* seleccionarDragon(Dragon *dragones, int totalDragones); 
Dragon* visualizarDragones(Dragon **dragones, int *totalDragones); 
void añadir_dragon(Dragon **dragones, int *totalDragones);
Cazador* MENU(Cazador **cazadores, int *totalCazadores);

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

    // ataque
    do {
        printf(AZUL_C"\tataque: ");
        if (scanf("%d", &nuevoDragon.ataque) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.ataque < 0 || nuevoDragon.ataque > 50) {
            printf(ROJO"\tEl rango de ataque tiene que estar entre 0-50\n\n"SC);
        }
    } while (nuevoDragon.ataque < 0 || nuevoDragon.ataque > 50);

    getchar(); 

    // RESISTENCIA
    do {
        printf(AZUL_C"\tRESISTENCIA: ");
        if (scanf(" %d", &nuevoDragon.resistencia) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.ataque < 0 || nuevoDragon.resistencia > 20) {
            printf(ROJO"\tEl rango de resistencia tiene que estar entre 0-20\n\n"SC);
        }
    } while (nuevoDragon.resistencia < 0 || nuevoDragon.resistencia > 20);

    getchar(); 


    // PASIVA
    printf(AZUL_C"\tPASIVA:\n");
    printf(ROJO"\t  1) +25%% resistencia a ataques\n");
    printf(ROJO"\t  2) +25%% ataque\n");
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
            strcpy(nuevoDragon.pasiva, SC"+25% ataque");
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

    Dragon *temp = (Dragon *)realloc(*dragones, (*totalDragones + 1) * sizeof(Dragon));
    if (temp == NULL) {
     printf(ROJO"\tError al asignar memoria\n\n");
      return;
    }
    *dragones = temp;

    memcpy(&((*dragones)[*totalDragones]), &nuevoDragon, sizeof(Dragon));

    (*totalDragones)++;

    printf(NARANJA"\n\tDragón agregado:\n");
    mostrarDragon(&nuevoDragon);
}

void inicializarCazadores(Cazador **cazadores, int *totalCazadores) {
    *totalCazadores = 3; // Número total de cazadores

    *cazadores = (Cazador *)malloc(*totalCazadores * sizeof(Cazador));
    if (*cazadores == NULL) {
        printf("ERROR CATASTRÓFICO: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializando los cazadores
    inicializarCazador(&(*cazadores)[0], 1, "Mushashi", "Iaido", 20, 120, 100, "Un caballero audaz y letal...");
    inicializarCazador(&(*cazadores)[1], 2, "Conan", "Atlantean", 15, 150, 100, "Un guerrero con fuerza colosal...");
    inicializarCazador(&(*cazadores)[2], 3, "Jeremias", "Yari", 10, 200, 100, "Un estratega con gran resistencia...");
}

void inicializarDragon(Dragon *dragon, int id,  char *nombre, int vida, int ataque, int resistencia,  char *pasiva,  char *descripcion, int oro) {
    dragon->id = id;
    strcpy(dragon->nombre, nombre);
    dragon->vida = vida;
    dragon->ataque = ataque;
    dragon->resistencia = resistencia;
    strcpy(dragon->pasiva, pasiva);
    strcpy(dragon->descripcion, descripcion);
    dragon->oro = oro;
}

void mostrarDragon(Dragon *dragon) {
    printf(ROJO"\tID:"SC" %d\n", dragon->id);
    printf(ROJO"\tNombre:"SC" %s\n", dragon->nombre);
    printf(ROJO"\tVida:"SC" %d\n", dragon->vida);
    printf(ROJO"\tataque:"SC" %d\n", dragon->ataque);
    printf(ROJO"\tResistencia:"SC" %d%%\n", dragon->resistencia);
    printf(ROJO"\tPasiva:"SC" %s\n", dragon->pasiva);
    printf(ROJO"\tDescripción:"SC" %s\n", dragon->descripcion);
    printf(ROJO"\tRecompensa:"SC" %d de oro\n\n", dragon->oro);
}

Dragon* visualizarDragones(Dragon **dragones, int *totalDragones) {
    *totalDragones = 3;
    *dragones = (Dragon*)malloc(3 * sizeof(Dragon));
    if (*dragones == NULL) {
        printf("Error al reservar memoria\n");
        exit(EXIT_FAILURE);
    }

    inicializarDragon(&(*dragones)[0], 1, "Nightmare", 100, 10, 15, "+25% resistencia a ataques", "Nightmare es un dragón...", 50);
    inicializarDragon(&(*dragones)[1], 2, "Cryonyx", 100, 15, 15, "+25% ataque", "Cryonyx es un dragón temido...", 125);
    inicializarDragon(&(*dragones)[2], 3, "Velkhanos", 100, 10, 15, "Se curará un 5%...", "Velkhanos es un dragón histórico...", 200);

    printf(NARANJA"\nDRAGONES DISPONIBLES:\n"SC);
    system("chafa -f symbols -s 50x30 Nightmare.jpg"); 
    mostrarDragon(&(*dragones)[0]);  // Corregido
    system("chafa -f symbols -s 50x30 Cryonyx.jpg");
    mostrarDragon(&(*dragones)[1]);  // Corregido
    system("chafa -f symbols -s 50x30 Velkhanos.jpg");
    mostrarDragon(&(*dragones)[2]);  // Corregido

    return seleccionarDragon(*dragones, *totalDragones); // Devolvemos el dragón seleccionado
}

Dragon* seleccionarDragon(Dragon *dragones, int totalDragones) {
    int seleccion;
    int valido = 0;

    do {
        printf(NARANJA"Introduzca el ID del dragón con el que va a jugar: "SC);
        scanf("%d", &seleccion);
        while (getchar() != '\n'); // Limpiar buffer

        if (seleccion >= 1 && seleccion <= totalDragones) {
            switch (seleccion) {
                case 1:
                    printf("\n\nDragón seleccionado: %d\n", seleccion);
                    system("chafa -f symbols -s 50x30 Nightmare.jpg");
                    break;
                case 2:
                    printf("\n\nDragón seleccionado: %d\n", seleccion);
                    system("chafa -f symbols -s 50x30 Cryonyx.jpg");
                    break;
                case 3:
                    printf("\n\nDragón seleccionado: %d\n", seleccion);
                    system("chafa -f symbols -s 50x30 Velkhanos.jpg");
                    break;
            }
            mostrarDragon(&dragones[seleccion - 1]);
            valido = 1;
            return &dragones[seleccion - 1]; // Devolvemos el dragón seleccionado
        } else {
            printf(ROJO"Has introducido un dragón que no existe.\n\n"SC);
        }
    } while (!valido);

    return NULL; // Nunca debería llegar aquí
}

// En cazadores.c o juego.c (solo en uno)
void inicializarCazador(Cazador *datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion) {
    datos->ID = ID;
    strncpy(datos->nombre, nombre, sizeof(datos->nombre) - 1);
    datos->nombre[sizeof(datos->nombre) - 1] = '\0';
    strncpy(datos->arma, arma, sizeof(datos->arma) - 1);
    datos->arma[sizeof(datos->arma) - 1] = '\0';
    strncpy(datos->descripcion, descripcion, sizeof(datos->descripcion) - 1);
    datos->descripcion[sizeof(datos->descripcion) - 1] = '\0';
    datos->ataque = ataque;
    datos->vida = vida;
    datos->oro = oro;
    datos->defensa = 0; // Valor por defecto
}


//VISUALIZAR CAZADOR
void cazadorIMPRIMIR(const Cazador *cazador_a_imprimir){
    printf(NARANJA"\nID: %d\n", cazador_a_imprimir->ID);
    printf("\nNombre: %s\n", cazador_a_imprimir->nombre);
    printf("\nArma: %s\n", cazador_a_imprimir->arma);
    printf("\nAtaque: %d\n", cazador_a_imprimir->ataque);
    printf("\nVida: %d\n", cazador_a_imprimir->vida);
    printf("\nOro: %d\n", cazador_a_imprimir->oro);
    printf("\nDescripción: %s\n", cazador_a_imprimir->descripcion);
}

 Cazador* cazadorSELEC(Cazador *cazadores, int totalCazadores) {
    int intentos = 3;
    int cazadorACTIVO;

    printf(NARANJA"\nCAZADORES DISPONIBLES: \n"SC);

    system("chafa -f symbols -s 50x30 Mushashi.jpg");
    cazadorIMPRIMIR(&cazadores[0]);
    system("chafa -f symbols -s 50x30 Conan.jpg");
    cazadorIMPRIMIR(&cazadores[1]);
    system("chafa -f symbols -s 50x30 Sauron.jpg");
    cazadorIMPRIMIR(&cazadores[2]);

    do {
        printf(NARANJA"\n\nIntroduzca el ID del cazador con el que va a jugar: "SC);
        if (scanf("%d", &cazadorACTIVO) != 1) {
            printf(ROJO"Entrada inválida. Debe ingresar un número.\n"SC);
            while (getchar() != '\n');
            intentos--;
        } else if (cazadorACTIVO < 1 || cazadorACTIVO > totalCazadores) {
            printf(ROJO"El ID del primer cazador es 1 y el último es %d.\n"SC, totalCazadores);
            intentos--;
        } else {
            if (cazadorACTIVO == 1) {
                system("chafa -f symbols -s 50x30 Mushashi.jpg");
            } else if (cazadorACTIVO == 2) {
                system("chafa -f symbols -s 50x30 Conan.jpg");
            } else if (cazadorACTIVO == 3) {
                system("chafa -f symbols -s 50x30 Sauron.jpg");
            }
            cazadorIMPRIMIR(&cazadores[cazadorACTIVO - 1]);
            return &cazadores[cazadorACTIVO - 1]; // Devolvemos el cazador seleccionado
        }

        if (intentos == 0) {
            printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n"SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

    return NULL; // Nunca debería llegar aquí, pero por seguridad
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
        printf(AZUL_C "\t ataque: " SC);

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

        if (strlen(nuevoCazador.descripcion) < 1 || strlen(nuevoCazador.descripcion) > MAXDESCRIPCION) {
            printf(ROJO "Valor inválido, la descripción no puede ser menor a 1 o mayor a %d.\n" SC, MAXDESCRIPCION);
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

    Cazador *REALLOC_TEMP = (Cazador*) realloc(*cazadores, (*totalCazadores + 1) * sizeof(Cazador));
    if (REALLOC_TEMP == NULL) {
        printf("ERROR: No se pudo asignar memoria para el nuevo cazador.\n");
        exit(EXIT_FAILURE);
    }
    *cazadores = REALLOC_TEMP;  // Solo si realloc fue exitoso


    // **Añadir el nuevo cazador al array**
    (*cazadores)[*totalCazadores] = nuevoCazador;
    (*totalCazadores)++;

    // **Imprimir cazador añadido**
    printf(NARANJA "\nCAZADOR AGREGADO:\n" SC);
    cazadorIMPRIMIR(&(*cazadores)[*totalCazadores - 1]);
}


void BIENVENIDA() {
    system("clear");
    system("chafa -f symbols -s 90x50 Erebor.jpg");
    printf(CURSIVA"Tras la caída del gran dragón codicioso, los cielos sobre la Montaña Solitaria permanecieron en silencio por generaciones. Sin embargo, los ecos de su avaricia no desaparecieron tras su muerte a manos de Bardo. Los hijos del monstruo, nacidos en las sombras de su padre, regresan ahora, decididos a reclamar lo que consideran suyo: el oro que una vez perteneció al rey enano Thráin II.\n"

        "\nEl tesoro, una vez custodiado por un solo ser, ahora se ve protegido por una legión de dragones con la misma insaciable hambre que su antecesor. La Montaña, que guardó el silencio por tanto tiempo, vuelve a rugir con la furia de aquellos que ansían lo que no les pertenece.\n"

        "\nLos cazadores, sabiendo que esta vez el desafío es aún mayor, se preparan para enfrentar a una fuerza más peligrosa que cualquier que hayan conocido. No luchan solo por el oro, sino por evitar que la sombra de la codicia del dragón se apodere nuevamente de la tierra.\n\n"SC);
}



 // Función para simular la batalla
void comenzarBatalla(Cazador *cazador, Dragon *dragon) {
    printf(NARANJA "\n¡La batalla comienza entre %s (Cazador) y %s (Dragón)!\n" SC, cazador->nombre, dragon->nombre);
}

int totalCazadores;

Cazador* MENU(Cazador **cazadores, int *totalCazadores) {
    int opcion;
    Cazador *cazadorSeleccionado = NULL;

    printf(MAGENTA"\t MENÚ: \n"
           AZUL_C"\t 1) Seleccionar un cazador.\n"
                 "\t 2) Añadir cazador.\n"
                 "\t 3) Salir.\n"SC
           MAGENTA"\t OPCIÓN: "SC);
    scanf("%d", &opcion);
    while (getchar() != '\n'); // Limpiar buffer

    switch (opcion) {
        case 1:
            cazadorSeleccionado = cazadorSELEC(*cazadores, *totalCazadores); // Guardamos el cazador seleccionado
            break;
        case 2:
            añadirCazador(cazadores, totalCazadores);
            cazadorSeleccionado = &(*cazadores)[*totalCazadores - 1]; // El último cazador añadido
            break;
        case 3:
            printf("Saliendo...\n");
            return NULL; // Indicamos que no se seleccionó nada
        default:
            printf("Opción inválida.\n");
            break;
    }

    return cazadorSeleccionado; // Devolvemos el cazador seleccionado
}

int main() {
    Dragon *dragones = NULL;
    Cazador *cazadores = NULL;
    int totalDragones = 0;
    int totalCazadores = 0;
    int opcion;

    BIENVENIDA();
    inicializarCazadores(&cazadores, &totalCazadores);

    // Paso 1: Seleccionar cazador
    Cazador *cazadorSeleccionado = MENU(&cazadores, &totalCazadores);
    if (cazadorSeleccionado == NULL) {
        printf(ROJO"No se seleccionó un cazador. Saliendo...\n"SC);
        free(dragones);
        free(cazadores);
        return 0;
    }

    // Paso 2: Seleccionar dragón
    Dragon *dragonSeleccionado = NULL;
    printf(MAGENTA"\tMENÚ DE DRAGONES:\n"SC);
    printf(AZUL_C"\t1) Seleccionar un dragón predefinido\n");
    printf(AZUL_C"\t2) Crear un nuevo dragón\n");
    printf(AZUL_C"\t3) Salir\n");
    printf(MAGENTA"\tSelección: "SC);
    scanf("%d", &opcion);
    while (getchar() != '\n'); // Limpiar buffer

    switch (opcion) {
        case 1:
            dragonSeleccionado = visualizarDragones(&dragones, &totalDragones); // Solo esta línea
            break;
        case 2:
            añadir_dragon(&dragones, &totalDragones);
            dragonSeleccionado = &dragones[totalDragones - 1]; // El último dragón añadido
            break;
        case 3:
            printf("Saliendo...\n");
            free(dragones);
            free(cazadores);
            return 0;
        default:
            printf("Opción inválida.\n");
            break;
    }

    // Paso 3: Iniciar batalla con los seleccionados
    if (cazadorSeleccionado != NULL && dragonSeleccionado != NULL) {
        comenzarBatalla(cazadorSeleccionado, dragonSeleccionado);
    } else {
        printf(ROJO"Error: No se seleccionaron cazador y/o dragón correctamente.\n"SC);
    }

    free(dragones);
    free(cazadores);
    return 0;
}


