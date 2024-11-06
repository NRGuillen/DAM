#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIEMS 100;

struct Proveedor{

	char nombre[100];
	char direccion[100];
	char telefono[100];
};

struct Articulo{

	char nombre[100];
	float precio;
	struct Proveedor proveedor[100];
};	

struct Inventario{

	struct Articulo articulos;
	int cantidades;
	int totalArticulos;
};


	int main(){	

	struct Proveedor miProveedor;
	struct Articulo miArticulo;
	struct Inventario miInventario;

	strcpy(miProveedor.nombre, "Amazon");
        strcpy(miProveedor.direccion, "C/Virgen de los Remedios");	     
	strcpy(miProveedor.telefono, "529423423");
		
	strcpy(miArticulo.nombre, "Agua");
	miArticulo.precio = 10;

	miInventario.cantidades = 10;
	miInventario.totalArticulos = 30;

	printf("Nombre de proveedor: %s\n", miProveedor.nombre);
	printf("Direccion: %s\n", miProveedor.direccion);
	printf("Teléfono: %s\n", miProveedor.telefono);

	printf("Nombre del articulo: %s\n", miArticulo.nombre);
	printf("Precio del articulo: %f\n", miArticulo.precio);
	
	printf("Cantidad disponible articulos: %d\n", miInventario.cantidades);
	printf("Articulos totales: %d\n", miInventario.totalArticulos);
	return 0;
	}



