
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dll.h"

stack *newStack(void (*d)(FILE *,void *))   //constructor
	{
	stack *items = malloc(sizeof(stack));
    if (items == 0)
        {
        fprintf(stderr,"out of memory");
        exit(-1);
        }
    items->list = newDLL(d);
    return items;
	}
void push(stack *items,void *value)         //stores a generic value
	{
	insertDLL(items->list, 0, value); 	//stores at front of list
	}
void *pop(stack *items)                     //returns a generic value
	{
	return removeDLL(items->list, 0);			//removes from front of list
	}

void *peekStack(stack *items)               //returns a generic value
	{
	 if (sizeStack(items) == 0)
        {
        printf("peek error: empty stack.");
        return 0;
        }
    return items->list->head->value;
	}
int sizeStack(stack *items)
	{
	return items->list->size;
	}
void displayStack(FILE *fp,stack *items)
	{
	displayDLL(fp, items->list);
	return;
	}
