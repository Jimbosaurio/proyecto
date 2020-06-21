#pragma once

enum FORMATO {TAPA_BLANDA, TAPA_DURA};


struct _Libro {
	char* titulo;
	char* autor;
	char* editorial;
	char isbn[14];
	enum FORMATO formato;
	int existencias;
	float precio;
};
typedef struct _Libro Libro;


Libro crearLibro(char *datosLibro);
void mostrarLibro(Libro *libro);
const char* condensarLibro(Libro *libro);