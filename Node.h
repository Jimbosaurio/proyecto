#pragma once
#include "Libro.h"
#include <string.h>

typedef struct Node Node;
typedef struct _Libro Data;

struct Node {
	Node* prev;
	Data data;
	Node* next;
};

Node* createNode(Data data);
void deleteNode(Node* useless);