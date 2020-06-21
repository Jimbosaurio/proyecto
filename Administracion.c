
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Inventario.h"
#include "Administracion.h"


void AltaLibro()
{
	char buffer[200];
	Libro nuevo;
	puts("Agregando un nuevo libro");
	printf("Titulo: ");
	gets_s(buffer, 200);
	nuevo.titulo = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(nuevo.titulo, strlen(buffer) + 1, buffer);
	printf("Autor: ");
	gets_s(buffer, 200);
	nuevo.autor = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(nuevo.autor, strlen(buffer) + 1, buffer);
	printf("Editorial: ");
	gets_s(buffer, 200);
	nuevo.editorial = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(nuevo.editorial, strlen(buffer) + 1, buffer);

	printf("ISBN: ");
	gets_s(buffer, 200);
	while (strlen(buffer) != 13)
	{
		printf("ISBN invalido. Debe contener 13 numeros. Ingresa de nuevo: ");
		gets_s(buffer, 200);
	}
	strcpy_s(nuevo.isbn, 14, buffer);

	printf("Formato (tapa): ");
	gets_s(buffer, 200);
	if (buffer[0] == '0')
		nuevo.formato = TAPA_BLANDA;
	else
		nuevo.formato = TAPA_DURA;

	printf("Cantidad en existencia: ");
	gets_s(buffer, 200);
	nuevo.existencias = strtol(buffer, NULL, 10);

	printf("Precio: ");
	gets_s(buffer, 200);
	nuevo.precio = strtof(buffer, NULL);

	AgregarLibro(nuevo);
}

void BajaLibro()
{
	char query_isbn[15];
	printf("Introduce el ISBN del libro que quieres dar de baja:");
	gets_s(query_isbn, 15);
	while (strlen(query_isbn) != 13)
	{
		printf("ISBN invalido. Debe contener 13 numeros. Ingresa de nuevo: ");
		gets_s(query_isbn, 15);
	}
	EliminarLibro(query_isbn);
}

void AgregarExistenciasLibro()
{
	char query_isbn[15];
	int n;
	printf("Introduce el ISBN del libro que quieres modificar:");
	gets_s(query_isbn, 15);
	while (strlen(query_isbn) != 13)
	{
		printf("ISBN invalido. Debe contener 13 numeros. Ingresa de nuevo: ");
		gets_s(query_isbn, 15);
	}
	printf("Introduce la cantidad de unidades nuevas:");
	scanf("%d", &n);
	CambiarExistenciasLibro(query_isbn,n);
}

void BuscarLibroPorTitulo()
{
	List* resultado;
	char query_titulo[100];
	printf("Introduce el titulo del libro que deseas:");
	gets_s(query_titulo,100);
	resultado  = Buscar(TITULO, query_titulo);
	if (resultado->head == NULL)
		puts("0 resultados coinciden con este titulo");
	traverse(resultado);
}

void BuscarLibroPorAutor()
{
	List* resultado;
	char query_autor[100];
	int r;
	printf("Introduce el autor que deseas buscar:");
	gets_s(query_autor,100);
	resultado = Buscar(AUTOR, query_autor);
	if (resultado->head == NULL)
		puts("0 resultados coinciden con este autor");
	traverse(resultado);
}

void BuscarLibroPorISBN()
{
	List* resultado;
	char query_isbn[100];
	printf("Introduce el titulo del libro que deseas:");
	gets_s(query_isbn,100);
	resultado = Buscar(ISBN, query_isbn);
	if (resultado->head == NULL)
		puts("0 resultados coinciden con este isbn");
	traverse(resultado);
}
