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

/*Creo este void debido a que si no estaria repitiendo muchas veces los printf en distintos
codigos es decir, con este void puedo hacer printf en void mostrarLibro y en void mostrarCantidadLibros

*/

void imprimirSoloUnLibro(Libro *biblioteca){

            printf("ID: %d\n", (*biblioteca).ID);
            printf("Titulo: %s\n", (*biblioteca).titulo);
            printf("Autor: %s\n", (*biblioteca).autor);
            printf("Precio: %.2f\n", (*biblioteca).precio);
            printf("Categoria: %d\n", (*biblioteca).categoria);
            printf("Cantidad disponible: %d\n", (*biblioteca).cantidad);
}

// Muestra un libro por ID
void mostrarLibro(Libro *biblioteca, int totalLibros, int id) {
    for (int i = 0; i < totalLibros; i++) {
        if ((biblioteca + i)->ID == id) {
                imprimirSoloUnLibro(biblioteca);
            return;
        }
    }
    printf("No se encontró el libro con ID: %d\n", id);
}

// Muestra una cantidad específica de libros
void mostrarCantidadLibros(Libro *biblioteca, int totalLibros, int cantidad) {
    if (cantidad > totalLibros || cantidad <= 0) {
        printf("Cantidad no válida. Solo hay %d libros disponibles.\n", totalLibros);
        return;
    }
            imprimirSoloUnLibro(biblioteca);
}

int main() {
    int id, cantidadLibros;
    char respuesta[3];
    int totalLibros = 50;

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

    printf("¿Quieres visualizar un solo libro? (responde con si o no): ");
    scanf("%s", respuesta);

    if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
        printf("Introduce el ID del libro: ");
        scanf("%d", &id);
        mostrarLibro(biblioteca, totalLibros, id);
    } else if (strcmp(respuesta, "no") == 0 || strcmp(respuesta, "No") == 0) {
        printf("Saliendo del programa.\n");
        
    } else {
        printf("Has introducido un dato erroneo.\n");
    }

    return 0;
}