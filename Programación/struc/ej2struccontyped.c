#include <stdio.h>
#include <string.h>

typedef struct Vehiculo{

	char marca[12];
	char modelo[12];
	int anio;
	int kilometraje;
}vehiculo;

int main() {
	
	//No es necesario el struc pq esta el vehiculo arriba en typefed 

	Vehiculo miVehiculo;
	
	//Para los char es necesario usar el "strcpy" para copiar la palabra entre "" y para los numeros
	//no es necesario 

	strcpy(miVehiculo.marca, "Toyota");
	strcpy(miVehiculo.modelo, "Corolla");
        miVehiculo.anio = 2021;
        miVehiculo.kilometraje = 15000;

        printf("Marca: %s\n", miVehiculo.marca);
        printf("Modelo: %s\n", miVehiculo.modelo);
        printf("Año: %d\n", miVehiculo.anio);
        printf("Kilometraje: %d km\n", miVehiculo.kilometraje);

	return 0;
}
