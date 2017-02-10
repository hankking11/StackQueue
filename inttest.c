#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

static void showItems(sll *items)
	{
	printf("The items are ");
	displaySLL(stdout,items);
	printf(".\n");
	}

int main(void)
	{
	
	/*
	sll *items = newSLL(displayInteger);
	showItems(items);
	printf("size is: %d\n", sizeSLL(items));
	insertSLL(items,0,newInteger(3));                   //insert at front
	insertSLL(items,sizeSLL(items),newInteger(2));      //insert at back
	insertSLL(items,1,newInteger(1));                   //insert at middle
	showItems(items);
	printf("size is: %d\n", sizeSLL(items));
	int i;
	for(i = 0; i < 6000; i++)
		{
		insertSLL(items,i + 3,newInteger(i) );           //insert at back
		showItems(items);
		printf("size is: %d\n", sizeSLL(items));
		}
	
	for(i = 0; i < 10; i++)
		{
		printf("start loop\n");
		printf("The value ");
		displayInteger(stdout,removeSLL(items,0));          //remove from front
		printf(" was removed.\n");
		showItems(items);
		printf("size is: %d\n", sizeSLL(items));
		printf("end loop\n");
		}
	printf("finished size 10 loop\n");
	
	for(i = 0; i < 6; i++)
		{
		insertSLL(items,0,newInteger(i) );           //insert at middle
		showItems(items);
		printf("size is: %d\n", sizeSLL(items));
		}
	
	for(i = 0; i < 10; i++)
		{
		printf("The value ");
		displayInteger(stdout,removeSLL(items,items->size - 1));//remove from back
		printf(" was removed.\n");
		showItems(items);
		printf("size is: %d\n", sizeSLL(items));
		}
	
	printf("The value ");
	displayInteger(stdout,removeSLL(items,0));          //remove from front
	printf(" was removed.\n");
	
	printf("The value ");
	displayInteger(stdout,removeSLL(items,0));          //remove from front
	printf(" was removed.\n");
	
	showItems(items);
	printf("size is: %d\n", sizeSLL(items));
//	int x = getInteger((integer *) getSLL(items,0));    //get the first item
//	printf("The first item is\n %d.\n",x);
	*/

sll *a = newSLL(displayInteger);
    insertSLL(a,0,newInteger(0));
    insertSLL(a,0,newInteger(1));
    insertSLL(a,0,newInteger(2));
    insertSLL(a,0,newInteger(3));
    insertSLL(a,0,newInteger(4));
    insertSLL(a,0,newInteger(5));
    insertSLL(a,0,newInteger(6));
    insertSLL(a,0,newInteger(7));
    insertSLL(a,0,newInteger(8));
    insertSLL(a,0,newInteger(9));
    displaySLL(stdout,a);
	return 0;
	}
