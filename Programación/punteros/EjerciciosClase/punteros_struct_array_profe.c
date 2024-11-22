#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definimos las constantes
#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 20

typedef struct{
	char nombre[MAX_NOMBRE];
	int edad;
	float nota;
} Estudiante;

//Esta forma no es valida, porque las funciones locales solo existen en local
/*
  Estudiante inicializar(char * nombre, int edad, float nota){
	
	//Creo una variable de tipo Estudiante
	Estudiante estudiante_nuevo;

        //Creo el estudiante estudiante_nuevo.edad estudiante_nuevo.nombre....
	return estudiante_nuevo;
	

}*/
//Esta opcion no sirve porque no tiene la memoria reservada, no hay donde meter Estudiante
/*
Estudiante * inicializar(char * nombre, int edad, float nota){
	Estudiante * estudiante_nuevo;
	
	//Inicializo
	
	return &estudiante_nuevo;
}
*/

/* ES VALIDA, pero todavia no sabemos lo que hace
 
Estudiante * inicializar(char * nombre, int edad, float nota){
        Estudiante * estudiante_nuevo = malloc //Memoria dinámica

        //Inicializo

        return &estudiante_nuevo;
}
*/

void inicializar(Estudiante * estudiante_a_rellenar, char * nombre, int edad, float nota){
	//estudiante_a_rellenar.edad = edad; NO COMPILA porque estudiante_a_rellenar es un puntero, no un estudiante.
	//Habria que hacer(estudiante_a_rellenar). edad, es decir, acceder al contenido del puntero para poder asi acceder al campo "edad" de estudiante
	//Habria que hacer (*estudiante_a_rellenar) .edad
	estudiante_a_rellenar->edad = edad;
	estudiante_a_rellenar->nota = nota;
	//estudiante_a_rellenar.nombre = nombre; es incorrecto porque compara las memorias no el contenido de las memorias.
	strcpy(estudiante_a_rellenar->nombre, nombre);
}
int main(){
	
	Estudiante listado[MAX_ESTUDIANTES]; // Aqui se reserva la memoria para los estudiantes.. Los 560 bytes se resevan aqui.
	int num_estudiantes;
	
	float nota;
	int edad;
	char nombre[MAX_NOMBRE];

	printf("%p\n", listado);
	printf("Sizeof listado: %lu\n", sizeof(listado)); // 20 estudiante x 28 (int + char + float) = 560
	printf("Sizeof estudiante: %lu\n", sizeof(Estudiante));

	printf("Cuantos estudiantes desea inicializar? ");
	scanf("%d", &num_estudiantes);

	for(int i = 0; i < num_estudiantes, i++;){
	printf("Introduce la edad: ");
	scanf("%d", &edad);
	printf("Introduce la nota: ");
	scanf("%f", &nota);
	printf("Introduce el nombre: ");
	scanf("%s", nombre);

	//inicializar(listado + i,nombre, edad, nota);
	inicializar(&listado[i],nombre, edad, nota);
	}
	return 0;

}

