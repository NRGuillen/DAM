#include <stdio.h>
#include <string.h>

#define MAX_TITULO 80
#define MAX_AUTOR 50
#define MAX_LIBROS 40

typedef enum {
    FICTION, 
    NON_FICTION,
    POETRY,
    THEATER,
    ESSAY,
} Categoria;

typedef struct {
    int ID;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    float precio;
    Categoria categoria;
    int cantidad;
} Libro;

/*
Creo este void debido a que si no estaria repitiendo muchas veces los printf en distintos
codigos es decir, con este void puedo hacer printf en void mostrarLibro y en void mostrarCantidadLibros
*/
void imprimirSoloCategoria(Libro *biblioteca){ //Libro *biblioteca es un puntero que esta apuntando al struct de Libro

            /*
            Para acceder a los datos del struct se puede hacer de dos formas o con "->" o con ".ID".
            En mi caso utilizo el  .ID ya que lo entiendo mejor pero tambien podria ser con "printf("ID: %d\n", biblioteca->ID)";
            */
            printf("\tEl libro con ID %d, es de categoria: %d\n", (*biblioteca).ID, (*biblioteca).categoria);

                                        /*<-------TAMBIEN ES VALIDO------->

            printf("El libro con ID %d, es de categoria: %d\n", biblioteca->ID, biblioteca->categoria);
                                                                                                        */                      
}

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
}

/*
Este void lo he creado para mostrar el listado de todos los libros que hay en la biblioteca, declarada en el int main.
Utilizo un puntero Libro *biblioteca para acceder a todos los libros que hay y un int totalLibros declarado en el main
para marcar el limite de la lista, en este caso 40
*/

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

// Muestra un libro por ID
void mostrarLibro(Libro *biblioteca, int totalLibros, int id) { /*
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


/*
Este void lo he creado para mostrar la cantidad de un solo libro de la biblioteca, declarada en el int main.
Utilizo un puntero Libro *biblioteca para acceder a la id de los libros que hay y un int totalLibros declarado en el main
para marcar el limite de la lista, en este caso 40
*/

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

/*
Este void lo he creado para modificar la cantidad de un solo libro de la biblioteca, declarada en el int main.
Utilizo un puntero Libro *biblioteca para acceder a la id de los libros que hay y un int totalLibros declarado en el main
para marcar el limite de la lista, en este caso 40.
Este void realmente es la copia del void mostrarCantidadLibros solamente hay que añadir una suma para aumentar la cantidad que introduzca el usuario
*/

void añadirCantidadLibro (Libro *biblioteca, int totalLibros, int id) { 
                                                                        /*
                                                                        Declaro totalLibro para saber la cantidad de un libro y poder modificar dicha cantidad con un +=
                                                                        Declaro id para acceder a la id del libro y poder modificar la cantidad.
                                                                        */
    if (id < 1 || id > totalLibros) { //Comprueba que el id este en el rango de 0 y 40 
        printf("El ID ingresado no es válido. Debe estar entre 1 y el 40");
    }
    for (int i = 0; i < totalLibros; i++) { //Bucle para recorrer el array desde el 0 al 40.
        if ((biblioteca + i)->ID == id) { //Este if compara la ID de la lista, con el id introducido del usuario

            int suma, num; //Declaro valiables para realizar el incremento

            printf("Introduce la cantidad que quieres añadir: "); //Introduce la cantidad que quiere añadir
            scanf("%d", &num);

            suma = (*biblioteca).cantidad + num; //Suma la cantidad que ya habia almacenada en biblioteca + el numero ingresado por el usuario

            printf("\tCantidad actualizada del libro con ID %d: %d\n", id, suma);
        }
    } 
} 

/*
Este void lo he creado para mostrar todos los libros que haya en una sola categoria.
Utilizo un puntero Libro *biblioteca para acceder a la id de los libros que hay y un int totalLibros declarado en el main
para marcar el limite de la lista, en este caso 40 y declaro categoria para el enum.
*/

void mostrarLibrosPorCategoria(Libro *biblioteca, int totalLibros, Categoria categoria) {
                                                                                        /*
                                                                                        Declaro totalLibro para saber la cantidad de un libro y poder modificar dicha cantidad con un +=
                                                                                        Declaro id para acceder a la id del libro y poder modificar la cantidad.
                                                                                        */


    printf("Libros de la categoria %d:\n", categoria);
    int encontrado = 0;
    for (int i = 0; i < totalLibros; i++) { //Bucle para recorrer el array desde el 0 al 40.
        if ((biblioteca + i)->categoria == categoria) { //Este if compara las categorias de la lista, con la categoria introducida del usuario
            printf("\tID: %d\n  \tTitulo: %s\n  \tAutor: %s\n  \tPrecio: %.2f\n  \tCantidad: %d\n", (biblioteca + i)->ID, (biblioteca + i)->titulo, (biblioteca + i)->autor, (biblioteca + i)->precio, (biblioteca + i)->cantidad);
        }
    }
}

int main() {
    int id, cantidadLibros;
    Categoria categoria; //Declaro categoria para el "mostrarLibrosPorCategoria"
    char respuesta[3]; // limito la respuesta a tres caracteres, si\0, no\0
    int totalLibros = 40;//limito los libros a 40 ya que solo hay 40
    int cantidad;

    // Declaración de la biblioteca
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

    /*---------------EXPLICACION GLOBAR DE ESTOS IF------------------
    #if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0)
    #Comprueba que el usuario haya puesto un si, o Si, de lo contrario el codigo no se ejecutara ya que seria = 1.


    #if(id >= 41){
    #        printf("\tNo existe ningun libro con esa id\n");
    #    }
    #Si el id que introduce el usuario es mayor a 41( debido a que solo hay 40 libros) ejecuta el printf de error

    #else if (strcmp(respuesta, "no") == 0 || strcmp(respuesta, "No") == 0)
    #Comprueba que el usuario haya puesto un no, o No, de lo contrario el codigo no se ejecutara ya que seria = 1.

    */

    /*---------------VISUALIZAR TODOS LOS LIBROS------------------*/

    printf("¿Quieres visualizar todos los libros? (responde con si o no): ");
    scanf("%s", respuesta);

    if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
        mostrarTodosLosLibros(biblioteca, totalLibros);
    } else if (strcmp(respuesta, "no") == 0 || strcmp(respuesta, "No") == 0) {

    } else {
        printf("Has introducido un dato erroneo.\n");
    }


    /*---------------VISUALIZAR CARACTERISTICAS DE UN LIBRO------------------*/


    printf("¿Quieres visualizar las características de algun libro? (responde con si o no): ");
    scanf("%s", respuesta);

    if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
        printf("Introduce el ID del libro: ");
        scanf("%d", &id);
        if(id >= 41){
            printf("\tNo existe ningun libro con esa id\n");
        }
        mostrarLibro(biblioteca, totalLibros, id);
    } else if (strcmp(respuesta, "no") == 0 || strcmp(respuesta, "No") == 0) {
       
    } else {
        printf("Has introducido un dato erroneo.\n");
    }

    /*---------------VISUALIZAR CANTIDAD DE UN LIBRO------------------*/

    printf("¿Quieres visualizar la cantidad de un libro? (responde con si o no): ");
    scanf("%s", respuesta);

    if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
        printf("Introduce el ID del libro: ");
        scanf("%d", &id);
        mostrarCantidadLibros(biblioteca, totalLibros, id);  
    } else if (strcmp(respuesta, "no") == 0 || strcmp(respuesta, "No") == 0) {
    
    } else {
        printf("Has introducido un dato erróneo.\n");
    }

    /*---------------MODIFICACION DEL STOCK DE UN LIBRO------------------*/

    printf("¿Quieres modificar el stock de un libro? (responde con si o no): ");
    scanf("%s", respuesta);

    if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
        printf("Introduce el ID del libro: ");
        scanf("%d", &id);
        mostrarCantidadLibros(biblioteca,  totalLibros,  id); //Llamo el void mostrarCantidadLibros para visualizar la cantidad que tiene un libro.
        añadirCantidadLibro (biblioteca, totalLibros, id); //Llamo el void añadirCantidadLibro para incrementar el stock.

    } else if (strcmp(respuesta, "no") == 0 || strcmp(respuesta, "No") == 0) {
    
    } else {
        printf("Has introducido un dato erróneo.\n");
    }

    /*-------------------------VISUALIZAR CATEGORIA-------------------------*/

    printf("Introduce qué libros de la misma categoría quieres visualizar (0 = FICTION, 1 = POETRY, 2 = NON_FICTION, 3 = THEATER, 4 = ESSAY): ");
    scanf("%d", &categoria);  // Capturamos la categoría como un valor entero

    // Verificamos si la categoría es válida
    if (categoria >= 0 && categoria <= 4) {
        printf("Seleccionaste la categoria: %d\n", categoria);  // Imprimir categoría seleccionada
        mostrarLibrosPorCategoria(biblioteca, totalLibros, categoria);  // Pasamos la categoría seleccionada
    } else {
        printf("\tCategoría no válida, por favor elige un valor entre 0 y 4.\n");
    }

    return 0;
}
