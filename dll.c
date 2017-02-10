//dll.c
//By Hank King
//      For CS 201 at the University of Alabama
//      Spring 2017
//Function headers by John C Lusth 
//taken from http://beastie.cs.ua.edu/cs201/assign0.html
//The following code is a singly linked list data structure module.
#include "dll.h"
#include <stdlib.h>

//dll constructor
extern dll *newDLL(void (*d)(FILE *,void *)) //d is the display function
	{
	dll *items = malloc(sizeof(dll));
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

//dllnode constructor
extern dllnode *newDLLNode(void *a)
	{
	dllnode *item = malloc(sizeof(dllnode));
	if (item == 0)
		{
		fprintf(stderr,"out of memory");
		exit(-1);
		}
	item->next = 0;
	item->prev = 0;
	item->value = a;
	return item;
	}

//inserts an item at the index, "index" in zero based counting
extern void insertDLL(dll *items,int index,void *value) //stores a generic value
	{
	if (index > items->size + 1 || (items->size == 0 && index > 0) )
		{
		printf("invalid index in insertDLL");
		return;
		}

	if(index == 0)				//call add to front if necessary
		{
		addToFrontDLL(items, value);
		return;
		}
	if (index == items->size)	//call add to back if necessary
		{
		addToBackDLL(items, value);
		return;
		}

	dllnode *spot = goToIndexDLL(index - 1, items); //index -1 bc adding it after
	dllnode *spotNext = spot->next;		//stores node after spot for later
	dllnode *newIndex = newDLLNode(value);
	joinDLL(spot, newIndex);
	joinDLL(newIndex, spotNext);		//adds the rest of list after newIndex
	items->size++;
	return;
	}

//Adds a node to front of the list. Updates head pointer and tail pointer if
//the list was empty prior to call. Runs in constant time.
extern void addToFrontDLL(dll *items, void *value)
	{
	dllnode *newIndex = newDLLNode(value);
	
	if (items->size == 0) //handle first entry	
		{
		items->tail = newIndex;
		items->head = newIndex;
		items->size++;
		return;
		}
	joinDLL(newIndex, items->head);
	items->head = newIndex;
	items->size++;
	return;
	}

//Adds a node to back of list. Updates tail pointer, redirects to addToFrontDLL
//if the list was empty prior to call. Runs in constant time.
extern void addToBackDLL(dll *items, void *value)
	{
	if (items->size == 0)	//if list is empty call add to front
		addToFrontDLL(items, value);
	dllnode *newIndex = newDLLNode(value);
	joinDLL(items->tail, newIndex);
	items->tail = newIndex;
	items->size++;
	return;
	}

//removes specified index in zero based counting. Returns value of removed index.
extern void *removeDLL(dll *items,int index)     	//returns a generic value
	{
	if (items->size == 0)
		{
		printf("Error: empty list.");
		return 0;
		}		
	if (index == 0 || items->size == 1)
		return removeFromFrontDLL(items);
	else if (index == items->size - 1)
		return removeFromBackDLL(items);
	
	dllnode *spot = goToIndexDLL(index - 1, items);//go to index before the one to remove
	dllnode *IndexToRemove = spot->next;
	joinDLL(spot,spot->next->next);
	void *val = IndexToRemove->value;
	free(IndexToRemove);
	items->size--;		
	return val;
	}

//removes index from front in constant time. Handles removal of the last 
//node in the list if necessary. Returns value of index removed.
extern void *removeFromFrontDLL(dll *items)
	{
	if (items->size == 1)	//handle removal of last node
		{
		dllnode *indexToRemove = items->head;
		items->head = NULL;
		items->tail = NULL;
		void *val = indexToRemove->value;
		free(indexToRemove);
		items->size = 0;
		return val;
		}
	dllnode *indexToRemove = items->head;
	void *val = items->head->value;
	items->head = items->head->next;
	items->head->prev = 0;
	free(indexToRemove);
	items->size--;
	return val;
	}

//removes last node in linear time. Returns value of node removed.
//calls removeFromFront if there is only one node in the list.
extern void *removeFromBackDLL(dll *items)
	{
	if (items->size == 1)
		return removeFromFrontDLL(items);
	dllnode *indexToRemove = items->tail;
	void *val = indexToRemove->value;
	dllnode *spot = items->tail->prev; //go to second to last index
	items->tail = spot;
	items->tail->next = NULL;
	free(indexToRemove);
	items->size--;
	return val;
	}

//adds the "back" dll onto the back of the "front" dll (renders front->back)
extern void unionDLL(dll *front,dll *back) 			//merge two lists into one
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
	joinDLL(front->tail, back->head);
	front->tail = back->tail;
	front->size = front->size + back->size;
	back->tail = NULL;
	back->head = NULL;
	back->size = 0;
	return;
	}

//returns the generic value at index in zero based counting
extern void *getDLL(dll *items,int index)			//get the value at the index
	{
	dllnode *spot = goToIndexDLL(index, items);
	return spot->value;
	}

//returns size of the dll (number of nodes)	
extern int sizeDLL(dll *items)
	{
	return items->size;
	}

//displays the value of each node in the dll front to back
extern void displayDLL(FILE *fp,dll *items)
	{
	dllnode *spot = items->head;
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

//returns the dllnode at index n in zero based counting 
extern dllnode *goToIndexDLL(int n, dll *items)
	{
	if (n == items->size - 1) //return tail in constant time
		return items->tail;
	else if (n == 0)
		return items->head;		//return head in constant time
	if(n <= items->size / 2) 	//if index is in first half of list
		{						//start from front, walk forward
		dllnode *spot = items->head;
		int i = 0;
		while (spot != NULL && i < n)
			{
			spot = spot->next;
			i++;
			}
		return spot;	
		}
	else 					 	//if index is in second half of list
		{						//start from back, walk towards the front
		dllnode *spot = items->tail;
		int i = items->size - 1;
		while (spot != NULL && i > n)
			{
			spot = spot->prev;
			i--;
			}
		return spot;	
		}
	
	}

//joins 2 dllnodes
extern void joinDLL(dllnode *front, dllnode *back)
	{
	front->next = back;
	back->prev = front;
	return;
	}
