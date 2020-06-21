#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inventario.h"
#include "Libro.h"
#include "DoubleLinkedList.h"


int LeerArchivoBD(const char* ruta)
{
	char linea[200];
	int i;
	Libro libroActual;

	inventario = createDLL();
	
	FILE *archivoInventario = fopen(ruta, "r");
	if (archivoInventario == NULL) 
	{ 
		fputs("No existe el archivo", stderr); 
		return 1;
	}
	i = 0;
	while (feof(archivoInventario) == 0)
	{
		fgets(linea, 200, archivoInventario);
		libroActual = crearLibro(linea);
		add_end(inventario, libroActual);
	}
	
	fclose(archivoInventario);
	return 0;
}

int GuardarArchivoBD(char *ruta)
{
	FILE* archivoInventario = fopen(ruta, "w");
	Node* iter = inventario->head->next;
	while (iter != inventario->tail)
	{
		fputs(condensarLibro(&iter->data), archivoInventario);
		fputc('\n', archivoInventario);
		iter = iter->next;
	}
	fputs(condensarLibro(&inventario->tail->data), archivoInventario);
	fclose(archivoInventario);
	return 0;

}

int ListarInventario()
{
	system("cls");
	forward_traverse(inventario);

	return 0;
}

void AgregarLibro(Libro l)
{
	add_end(inventario, l);
}

void EliminarLibro(const char* isbn)
{
	Node* resultado = BuscarLibro(isbn);
	if (resultado == NULL)
	{
		puts("Ese ISBN no existe en el cat�logo");
		return;
	}
	delete_node(inventario, resultado);
}

void CambiarExistenciasLibro(const char* isbn, int numLibros)
{
	Node* resultado = BuscarLibro(isbn);
	if (resultado == NULL)
	{
		puts("Ese ISBN no existe en el cat�logo");
		return;
	}
	resultado->data.existencias += numLibros;
}

void DisminuirExistenciasLibro(const char* isbn)
{
	CambiarExistenciasLibro(isbn, -1);
}

List* Buscar(enum MODO_BUSQUEDA mode, const char* query)
{
	List* resultado = createList();
	Node* iterador = inventario->head;
	while (iterador != inventario->tail)
	{
		switch (mode)
		{
			case TITULO:
				if (!strcmp(query,iterador->data.titulo))
					enqueue(resultado, iterador->data);
				break;
			case AUTOR:
				if (!strcmp(query,iterador->data.autor))
					enqueue(resultado, iterador->data);
				break;
			case ISBN:
				if (!strcmp(query,iterador->data.isbn))
					enqueue(resultado, iterador->data);
				break;
		}
		iterador = iterador->next;
	}

	//Ultimo elemento
	switch (mode)
	{
	case TITULO:
		if (!strcmp(query, iterador->data.titulo))
			enqueue(resultado, iterador->data);
		break;
	case AUTOR:
		if (!strcmp(query, iterador->data.autor))
			enqueue(resultado, iterador->data);
		break;
	case ISBN:
		if (!strcmp(query, iterador->data.isbn))
			enqueue(resultado, iterador->data);
		break;
	}

	return resultado;
}

Node* BuscarLibro(const char* isbn)
{
	Node* iterador = inventario->head;
	while (iterador != inventario->tail)
	{
		if (!strcmp(isbn, iterador->data.isbn))
				return iterador;
		iterador = iterador->next;
	}

	if (!strcmp(isbn, iterador->data.isbn))
			return iterador;

	return NULL;
}

