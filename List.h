#pragma once
#include <stdlib.h>
#include "Node.h"


typedef struct List List;
typedef struct List Stack;
typedef struct List Queue;

struct List
{
	Node* head;
	Node* tail;
	int count;
};

List * createList();
List* createStack();
List* createQueue();
int isEmpty(List *);
Data* peek(List *);
void push(List *,Data);
Data pop(List*);
void enqueue(List*,Data);
Data dequeue(List*);
void traverse(List*);
