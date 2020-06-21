#include <stdlib.h>
#include "Node.h"
#include <string.h>

Node* createNode(Data data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->next = NULL;
	new->prev = NULL;
	new->data = data;
	return new;
}

void deleteNode(Node* useless)
{
	free(useless);
}