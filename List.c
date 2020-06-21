#include "List.h"

List* createList()
{
	List * l = (List*)malloc(sizeof(List));
	l->head = NULL;
	l->tail = NULL;
	l->count = 0;
	return l;
}

List* createStack()
{
	return createList();
}

List* createQueue()
{
	return createList();
}

int isEmpty(List * list)
{
	return list->head == NULL;
}

Data* peek(List * list)
{
	return &list->head->data;
}

void push(List* list, Data new)
{
	Node* newNode = createNode(new);

	newNode->next = list->head;
	list->head = newNode;
}

Data pop(List* list)
{
	Data out = list->head->data;
	list->head = list->head->next;
	return out;
}


void enqueue(List* list, Data new)
{
	Node* newNode = createNode(new);
	if (isEmpty(list))
		list->head = newNode;
	else
		list->tail->next = newNode;
	
	list->tail = newNode;
}

Data dequeue(List* list)
{
	Data out = list->head->data;
	list->head = list->head->next;
	if (isEmpty(list))
		list->tail = NULL;
	return out;
}

void traverse(List* list)
{
	Node* iterator = list->head;
	if (list->head == NULL)
		return;
	while (iterator != list->tail)
	{
		mostrarLibro(&(iterator->data));
		iterator = iterator->next;
	}
	mostrarLibro(&(list->tail->data));
}
