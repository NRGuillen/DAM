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

        Categoria define un cojunto de valores constantes, en este caso las categorias, no van a cambiar siempre seran  FICTION NON_FICTION POETRY THEATER ESSAY
        El typdef Categoria es independiente a Libro, por lo que se puede reutilizar en partes diferentes del probrama.
        Si lo ponemos dentro de Libro limitariamos su uso y no seria eficiente para utilizarlo en otras lineas del programa.
 
    */

    int cantidad; //Cantidad de cada libro en la biblioteca, es decir libro 1 = 20 libros, libro 2 = 3 libros...
} Libro; //Nombre de la estructura que va a representar un libro en la biblioteca

void imprimirSoloUnLibro(Libro *biblioteca){ //Libro *biblioteca es un puntero que esta apuntando al struct de Libro

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


void mostrarTodosLosLibros(Libro *biblioteca, int totalLibros) { /*
                                                                 Libro *biblioteca es un puntero que esta apuntando a los datos de los libros
                                                                 LLamo al totalLibros(del main) para indicar el limite de libros que hay, en este caso 40.
                                                                 ¿Como se si la variable biblioteca apunta a un solo libro o al array completo? No se puede.
                                                                 */

    printf("Lista de libros disponibles:\n");//imprime toda la lista de libros
    for (int i = 0; i < totalLibros; i++) { //Bucle para recorrer el array desde el 0 al 40.
        
        printf("\tID: %d\n  \tTitulo: %s\n  \tAutor: %s\n  \tPrecio: %.2f\n  \tCategoria: %d\n  \tCantidad: %d\n", (biblioteca + i)->ID, (biblioteca + i)->titulo, (biblioteca + i)->autor, (biblioteca + i)->precio, (biblioteca + i)->categoria, (biblioteca + i)->cantidad);

        /*
        Como es un listado solo quiero saber la ID del libro para poder buscarlo y su nombre, por lo tanto:
        (biblioteca + i) apunta al libro en la posición i del arreglo.
        (biblioteca + i)->ID accede  al campo deseado del libro en la posición i
        (biblioteca + 0)->ID = 1 (1,  "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10).
        Sucede lo mismo para el titulo,autor, precio....
        */
    }
}


void mostrarLibro(Libro *biblioteca, int totalLibros, int id) { // Muestra un libro por ID
                                                                /*
                                                                Libro *biblioteca es un puntero que esta apuntando a los datos de los libros.
                                                                LLamo al totalLibros(del main) para indicar el limite de libros que hay, en este caso 40.
                                                                LLamo al id(del main) para buscar el libro a traves del identificador.
                                                                */
    if (id < 1 || id > totalLibros) {//si el id introducido es menor a 1, es incorreto y si es mayor al totalLibros(40) tambien sera incorrecto
        printf("El ID ingresado no es válido. Debe estar entre 1 y %d.\n", totalLibros);
    }
      
    for (int i = 0; i <= totalLibros; i++) {//Bucle que recorre desde el 0 hasta el 40.
        if ((biblioteca + i)->ID == id) {//Este if compara la ID de la lista, con el id introducido del usuario
                                        /*
                                        (biblioteca + i) apunta a la posicion i de la biblioteca, en este caso un id. Se debe sumar + i, para que cuando el usuario
                                        introduzca por ejemplo el 1, sea el libro 1 el que salga, y no el 0, ya que para nosotros un array empieza desde el 0.
                                        (biblioteca + i)->ID accede  al campo deseado del libro en la posición i
                                        (biblioteca + i)->ID == id Compara el id introducido del usuario con el id de biblioteca, (1 = 1) = {1,  "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10}
                                        */

            imprimirSoloUnLibro(biblioteca + i);
        }
                                                /*
                                                LLamo al void creado especificamente para estos casos, asi no tengo que repetir printf en varios voids.
                                                Lleva un + i para acceder a la posicion correcta, como anteriormente he mencinado, si el usuario introduce un 1
                                                para un array realmente es el 0, por lo que incrementamos ese valor para que el 1 sea el 1
                                                */
    }
    
}


void mostrarCantidadLibros(Libro *biblioteca, int totalLibros, int id) {
                                                                        /*
                                                                        Libro *biblioteca es un puntero que esta apuntando a los datos de los libros.
                                                                        LLamo al totalLibros(del main) para indicar el limite de libros que hay, en este caso 40.
                                                                        LLamo al id(del main) para buscar el libro a traves del identificador.
                                                                        */

    if (id < 1 || id > totalLibros) {//si el id introducido es menor a 1, es incorreto y si es mayor al totalLibros(40) tambien sera incorrecto
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
            int num;
            printf("Introduce la cantidad que quieres añadir: ");
            scanf("%d", &num);
            (biblioteca + i)->cantidad += num; //Suma la cantidad que ya habia almacenada en biblioteca + el numero ingresado por el usuario

            printf("\tCantidad actualizada del libro con ID %d: %d\n", id, (biblioteca + i)->cantidad);
        }
    }
}

void mostrarLibrosPorCategoria(Libro *biblioteca, int totalLibros, Categoria categoria) {
                                                                                         /*
                                                                                         Declaro totalLibro para saber la cantidad de un libro y poder modificar dicha cantidad con un +=
                                                                                         Declaro id para acceder a la id del libro y poder modificar la cantidad.
                                                                                         */
    printf("Libros de la categoria %d:\n", categoria);
    for (int i = 0; i < totalLibros; i++) { //Bucle para recorrer el array desde el 0 al 40.
        if ((biblioteca + i)->categoria == categoria) {  //Este if compara las categorias de la lista, con la categoria introducida del usuario
            printf("\tID: %d\n  \tTitulo: %s\n  \tAutor: %s\n  \tPrecio: %.2f\n  \tCantidad: %d\n", (biblioteca + i)->ID, (biblioteca + i)->titulo, (biblioteca + i)->autor, (biblioteca + i)->precio, (biblioteca + i)->cantidad);
        }
    }
}

int main(int argc, char **argv) {
    int totalLibros = 40;
     Libro biblioteca[MAX_LIBROS] = {
        {1,  "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10},
        {2,  "1984", "George Orwell", 12.49, FICTION, 5},
        {3,  "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8},
        {4,  "Moby Dick", "Herman Melville", 18.99, FICTION, 12},
        {5,  "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7},
        {6,  "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9},
        {7,  "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6},
        {8,  "The Odyssey", "Homer", 17.49, FICTION, 4},
        {9,  "Ulysses", "James Joyce", 25.00, FICTION, 2},
        {10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3},
        {11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11},
        {12, "The Iliad", "Homer", 18.50, FICTION, 7},
        {13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15},
        {14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20},
        {15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13},
        {16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6},
        {17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5},
        {18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8},
        {19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4},
        {20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14},
        {21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6},
        {22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8},
        {23, "Othello", "William Shakespeare", 10.99, THEATER, 7},
        {24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5},
        {25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4},
        {26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10},
        {27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9},
        {28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3},
        {29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15},
        {30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10},
        {31, "Paradise Lost", "John Milton", 12.00, POETRY, 7},
        {32, "Beowulf", "Anonymous", 15.00, POETRY, 5},
        {33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4},
        {34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9},
        {35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11},
        {36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8},
        {37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5},
        {38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12},
        {39, "The Republic", "Plato", 16.00, ESSAY, 6},
        {40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 10}
    };
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
    if (argc < 2) {
        printf("Comando no reconocido.\n");
        return 1;
    }

    if (strcmp(argv[1], "mostrar") == 0) { //argv[1] es el primer argumento que el usuario pasa.
                                           //Lo que hace strcmp(argv[1], "mostrar") == 0 es comparar el primer argumento (argv[1]) con la cadena "mostrar". Es decir lo que introduce el usuario "mostrar"
                                           //Si ambos son iguales (es decir, si el argumento pasado por el usuario es exactamente "mostrar"), entonces strcmp 
                                           //devuelve 0 y la condición será verdadera.
        if (argc == 2) { // argc 2 son los argumentos que el programa recibe inclyendo el nombre del programa
                         // ./biblioteca mostrar
                         // Hay 2 argumentos "biblioteca" y "mostrar"
            mostrarTodosLosLibros(biblioteca, totalLibros);//Se ejecuta cuando argc sea igual a 2 argumentos
        } else if (argc == 3) { //se ejecuta cuando hayan 3 argumentos
            int id = atoi(argv[2]); //se convierte el tercer argumento a un numero entero 
                                    //atoi convierte el valor de un texto a un numero entero, si un argumento no es valido atoi devuelve 0
            mostrarLibro(biblioteca, totalLibros, id);//Se ejecuta cuando argc sea igual a 3 argumentos
        } else {
            printf("Comando no reconocido.\n");//Se ejecuta si se introduce 3 argumentos y alguno es invalido
        }
    } else if (strcmp(argv[1], "stock") == 0) { //compara si el primer argumento es igual a "stock"
        if (argc == 4) { //se ejecuta si hay 4 argumentos
            int id = atoi(argv[2]); //convierte el argumento 2 a un numero entero 
            int cantidad = atoi(argv[3]); //convierte el argumento 3 a un numero entero 
            añadirCantidadLibro(biblioteca, totalLibros, id, cantidad); //Se ejecuta cuando hay 4 argumentos
        } else {
            printf("Comando no reconocido.\n"); //Se ejecuta si se introduce 4 argumentos y alguno es invalido
        }
    } else if (strcmp(argv[1], "categoria") == 0) { //se reptite como en los anteriores casos
        if (argc == 3) {
            int categoria = atoi(argv[2]);
            mostrarLibrosPorCategoria(biblioteca, totalLibros, categoria);
        } else {
            printf("Comando no reconocido.\n");
        }
    /*} else if (strcmp(argv[1], "autor") == 0) {
        if (argc == 3) {
            char *autor = argv[2];
        } else {
            printf("Comando no reconocido.\n");
        }*/
    } else if (strcmp(argv[1], "añadir") == 0) { //se reptite como en los anteriores casos
        printf("No se hacer la funcion :(.\n");
    } else {
        printf("Comando no reconocido.\n");
    }

    return 0;
}


  

