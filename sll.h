//sll.h
//By John C. Lusth
//Modified by Hank King
//      For CS 201 at the University of Alabama
//      Spring 2017
//taken from http://beastie.cs.ua.edu/cs201/assign0.html
//The following code is a module for a singly linked list data structure
#include <stdio.h>
#ifndef __SLL_INCLUDED__
#define __SLL_INCLUDED__

typedef struct sllnode
	{
	void *value;
	struct sllnode *next;
	} sllnode;

typedef struct sll
	{
	sllnode *head;
	sllnode *tail;
	int size;
	void (*display)(FILE *,void *);
	} sll;

extern sll *newSLL(void (*d)(FILE *,void *));  		//constructor
extern sllnode *newSLLNode(void *a);
extern void insertSLL(sll *items,int index,void *value); //stores a generic value
extern void addToFrontSLL(sll *items, void *value);
extern void addToBackSLL(sll *items, void *value);
extern void *removeSLL(sll *items,int index);     	//returns a generic value
extern void *removeFromFrontSLL(sll *items);
extern void *removeFromBackSLL(sll *items);
extern void unionSLL(sll *front,sll *back); 	//merge two lists into one
extern void *getSLL(sll *items,int index);			//get the value at the index
extern int sizeSLL(sll *items);
extern void displaySLL(FILE *,sll *items);
extern sllnode *goToIndexSLL(int n, sll *items);
extern void joinSLL(sllnode *front, sllnode *back);
#endif
