#pragma once
#include "Libro.h"
#include "Node.h"
#include <string.h>

typedef struct Doubly_Linked_List DLL;

struct Doubly_Linked_List
{
	Node* head;
	Node* tail;
	int count;
};

DLL* createDLL();
void add_front(DLL *,Libro);
void add_after(DLL *, int index, Data);
void add_before(DLL *, int index, Data);
void add_end(DLL*, Libro);
void delete_index(DLL*, int index);
void delete_node(DLL*, Node* node);
void forward_traverse(DLL*);
void backward_traverse(DLL*);
