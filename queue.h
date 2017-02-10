//queue.h
//By John C. Lusth
//Modified by Hank King to include a queue struct
//      For CS 201 at the University of Alabama
//      Spring 2017
//taken from http://beastie.cs.ua.edu/cs201/assign0.html
//The following code makes a queue from a singly linked list. 
//For use with sll module
#include "sll.h"
typedef struct queue
    {
	sll *list;
    } queue;

queue *newQueue(void (*d)(FILE *,void *));   //constructor
void enqueue(queue *items,void *value);      //stores a generic value
void *dequeue(queue *items);                 //returns a generic value
void *peekQueue(queue *items);               //returns a generic value
int sizeQueue(queue *items);
void displayQueue(FILE *fp,queue *items);
