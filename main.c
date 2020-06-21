
#include <stdio.h>
#include <stdlib.h>
#include "Inventario.h"
#include "Administracion.h"


int main(int argc, char** argv)
{
	int w;
	printf("°°°°°°°°°°°°°°°°°°°°°°°°°LIBRERIAS SCHOPENHAUER°°°°°°°°°°°°°°°°°°°°°°°°°​");
	printf("\nBienvenido a nuestra libreria en linea ");
	printf("\nPor favor ingrese la operacion que desea realizar");
	printf("\n1)Mostrar listado de libros\n2)Buscar libro por titulo \n3)Buscar libro por medio del nombre del autor");
	printf("\n4)Buscar libro por medio del ISBN\n5)ver carrito de compra y confirmar compra \n6)Administracion");
	scanf("%d",&w);
	printf("Aqui se muestran los libros a la venta, puede desplazar para ver el siguiente");

	ListarInventario();

	switch (w)
	{
			case (1):	

						ListarInventario();

				break;

			case (2):		BuscarLibroPorTitulo();

				break;

			case (3):		BuscarLibroPorAutor();
				break;

			case (4):		BuscarLibroPorISBN();
				break;

			case (5):
				break;

	default:
		break;
	}











	//LeerArchivoBD("D:\\Documents\\Luis\\ProyectoEDA1_Luis\\ProyectoEDA1_Luis\\InventarioLibros.txt");
	//ListarInventario();
	//AltaLibro();
	//BajaLibro();
	//AgregarExistenciasLibro();
	//ListarInventario();
	//BuscarLibroPorAutor();
	//GuardarArchivoBD("D:\\Documents\\Luis\\ProyectoEDA1_Luis\\ProyectoEDA1_Luis\\InventarioLibros.txt");
	return 0;
}
