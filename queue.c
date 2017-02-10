//queue.c
//By Hank King
//		For CS 201 at the University of Alabama
//		Spring 2017
//Function headers by John C Lusth 
//taken from http://beastie.cs.ua.edu/cs201/assign0.html
//The following code makes a queue from a singly linked list. Enqueue adds to 
//the back of the list, while dequeue removes from the front of the list.

#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "queue.h"

queue *newQueue(void (*d)(FILE *,void *))   //constructor
	{
	queue *items = malloc(sizeof(queue));
	if (items == 0)
		{
		fprintf(stderr,"out of memory");
		exit(-1);
		}
	items->list = newSLL(d);
	return items;
	}

//stores a generic value at the back of a singly linked list in constant time.
void enqueue(queue *items,void *value)      //stores a generic value
	{
	insertSLL(items->list, items->list->size, value); //adds to back of sll
	}

//removes a generic value from the front of a singly linked list in constant time.
//returns the value.
void *dequeue(queue *items)                 //returns a generic value
	{
	return removeSLL(items->list, 0);
	}

//returns next generic value to be dequeued in constant time without dequeueing it.
void *peekQueue(queue *items)               //returns a generic value
	{
	if (sizeQueue(items) == 0)
		{
		printf("peek error: empty queue.");
		return 0;
		}
	return items->list->head->value;		//returns value at head of list.
	}

//returns number of nodes in queue
int sizeQueue(queue *items)
	{
	return items->list->size;
	}

//displays queue in order
void displayQueue(FILE *fp,queue *items)
	{
	displaySLL(fp, items->list);
	return;
	}
