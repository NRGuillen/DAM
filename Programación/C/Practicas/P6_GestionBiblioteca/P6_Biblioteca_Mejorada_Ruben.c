#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TITULO 80 //Defino el tamaño del titulo, no puede tener mas de 80 caracteres
#define MAX_AUTOR 50 //Defino el tamaño del autor, el nombre del autor no puede tener mas de 50 caracteres
#define MAX_LIBROS 40 //Defino la cantidad de libros, la biblioteca puede contener 40 libros



typedef enum {
    FICTION, 
    NON_FICTION,
    POETRY,
    THEATER,
    ESSAY,
} Categoria;

typedef struct {
    int ID; //ID de cada libro
    char titulo[MAX_TITULO]; //Almacena el titulo de cada libro hasta 80 caracteres por el MAX_TITULO
    char autor[MAX_AUTOR]; //Almacena el nombre de cada autor hasta 50 caracteres por el MAX_AUTOR
    float precio; //Precio de cada libro en float por los precios decimales
    Categoria categoria; //Variable que almacena los valores definidos en el typedef de Categoria

    /*
                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

                                                        ¿Porque Categoria no se pone dentro del tydef?

        Categoria esta definiendo un cojunto de valores constantes, en este caso las categorias, no van a cambiar siempre seran  FICTION NON_FICTION 
        POETRY THEATER ESSAY.
        El typdef Categoria es independiente a Libro, por lo que se puede reutilizar en partes diferentes del probrama.
        Si lo ponemos dentro de Libro limitariamos su uso y no seria eficiente para utilizarlo en otras lineas del programa.
 
    */
    

    int cantidad; //Cantidad de cada libro en la biblioteca, es decir libro 1 = 20 libros, libro 2 = 3 libros...
} Libro; //Nombre de la estructura que va a representar un libro en la biblioteca

void inicializarLibro(Libro *libro, int id, const char *titulo, const char *autor, float precio, Categoria categoria, int cantidad);
void imprimirSoloUnLibro(Libro *biblioteca);
void mostrarTodosLosLibros(Libro *biblioteca, int totalLibros);
void mostrarLibro(Libro *biblioteca, int totalLibros, int id);
void mostrarCantidadLibros(Libro *biblioteca, int totalLibros, int id);
void añadirCantidadLibro(Libro *biblioteca, int totalLibros, int id, int cantidad);
void mostrarLibrosPorCategoria(Libro *biblioteca, int totalLibros, Categoria categoria);
void mostrarAutor(Libro *biblioteca, int totalLibros, const char *nombreAutor);
void añadirNuevoLibro(Libro **biblioteca, int *totalLibros);

//inicializarLibro, sirve para asignar los valores a la estructura Libro (a la memoria dinamica).

int main(int argc, char*argv[]) {
    printf("Lista de Argumentos: \n");
    for (int i = 0; i < argc; i++) {
        printf("\t Argumento %d: %s\n", i+1, argv[i]);
    }

    Libro *biblioteca = (Libro*) malloc(40 * sizeof(Libro)); 
    int totalLibros = MAX_LIBROS; 

    inicializarLibro(&biblioteca[0], 1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10);
    inicializarLibro(&biblioteca[1], 2, "1984", "George Orwell", 12.49, FICTION, 5);
    inicializarLibro(&biblioteca[2], 3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8);
    inicializarLibro(&biblioteca[3], 4, "Moby Dick", "Herman Melville", 18.99, FICTION, 12);
    inicializarLibro(&biblioteca[4], 5, "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7);
    inicializarLibro(&biblioteca[5], 6, "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9);
    inicializarLibro(&biblioteca[6], 7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6);
    inicializarLibro(&biblioteca[7], 8, "The Odyssey", "Homer", 17.49, FICTION, 4);
    inicializarLibro(&biblioteca[8], 9, "Ulysses", "James Joyce", 25.00, FICTION, 2);
    inicializarLibro(&biblioteca[9], 10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3);
    inicializarLibro(&biblioteca[10], 11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11);
    inicializarLibro(&biblioteca[11], 12, "The Iliad", "Homer", 18.50, FICTION, 7);
    inicializarLibro(&biblioteca[12], 13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15);
    inicializarLibro(&biblioteca[13], 14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20);
    inicializarLibro(&biblioteca[14], 15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13);
    inicializarLibro(&biblioteca[15], 16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6);
    inicializarLibro(&biblioteca[16], 17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5);
    inicializarLibro(&biblioteca[17], 18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8);
    inicializarLibro(&biblioteca[18], 19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4);
    inicializarLibro(&biblioteca[19], 20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14);
    inicializarLibro(&biblioteca[20], 21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6);
    inicializarLibro(&biblioteca[21], 22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8);
    inicializarLibro(&biblioteca[22], 23, "Othello", "William Shakespeare", 10.99, THEATER, 7);
    inicializarLibro(&biblioteca[23], 24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5);
    inicializarLibro(&biblioteca[24], 25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4);
    inicializarLibro(&biblioteca[25], 26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10);
    inicializarLibro(&biblioteca[26], 27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9);
    inicializarLibro(&biblioteca[27], 28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3);
    inicializarLibro(&biblioteca[28], 29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15);
    inicializarLibro(&biblioteca[29], 30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10);
    inicializarLibro(&biblioteca[30], 31, "Paradise Lost", "John Milton", 12.00, POETRY, 7);
    inicializarLibro(&biblioteca[31], 32, "Beowulf", "Anonymous", 15.00, POETRY, 5);
    inicializarLibro(&biblioteca[32], 33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4);
    inicializarLibro(&biblioteca[33], 34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9);
    inicializarLibro(&biblioteca[34], 35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11);
    inicializarLibro(&biblioteca[35], 36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8);
    inicializarLibro(&biblioteca[36], 37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5);
    inicializarLibro(&biblioteca[37], 38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12);
    inicializarLibro(&biblioteca[38], 39, "The Republic", "Plato", 16.00, ESSAY, 6);
    inicializarLibro(&biblioteca[39], 40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 10);

    /*
                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

                                        ./miPrograma argumento1 argumento2 123
                                            En este caso:
                                            argc será 4.

                                            argv[0] será "./miPrograma" (el nombre del programa).
                                            argv[1] será "argumento1".
                                            argv[2] será "argumento2".
                                            argv[3] será "123".

                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

                                        argc es el número total de argumentos que se pasan al programa al ejecutarlo, incluyendo el nombre del programa mismo
                                        
                                        ./biblioteca seria argc[1]

                                        argv es un arreglo de cadenas de caracteres, que contiene los argumentos 
                                        pasados al programa, empezando desde el índice 0.

                                        ./biblioteca seria argv[0]
    */


    printf("\n<-- Instrucciones para utilizar el programa -->\n\n");
    printf("Para seguir estas intrucciones debes de compilar el programa con el nombre P6_GestionBiblioteca_RubenGuillenRojas\n\n");
    printf("\t Para visualizar toda la biblioteca ./P6_GestionBiblioteca_RubenGuillenRojas mostrar\n");
    printf("\t Para visualizar un solo libro ./P6_GestionBiblioteca_RubenGuillenRojas mostrar [ID del libro]\n");
    printf("\t Para añadir sotck a un libro ./P6_GestionBiblioteca_RubenGuillenRojas stock [ID del libro] [Cantidad a añadir]\n");
    printf("\t Para visualizar todos los libros de una categoria ./P6_GestionBiblioteca_RubenGuillenRojas categoria [0 -> FICTION, 1 -> NON_FICTION, 2 -> POETRY, 3 -> THEATER, 4 -> ESSAY]\n");
    printf("\t Para visualizar un libro por autor ./P6_GestionBiblioteca_RubenGuillenRojas autor [nombre del autor]\n");
    printf("\t Para añadir un libro a la biblioteca ./P6_GestionBiblioteca_RubenGuillenRojas añadir\n\n");

// Verifica que se haya pasado al menos un argumento al programa


if (argc < 2) {
    printf("Has introducido un comando erroneo.\n");
    return 1;
}

// Comando "mostrar"
if (strcmp(argv[1], "mostrar") == 0) {
        // Si solo hay dos argumentos, muestra todos los libros

    if (argc == 2) { 
        mostrarTodosLosLibros(biblioteca, totalLibros); 
    }
        // Si hay tres argumentos, muestra un libro especifico por ID

    else if (argc == 3) { 
        int id = atoi(argv[2]); // Convierte el tercer argumento a entero
        mostrarLibro(biblioteca, totalLibros, id);
    } 
        // Si el numero de argumentos no es valido

    else { 
        printf("Has introducido un comando erroneo.\n");
    }
}

// Comando "stock"

else if (strcmp(argv[1], "stock") == 0) {
        // Si hay cuatro argumentos, actualiza el stock de un libro

    if (argc == 4) { 
        int id = atoi(argv[2]); // Convierte el segundo argumento a entero (ID)
        int cantidad = atoi(argv[3]); // Convierte el tercer argumento a entero (cantidad)
        añadirCantidadLibro(biblioteca, totalLibros, id, cantidad);
    } 
        // Si el numero de argumentos no es valido

    else { 
        printf("Has introducido un comando erroneo.\n");
    }
}


// Comando "categoria"

else if (strcmp(argv[1], "categoria") == 0) {
        // Si hay tres argumentos, muestra los libros de una categoría específica

    if (argc == 3) { 
        if(strcmp(argv[2], "0") == 0 || strcmp (argv[2], "1") == 0 || strcmp (argv[2], "2") == 0 || strcmp (argv[2], "3") == 0 || strcmp (argv[2], "4") == 0){

        int categoria = atoi(argv[2]); // Convierte el segundo argumento a entero (categoria)
        if(categoria > 5 || categoria < 0){
            printf("Introduce un numero valido entre 0-5\n");
            return 0;
        }
    
        mostrarLibrosPorCategoria(biblioteca, totalLibros, categoria);
    }else{
        printf("\nValor invalido introduce un numero entre 0-4\n\n");
    }
}
        // Si el numero de argumentos no es valido

    else { 
        printf("Has introducido un comando erroneo.\n");
    }
}

// Comando 

else if (strcmp(argv[1], "autor") == 0) {
        // Si hay tres argumentos, muestra los libros de un autor especifico

    if (argc == 3) { 
            const char *nombreAutor = argv[2]; // Toma el nombre del autor directamente como cadena
            mostrarAutor(biblioteca, totalLibros, nombreAutor);
         }
    
        // Si el numero de argumentos no es valido

    else { 
        printf("Has introducido un comando erroneo.\n");
    }
}

// Comando "añadir"

else if (strcmp(argv[1], "añadir") == 0) {
    // Añade un nuevo libro a la biblioteca
    añadirNuevoLibro(&biblioteca, &totalLibros);
}
// Si el comando no coincide con ninguno de los anteriores

else {
    printf("Has introducido un comando erroneo.\n");
}

// Liberamos la memoria al finalizar

free(biblioteca);
return 0;

}

void inicializarLibro(Libro *libro, int id, const char *titulo, const char *autor, float precio, Categoria categoria, int cantidad) {
    libro->ID = id; //  con libro->ID, estamos accediendo al campo ID del Libro y le asignamos el valor de id
    strncpy(libro->titulo, titulo, MAX_TITULO); // strncpy copia una cadena de caracteres (titulo) a otra (libro->titulo), con el limite de MAX_TITULO (80)
    strncpy(libro->autor, autor, MAX_AUTOR);
    libro->precio = precio;
    libro->categoria = categoria;
    libro->cantidad = cantidad;
}

void imprimirSoloUnLibro(Libro *biblioteca) { //Libro *biblioteca es un puntero que esta apuntando al struct de Libro

   /*
            Para acceder a los datos del struct se puede hacer de dos formas o con "->" o con ".ID".
            En mi caso utilizo el  .ID ya que lo entiendo mejor pero tambien podria ser con "printf("ID: %d\n", biblioteca->ID)";
    */

                                                                   /*<-------TAMBIEN ES VALIDO------->*/

            printf("\tID: %d\n", (*biblioteca).ID);                        //printf("ID: %d\n", biblioteca->ID);
            printf("\tTitulo: %s\n", (*biblioteca).titulo);                //printf("ID: %d\n", biblioteca->titulo);
            printf("\tAutor: %s\n", (*biblioteca).autor);                  //printf("ID: %d\n", biblioteca->autor);
            printf("\tPrecio: %.2f\n", (*biblioteca).precio);              //printf("ID: %d\n", biblioteca->precio);
            printf("\tCategoria: %d\n", (*biblioteca).categoria);          //printf("ID: %d\n", biblioteca->categoria); 
            printf("\tCantidad disponible: %d\n", (*biblioteca).cantidad); //printf("ID: %d\n", biblioteca->cantidad);
            printf("\n");
/*
                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

                    ¿Cual es la diferencia entre  printf("\tID: %d\n", (*biblioteca).ID)     y     printf("ID: %d\n", biblioteca->ID)
                    
                    printf("\tID: %d\n", (*biblioteca).ID)
                    ##Se usa para acceder a los campos de una estructura##
                    biblioteca es un puntero a una estructura Libro, obtiene el valor de la estructura a la que apunta
                    ID accede a la variable ID 
                    printf("\tID: %d\n", (*biblioteca).ID); imprime el valor del campo ID de la estructura.


                    printf("ID: %d\n", biblioteca->ID)
                    ##Hace lo mismo pero es mas visual y abreviado##
                    biblioteca->ID es una forma más corta de escribir (*biblioteca).ID. 
                    El operador -> es una forma para acceder a las variables de una estructura a través de un puntero.

                    CONCLUSION: Hacen la misma funcion, la diferencia es que uno es mas abreviado que el otro.

            */


}

void mostrarTodosLosLibros(Libro *biblioteca, int cantidadLibros) {/*
                                                                 Libro *biblioteca es un puntero que esta apuntando a los datos de los libros
                                                                 LLamo al totalLibros(del main) para indicar el limite de libros que hay, en este caso 40.
                                                                 ¿Como se si la variable biblioteca apunta a un solo libro o al array completo? No se puede.
                                                                 */
    if (cantidadLibros == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    for (int i = 0; i < cantidadLibros; i++) {                                                           //############################       
        printf("\n");                                                                                    //####CON AYUDA DE CHATGPT####
        printf("ID %d:\n", i + 1);                                                                       //############################

        printf("Titulo: %s\n", biblioteca[i].titulo[0] != '\0' ? biblioteca[i].titulo : "Sin título"); // Si el primer caracter de titulo no es '\0' (lo que significa que el título no esta vacio), se imprime el titulo del libro (biblioteca[i].titulo).
                                                                                                       //Si el titulo está vacío (es decir, el primer caracter de titulo es '\0'), entonces se imprime "Sin título".
        printf("Autor: %s\n", biblioteca[i].autor[0] != '\0' ? biblioteca[i].autor : "Desconocido"); // Lo mismo para el de arriba
        printf("Precio: %.2f\n", biblioteca[i].precio);//biblioteca[i] accede al arreglo de biblioteca, i indica la posicion y precio le permite acceder al struc Libro
        printf("Categoria: %d\n", biblioteca[i].categoria);//biblioteca[i] accede al arreglo de biblioteca, i indica la posicion y categoria es el typdef, es decir 0,1,2,3,4
        printf("\n");
    }
}

void mostrarLibro(Libro *biblioteca, int totalLibros, int id) { // Muestra un libro por ID

                                                                    /*
                                                                Libro *biblioteca es un puntero que esta apuntando a los datos de los libros.
                                                                LLamo al totalLibros(del main) para indicar el limite de libros que hay, en este caso 40.
                                                                LLamo al id(del main) para buscar el libro a traves del identificador.
                                                                */                                                          

    if (id < 1 || id > totalLibros) { //si el id introducido es menor a 1, es incorreto y si es mayor al totalLibros(40) tambien sera incorrecto
        printf("El ID ingresado no es válido. Debe estar entre 1 y %d.\n", totalLibros);
    }
    
    for (int i = 0; i < totalLibros; i++) { //Bucle que recorre desde el 0 hasta el 40.
        if ((biblioteca + i)->ID == id) { //Este if compara la ID de la lista, con el id introducido del usuario

    /*
                                        (biblioteca + i) apunta a la posicion i de la biblioteca, en este caso un id. Se debe sumar + i, para que cuando el usuario
                                        introduzca por ejemplo el 1, sea el libro 1 el que salga, y no el 0, ya que para nosotros un array empieza desde el 0.
                                        (biblioteca + i)->ID accede  al campo deseado del libro en la posición i
                                        (biblioteca + i)->ID == id Compara el id introducido del usuario con el id de biblioteca, (1 = 1) = {1,  "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10}
    */                 


            imprimirSoloUnLibro(biblioteca + i);
        }
    }
}

void mostrarCantidadLibros(Libro *biblioteca, int totalLibros, int id) {
     /*
                                                                        Libro *biblioteca es un puntero que esta apuntando a los datos de los libros.
                                                                        LLamo al totalLibros(del main) para indicar el limite de libros que hay, en este caso 40.
                                                                        LLamo al id(del main) para buscar el libro a traves del identificador.
                                                                        */

                                                                        

    if (id < 1 || id > totalLibros) { //si el id introducido es menor a 1, es incorreto y si es mayor al totalLibros(40) tambien sera incorrecto
        printf("El ID ingresado no es válido. Debe estar entre 1 y %d.\n", totalLibros);
    }

    for (int i = 0; i < totalLibros; i++) { //Bucle que recorre desde el 0 hasta el 40.
        if ((biblioteca + i)->ID == id) { //Este if compara la ID de la lista, con el id introducido del usuario

                                        /*
                                        (biblioteca + i) apunta a la posicion i de la biblioteca, en este caso un id. Se debe sumar + i, para que cuando el usuario
                                        introduzca por ejemplo el 1, sea el libro 1 el que salga, y no el 0, ya que para nosotros un array empieza desde el 0.
                                        (biblioteca + i)->ID accede  al campo deseado del libro en la posición i
                                        (biblioteca + i)->ID == id Compara el id introducido del usuario con el id de biblioteca, (1 = 1) = {1,  "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10}
                                        */

            printf("\tCantidad del libro con ID %d: %d\n", id, (biblioteca + i)->cantidad);
        }
    }
}

void añadirCantidadLibro(Libro *biblioteca, int totalLibros, int id, int cantidad) {

    /*
                                                                                    Declaro totalLibro para saber la cantidad de un libro y poder modificar dicha cantidad con un +=
                                                                                    Declaro id para acceder a la id del libro y poder modificar la cantidad.
                                                                                    */

                                                                                    

    if (id < 1 || id > totalLibros) { //Comprueba que el id este en el rango de 0 y 40
        printf("El ID ingresado no es válido. Debe estar entre 1 y 40.\n");
        return;
    }
    for (int i = 0; i < totalLibros; i++) { //Bucle para recorrer el array desde el 0 al 40.
        if ((biblioteca + i)->ID == id) { //Este if compara la ID de la lista, con el id introducido del usuario
            (biblioteca + i)->cantidad += cantidad; //Suma la cantidad que ya habia almacenada en biblioteca + el numero ingresado por el usuario
            printf("\tCantidad actualizada del libro con ID %d: %d\n\n", id, (biblioteca + i)->cantidad);
        }
    }
}

void mostrarLibrosPorCategoria(Libro *biblioteca, int totalLibros, Categoria categoria) {

                                                                                        /*
                                                                                         Declaro totalLibro para saber la cantidad de un libro y poder modificar dicha cantidad con un +=
                                                                                         Declaro id para acceder a la id del libro y poder modificar la cantidad.
                                                                                        */

    printf("Libros de la categoría %d:\n", categoria);
    for (int i = 0; i < totalLibros; i++) { //Bucle para recorrer el array desde el 0 al 40
        if ((biblioteca + i)->categoria == categoria) { //Este if compara las categorias de la lista, con la categoria introducida del usuario
            printf("\n\tID: %d\n  \tTítulo: %s\n  \tAutor: %s\n  \tPrecio: %.2f\n  \tCantidad: %d\n", (biblioteca + i)->ID, (biblioteca + i)->titulo, (biblioteca + i)->autor, (biblioteca + i)->precio, (biblioteca + i)->cantidad);
        
        }
    }
}

void mostrarAutor(Libro *biblioteca, int totalLibros, const char *nombreAutor) {

int encontrado = 0; // Variable para saber si esta el autor que el usuario introduce 

/*

Libro *biblioteca, biblioteca apunta a la memoria donde esta almacenado el struct de Libro.

   ###########
   ##EJEMPLO##
   ###########
                                                                              typedef
    struct =          int ID,    char titulo,         char autor,float precio, genero, int stock 

        biblioteca[0] = {1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10}

   int totalLibros, en este ejemplo "int totalLibros = 1", totalLibros seria igual a 1 debido a que solo hay 1 libro almacenado en la biblioteca


                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

   const char *nombreAutor, const indica que el string no debe de modificarse, es decir es constante. Si no estuviera el const, podria cambiar las
   letras del string, pero como hay un const indica que no se puede cambiar los caracteres de nombreAutor.

   char *nombreAutor, char* es un puntero que almacena la direccion de memoria de nombreAutor

   ###########
   ##EJEMPLO##
   ###########

   char *nombreAutor = "Harper Lee";

   nombreAutor almacena la direccion de memoria donde comienza la cadena, es decir "Harper Lee"
   como nombreAutor es un const puedo hacer que nombreAutor apunte a otra cadena de caracteres, pero no modificar su contenido 

   ###########
   ##EJEMPLO##
   ###########

   char *nombreAutor = "Harper Lee"; // nombreAutor apunta a la cadena literal

   nombreAutor = "George Orwell"; // Ahora nombreAutor apunta a otra cadena




*/
    //se inicializa a 0 para que no contenga basura y se rompa el programa

    for (int i = 0; i < totalLibros; i++) { //Bucle que recorre todos los libros de la biblioteca
        if (strncmp(biblioteca[i].autor, nombreAutor, strlen(nombreAutor)) == 0) {

           /*

            biblioteca[i].autor contiene un char con el nombre del autor, cada vez que el bucle for incrementa la i, va pasando por todos los autores
            nombreAutor contiene el nombre del autor que el usuario introduce (const char *nombreAutor = argv[2];)
            strlen() cuenta la longitud de la cadena nombreAutor. Es decir, devuelve el numero de caracteres que tiene el nombre del autor que el 
            usuario esta buscando, el \0 no cuenta
            strncmp() compara las primeras letras de "nombreAutor" con la cadena que el usuario busca
            
            ###########
            ##EJEMPLO##
            ###########
            
            Si introduce  "Harper Lee", la comparacion se hace con los primeros caracteres de "nombreAutor" y la cadena ingresada. Si coinciden devuelve 0, 
            si no coincide devuelve un valor diferente de 0

            ###########
            ##EJEMPLO##
            ###########

            strlen() cuenta los caracteres de nombreAutor, es decir cuenta el nombre del autor que el usuario busca.

            Si el usuario busca Harper Lee, delvolvera 10 

                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

            if (strncmp(biblioteca[i].autor, nombreAutor, strlen(nombreAutor)) == 0)

            La funcion compara los primeros strlen(nombreAutor) caracteres de biblioteca[i].autor con nombreAutor, es decir comprarara el nombre que el usuario
            introduce con los autores de la biblioteca, si los primeros caracteres de las 2 cadenas son iguales strncmp devolvera 0 (coinciden)


            */

            printf("Autor buscado: %s \n\n\tLibros\n \nTítulo: %s \nÍndice: %d)\n\n\n", biblioteca[i].autor, biblioteca[i].titulo, i);

            // biblioteca[i].autor -> Nombre del autor
            // biblioteca[i].titulo -> Nombre del titulo
            // i -> indice (i del bucle for)
            
        }
    }
        // Si no hemos encontrado ningun libro del autor, mostramos un mensaje

    if (!encontrado) {
        printf("No existe ningun libro con el nombre %s en esta biblioteca.\n", nombreAutor);
    }
}

void añadirNuevoLibro(Libro **biblioteca, int *totalLibros) {
    int opcion = 1;  // Variable para preguntar si quiere seguir añadiendo libros

    /*

                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

            Libro **biblioteca 

            1º puntero -> *biblioteca apunta a un bloque de memoria donde se almacena una lista dinamica de libros
            2º puntero -> **biblioteca es el acceso a cada elemento dentro de ese bloque de memoria, es decir cada struct de cada Libro.

            *totalLibros es el numero total de libros como un puntero para que la funcion pueda modificar ese valor, cada vez que añadamos un libro
            el numero total de libros cambia.

    */

    do { // Bucle para añadir más de 1 libro o añadir 1 solo libro
        Libro nuevoLibro; // Declaro nuevoLibro, que será el nuevo libro que el usuario añada
        int tipoCategoria; // Almacena la categoría del libro 0=FICTION, 1=NON_FICTION, 2=POETRY, 3=THEATER, 4=ESSAY
        int id = 0;

        printf("\nIntroduce los datos del nuevo libro:\n");
        
        
        printf("Titulo: ");
        fgets(nuevoLibro.titulo, sizeof(nuevoLibro.titulo), stdin); // Usa fgets para evitar desbordamientos
        nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = '\0'; // Elimina el salto de línea que fgets puede dejar

        printf("Autor: ");
        fgets(nuevoLibro.autor, sizeof(nuevoLibro.autor), stdin); // Usa fgets para evitar desbordamientos
        nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = '\0'; // Elimina el salto de línea

        printf("Precio: ");
        scanf("%f", &nuevoLibro.precio); // Lee el precio
        
        printf("Categoria (0=FICTION, 1=NON_FICTION, 2=POETRY, 3=THEATER, 4=ESSAY): ");
        scanf("%d", &tipoCategoria); // Lee la categoría
        
        nuevoLibro.categoria = tipoCategoria; // Asigna el valor de tipoCategoria a la categoría del libro
        
        printf("Cantidad: ");
        scanf("%d", &nuevoLibro.cantidad); // Lee la cantidad

        nuevoLibro.ID = (*totalLibros) + 1; // Aumenta el número del ID

        *biblioteca = (Libro *)realloc(*biblioteca, (*totalLibros + 1) * sizeof(Libro));
        if (*biblioteca == NULL) { // Se ejecuta si no hay suficiente memoria disponible
        
        /*

                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

        *biblioteca te da acceso al bloque de memoria que contiene los libros

        realloc(*biblioteca, (*totalLibros + 1) * sizeof(Libro)):

        realloc cambia el tamaño del bloque de memoria, en nuestro caso esta aumentando el tamaño de la memoria.
        *biblioteca es el puntero que apunta al bloque de memoria y le da acceso a realloc para modificarlo
        (*totalLibros + 1) * sizeof(Libro) es el nuevo tamaño del bloque, es decir + 1 libro
        * sizeof(Libro) devuelve el tamaño del un libro en bytes, es decir   (*totalLibros + 1) * sizeof(Libro) calcula el numero total de 
        bytes que van a necesitar para almacenar 1 libro y esto se le da al realloc para cambiar el tamaño de la memoria donde se almacenan los libros.

        */

            printf("Error: NULL\n"); 
        }

        memcpy(&((*biblioteca)[*totalLibros]), &nuevoLibro, sizeof(Libro)); // Copia los datos del nuevo libro

        /*
                                                        --------------------------------------------------
                                                        |################################################|
                                                        |#################MUY IMPORTANTE#################|
                                                        |################################################|
                                                        --------------------------------------------------

        &nuevoLibro es la direccion de memoria del nuevo libro que se va a añadir, es decir un puntero que contiene los datos que el usuario ingresa
        &((*biblioteca)[*totalLibros]) es el lugar donde se va a añadir el libro nuevo
            (*biblioteca) es el puntero de la biblioteca
            [*totalLibros] es el indice de los libros almacenados en la biblioteca y donde se añadira el nuevo
        sizeof(Libro), es el tamaño que el nuevoLibro va a poder tener, es decir el struct de Libro

        */
        
        /*

                                                                ############################
                                                                #########IMPORTANTE#########
                                                                ############################

        
        *biblioteca accede al puntero que esta apuntando a Libro, es decir es un arreglo dinamico de libro que se crea con realloc (*biblioteca = (Libro *)realloc(*biblioteca, (*totalLibros + 1) * sizeof(Libro));)
        [*totalLibros] tiene [], porque estamos accediendo a una posicion especifica de un arreglo(char) 
        
        ###########
        ##EJEMPLO##
        ###########

        Si hay 5 libros en el arreglo *totalLibros sera 5,  lo que indica que el siguiente libro se almacenara en la posición 5 del 
        arreglo (es decir, el sexto libro, los arreglos empiezan desde el 0 hasta n)

        */

        (*totalLibros)++; // Incrementa totalLibros, es decir la memoria que almacena los libros, en nuestro caso tenemos 40 libros(0-39 = 40), 
        //cuando añadamos 1 pasara a ser 40

        

        //Se muestra el nuevo libro 

        printf("\nLibro nuevo:\n");
        printf("\tID: %d\n", nuevoLibro.ID);
        printf("\tTitulo: %s\n", nuevoLibro.titulo);
        printf("\tAutor: %s\n", nuevoLibro.autor);
        printf("\tPrecio: %.2f\n", nuevoLibro.precio);
        printf("\tCategoria: %d\n", nuevoLibro.categoria);  // Ahora muestra la categoría correctamente
        printf("\tCantidad disponible: %d\n", nuevoLibro.cantidad);
        printf("\n\n");
        mostrarTodosLosLibros(*biblioteca, *totalLibros); // Muestra todos los libros

        //pregunta si quiere añadir mas libros, como el bucle funciona si opcion es 1, al cambiar la opcion a 0, el bucle muere.


        printf("¿Quieres añadir otro libro? (1 para sí, 0 para no): ");
        scanf("%d", &opcion);

    } while (opcion == 1); // Si opción es 1, se ejecuta de nuevo
}