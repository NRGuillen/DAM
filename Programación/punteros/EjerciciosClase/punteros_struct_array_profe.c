#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definimos las constantes
#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 20
#define MAX_BUFFER 200
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
//tiene que recibir un puntero a estudiante porque va a modificar la variable que recibe como argumento
//No es necesario un valor de retorno cumpleañero porque va a ser modificado en la funcion 
void cumpleanios(Estudiante * cumpleanero){
	cumpleanero->edad++;
}

//crea una funcion que cree una cadena de texto con la informacion del estudiante.
//(Puedes empezar creando una funcion que imprima por pantalla la informacion de un estudiante).
	
//27/11 VAMOS A CREAR UNA FUNCION PARA IMPRIMIR UN ESTUDIANTE. LO VAMOS A HACER DE 2 FORMAS

//Recibe un estudiante y muestra por pantalla todos sus datos
void imprimirEstudiante( const Estudiante* estudiante_a_imprimir){
printf("Nombre: %s\n",estudiante_a_imprimir -> nombre);
printf("Edad:%d\n", estudiante_a_imprimir ->edad);
printf("Nota: %f\n", estudiante_a_imprimir -> nota);
}	

//UNA FUNCIO DE "IMPRIMIR" SIN LOS PRINTFS
//Convertir un estudiante a una cadena de texto
//Quiero que sea una variable local del main que aqui se utiliza y aqui se rellena
//Esta funcion da un warning porque la variable retval deja de exisitir cuando acaba la funcion
/*char estudianteToString_warning(const Estudiante * datos){
	char retval[MAX_BUFFER];

//snprintf (donde, cuanto, el qué[lo que harias con un printf])
	snprintf(retval,MAX_BUFFER,"El estudiante %s de %d ha sacado un %f.", datos->nombre, datos->edad, datos->nota);

	return retval;
}
*/
char estudianteToString_warning(const Estudiante * datos, char * retval){
//snprintf (donde, cuanto, el qué[lo que harias con un printf])
	snprintf(retval,MAX_BUFFER * sizeof(char)/*200 x 4 (Lo que ocupa un char)*/,"El estudiante %s de %d ha sacado un %f.", datos->nombre, datos->edad, datos->nota);

}

void modificarNombreEstudiante(Estudiante* estudiante_a_modificar, char * nuevo_nombre){

strcpy(estudiante_a_modificar -> nombre, nuevo_nombre);
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
	inicializar(&listado[1],nombre, edad, nota);
	}
	//El estudiante de la primera posicion ha cumplido años
	printf("Edad antigua %s: %d\n" ,listado[0].nombre,listado[0].edad);
	
	cumpleanios(&listado[0]/*Direccion de memoria*/);
	//cumpleanios(listado);
	
	printf("Edad nueva: %d\n",listado[0].edad);
	//tambien se pueden usar
	//printf("Edad nueva: %d\n",listado ->edad);
	//printf("Edad nueva: %d\n",(*listado).edad);

	imprimirEstudiante(&listado[0]);

	char StringARellenar[MAX_BUFFER];
	estudianteToString_warning(&listado[0],StringARellenar);
	printf("%s\n", StringARellenar);
	//El estudiante ... de ... años ...
	
	//Renombrar

	char nuevo_nombre[MAX_NOMBRE];
	printf("Introduce nombre: ");
	scanf("%s", nuevo_nombre);
	modificarNombreEstudiante(&listado[0], nuevo_nombre);
	imprimirEstudiante(&listado[0]);

	return 0;

}

