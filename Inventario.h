#pragma once
#include <stdlib.h>
#include "Libro.h"
#include "DoubleLinkedList.h"
#include "List.h"


enum MODO_BUSQUEDA {TITULO, AUTOR, ISBN};

DLL* inventario; //Cambiar por la lista doble

int LeerArchivoBD(const char *ruta);
int GuardarArchivoBD(char *ruta);

int ListarInventario();

//Agregar libros
void AgregarLibro(Libro l);
//Eliminar libros
void EliminarLibro(const char* isbn);
//Cambiar existencias
void CambiarExistenciasLibro(const char* isbn, int numLibros);
void DisminuirExistenciasLibro(const char* isbn);
//Buscar
List * Buscar(enum MODO_BUSQUEDA mode, const char* id);
Node* BuscarLibro(const char* isbn);