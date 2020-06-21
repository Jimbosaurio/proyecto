#include <stdio.h> 
#include <stdlib.h>
#include "DoubleLinkedList.h"
#include <string.h>

DLL* createDLL()
{
	DLL* dll = (DLL*)malloc(sizeof(DLL));
	dll->head = NULL;
	dll->tail = NULL;
	dll->count = 0;
	return dll;
}

void add_before(DLL *list, int index, Data new)
{
	if (index == 0)
		add_front(list, new);
	else if (index > 0 && index < list->count)
		add_after(list, index - 1, new);
	else
		puts("Indice invalido");
}

void add_front(DLL *list, Data new)
{
	Node* newNode = createNode(new);
	if (list->head == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		list->tail = newNode;
	}
	else if (list->head != NULL && list->head == list->tail)
	{
		newNode->next = list->head;
		newNode->prev = list->head;
		list->head->prev = newNode;
		list->head->next = newNode;
	}
	else
	{
		newNode->next = list->head;
		newNode->prev = list->tail;
		list->head->prev = newNode;
		list->tail->next = newNode;
	}

	list->head = newNode;
	list->count += 1;
}

void add_end(DLL *list, Data new)
{
	Node* newNode = createNode(new);

	if (list->head == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		list->head = newNode;
	}
	else if (list->head != NULL && list->head == list->tail)
	{
		newNode->next = list->head;
		newNode->prev = list->head;
		list->head->prev = newNode;
		list->head->next = newNode;
	}

	else
	{
		newNode->next = list->head;
		newNode->prev = list->tail;
		list->head->prev = newNode;
		list->tail->next = newNode;
	}
	list->tail = newNode;
	list->count += 1;
}

void add_after(DLL *list, int index, Data new)
{
	Node* newNode;
	Node* mark = list->head;
	Node* n;
	if (index > list->count || index < 0)
	{
		puts("Indice invalido");
	}
	else if (index == list->count - 1)
	{
		add_end(list, new);
	}
	else
	{
		newNode = createNode(new);
		for (int i = 0 ; i < index ; i++)
			mark = mark->next;
		
		n = mark->next;

		n->prev = newNode;
		newNode->next = n;

		mark->next = newNode;
		newNode->prev = mark;
		list->count += 1;
	}
}

void delete_node(DLL *list, Node* node)
{
	Node *next, *prev;

	if (list->count == 1)
	{
		list->head = NULL;
		list->tail = NULL;
		list->count = 0;
		deleteNode(node);
		return;
	}

	next = node->next;
	prev = node->prev;

	prev->next = next;
	next->prev = prev;

	if (node == list->head)
		list->head = next;
	else if (node == list->tail)
		list->tail = prev;

	list->count -= 1;
	deleteNode(node);
}

void forward_traverse(DLL* list)
{
	Node* iterator = list->head;
	while (iterator != list->tail)
	{
		mostrarLibro(&(iterator->data));
		iterator = iterator->next;
	}
	mostrarLibro(&(list->tail->data));
}

void backward_traverse(DLL* list)
{
	Node* iterator = list->tail;
	while (iterator != list->head)
	{
		mostrarLibro(&(iterator->data));
		iterator = iterator->prev;
	}
	mostrarLibro(&(list->head->data));
}