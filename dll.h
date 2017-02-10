//dll.h
//By John C. Lusth
//Modified by Hank King
//      For CS 201 at the University of Alabama
//      Spring 2017
//taken from http://beastie.cs.ua.edu/cs201/assign0.html
//The following code is a module for a singly linked list data structure
#include <stdio.h>
#ifndef __DLL_INCLUDED__
#define __DLL_INCLUDED__

typedef struct dllnode
	{
	void *value;
	struct dllnode *next;
	struct dllnode *prev;
	} dllnode;

typedef struct dll
	{
	dllnode *head;
	dllnode *tail;
	int size;
	void (*display)(FILE *,void *);
	} dll;

extern dll *newDLL(void (*d)(FILE *,void *));  		//constructor
extern dllnode *newDLLNode(void *a);
extern void insertDLL(dll *items,int index,void *value); //stores a generic value
extern void addToFrontDLL(dll *items, void *value);
extern void addToBackDLL(dll *items, void *value);
extern void *removeDLL(dll *items,int index);     	//returns a generic value
extern void *removeFromFrontDLL(dll *items);
extern void *removeFromBackDLL(dll *items);
extern void unionDLL(dll *front,dll *back); 	//merge two lists into one
extern void *getDLL(dll *items,int index);			//get the value at the index
extern int sizeDLL(dll *items);
extern void displayDLL(FILE *,dll *items);
extern dllnode *goToIndexDLL(int n, dll *items);
extern void joinDLL(dllnode *front, dllnode *back);
#endif
