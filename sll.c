//sll.c
//By Hank King
//      For CS 201 at the University of Alabama
//      Spring 2017
//Function headers by John C Lusth 
//taken from http://beastie.cs.ua.edu/cs201/assign0.html
//The following code is a singly linked list data structure module.
#include "sll.h"
#include <stdlib.h>

//sll constructor
extern sll *newSLL(void (*d)(FILE *,void *)) //d is the display function
	{
	sll *items = malloc(sizeof(sll));
	if (items == 0)
		{
		fprintf(stderr,"out of memory");
		exit(-1);
		}
	items->head = 0;
	items->tail = 0;
	items->size = 0;
	items->display = d;
	return items;
	}

//sllnode constructor
extern sllnode *newSLLNode(void *a)
	{
	sllnode *item = malloc(sizeof(sllnode));
	if (item == 0)
		{
		fprintf(stderr,"out of memory");
		exit(-1);
		}
	item->next = 0;
	item->value = a;
	return item;
	}

//inserts an item at the index, "index" in zero based counting
extern void insertSLL(sll *items,int index,void *value) //stores a generic value
	{
	if (index > items->size + 1 || (items->size == 0 && index > 0) )
		{
		printf("invalid index in insertSLL");
		return;
		}

	if(index == 0)				//call add to front if necessary
		{
		addToFrontSLL(items, value);
		return;
		}
	if (index == items->size)	//call add to back if necessary
		{
		addToBackSLL(items, value);
		return;
		}

	sllnode *spot = goToIndexSLL(index - 1, items); //index -1 bc adding it after
	sllnode *spotNext = spot->next;		//stores node after spot for later
	sllnode *newIndex = newSLLNode(value);
	joinSLL(spot, newIndex);
	joinSLL(newIndex, spotNext);		//adds the rest of list after newIndex
	items->size++;
	return;
	}

//Adds a node to front of the list. Updates head pointer and tail pointer if
//the list was empty prior to call. Runs in constant time.
extern void addToFrontSLL(sll *items, void *value)
	{
	sllnode *newIndex = newSLLNode(value);
	newIndex->next = items->head;
	items->head = newIndex;
	if (items->size == 0)		//update tail if list was empty prior to call
		items->tail = newIndex;
	items->size++;
	return;
	}

//Adds a node to back of list. Updates tail pointer, redirects to addToFrontSLL
//if the list was empty prior to call. Runs in constant time.
extern void addToBackSLL(sll *items, void *value)
	{
	if (items->size == 0)	//if list is empty call add to front
		addToFrontSLL(items, value);
	sllnode *newIndex = newSLLNode(value);
	items->tail->next = newIndex;
	items->tail = newIndex;
	items->size++;
	return;
	}

//removes specified index in zero based counting. Returns value of removed index.
extern void *removeSLL(sll *items,int index)     	//returns a generic value
	{
	if (items->size == 0)
		{
		printf("Error: empty list.");
		return 0;
		}		
	if (index == 0 || items->size == 1)
		return removeFromFrontSLL(items);
	else if (index == items->size - 1)
		return removeFromBackSLL(items);
	
	sllnode *spot = goToIndexSLL(index - 1, items);//go to index before the one to remove
	sllnode *IndexToRemove = spot->next;
	joinSLL(spot,spot->next->next);
	void *val = IndexToRemove->value;
	free(IndexToRemove);
	items->size--;		
	return val;
	}

//removes index from front in constant time. Handles removal of the last 
//node in the list if necessary. Returns value of index removed.
extern void *removeFromFrontSLL(sll *items)
	{
	if (items->size == 1)	//handle removal of last node
		{
		sllnode *indexToRemove = items->head;
		items->head = NULL;
		items->tail = NULL;
		void *val = indexToRemove->value;
		free(indexToRemove);
		items->size = 0;
		return val;
		}
	sllnode *indexToRemove = items->head;
	void *val = items->head->value;
	items->head = items->head->next;
	free(indexToRemove);
	items->size--;
	return val;
	}

//removes last node in linear time. Returns value of node removed.
//calls removeFromFront if there is only one node in the list.
extern void *removeFromBackSLL(sll *items)
	{
	if (items->size == 1)
		return removeFromFrontSLL(items);
	sllnode *indexToRemove = items->tail;
	void *val = indexToRemove->value;
	sllnode *spot = goToIndexSLL(items->size - 2, items); //go to second to last index
	items->tail = spot;
	items->tail->next = NULL;
	free(indexToRemove);
	items->size--;
	return val;
	}

//adds the "back" sll onto the back of the "front" sll (renders front->back)
extern void unionSLL(sll *front,sll *back) 			//merge two lists into one
	{
	if (front->size == 0)	//handles addding to an empty list
		{
		front->head = back->head;
		front->tail = back->tail;
		front->size = back->size;
		back->tail = NULL;
		back->head = NULL;
		back->size = 0;
		return;
		}
	if (back->size == 0)		//handles adding an empty list to a nonempty one
		{
		return;
		}
	
	joinSLL(front->tail, back->head);	
	front->tail = back->tail;
	front->size = front->size + back->size;
	back->tail = NULL;
	back->head = NULL;
	back->size = 0;
	return;
	}

//returns the generic value at index in zero based counting
extern void *getSLL(sll *items,int index)			//get the value at the index
	{
	sllnode *spot = goToIndexSLL(index, items);
	return spot->value;
	}

//returns size of the sll (number of nodes)	
extern int sizeSLL(sll *items)
	{
	return items->size;
	}

//displays the value of each node in the sll front to back
extern void displaySLL(FILE *fp,sll *items)
	{
	sllnode *spot = items->head;
	if (spot == NULL || spot == 0)
		{
		fprintf(fp, "[]");
		return;
		}
	fprintf(fp, "[");
	items->display(fp, spot->value);
	if (spot != items->tail)
		fprintf(fp, ",");
	while(spot->next != NULL)
		{
		spot = spot->next;
		items->display(fp, spot->value);
		if (spot != items->tail)
			fprintf(fp, ",");
		}
	fprintf(fp, "]");
	return;
	}

//returns the sllnode at index n in zero based counting 
extern sllnode *goToIndexSLL(int n, sll *items)
	{
	if (n == items->size - 1) //return tail in constant time
		return items->tail;
	else if (n == 0)
		return items->head;		//return head in constant time
	
	sllnode *spot = items->head;
	int i = 0;
	while (spot != NULL && i < n)
		{
		spot = spot->next;
		i++;
		}
	return spot;	
	}

//joins 2 sllnodes
extern void joinSLL(sllnode *front, sllnode *back)
	{
	front->next = back;
	return;
	}
