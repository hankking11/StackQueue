#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "integer.h"

static void showItems(dll *dlist)
	{
	printf("The dlist are ");
	displayDLL(stdout,dlist);
	printf(".\n");
	}

int main(void)
	{
	
	
	dll *dlist = newDLL(displayInteger);
	showItems(dlist);
	printf("size is: %d\n", sizeDLL(dlist));
	insertDLL(dlist,0,newInteger(3));                   //insert at front
	insertDLL(dlist,sizeDLL(dlist),newInteger(2));      //insert at back
	insertDLL(dlist,1,newInteger(1));                   //insert at middle
	showItems(dlist);
	printf("size is: %d\n", sizeDLL(dlist));
	int i;
	for(i = 0; i < 10; i++)
		{
		insertDLL(dlist,i + 3,newInteger(i) );           //insert at back
		showItems(dlist);
		printf("size is: %d\n", sizeDLL(dlist));
		}
	
	for(i = 0; i < 4; i++)
		{
		printf("start loop\n");
		printf("The value ");
		displayInteger(stdout,removeDLL(dlist,0));          //remove from front
		printf(" was removed.\n");
		showItems(dlist);
		printf("size is: %d\n", sizeDLL(dlist));
		printf("end loop\n");
		}
	printf("finished size 4 loop\n");
	
	for(i = 0; i < 6; i++)
		{
		insertDLL(dlist,7,newInteger(i) );           //insert at middle
		showItems(dlist);
		printf("size is: %d\n", sizeDLL(dlist));
		}
	
	for(i = 0; i < 10; i++)
		{
		printf("The value ");
		displayInteger(stdout,removeDLL(dlist,dlist->size - 2));//remove from back
		printf(" was removed.\n");
		showItems(dlist);
		printf("size is: %d\n", sizeDLL(dlist));
		}
	
	printf("The value ");
	displayInteger(stdout,removeDLL(dlist,0));          //remove from front
	printf(" was removed.\n");
	
	printf("The value ");
	displayInteger(stdout,removeDLL(dlist,0));          //remove from front
	printf(" was removed.\n");
	
	showItems(dlist);
	printf("size is: %d\n", sizeDLL(dlist));
//	int x = getInteger((integer *) getDLL(dlist,0));    //get the first item
//	printf("The first item is\n %d.\n",x);
	

dll *a = newDLL(displayInteger);
	iinclude "dll.h"
    printf("complete\n");
	insertDLL(a,0,newInteger(0));
    printf("complete\n");
    insertDLL(a,0,newInteger(1));
    printf("complete\n");
    insertDLL(a,0,newInteger(2));
    printf("complete\n");
    insertDLL(a,0,newInteger(3));
    printf("complete\n");
    insertDLL(a,0,newInteger(4));
    printf("complete\n");
    insertDLL(a,0,newInteger(5));
    printf("complete\n");
    insertDLL(a,0,newInteger(6));
    printf("complete\n");
    insertDLL(a,0,newInteger(7));
    printf("complete\n");
    insertDLL(a,0,newInteger(8));
    printf("complete\n");
    insertDLL(a,0,newInteger(9));
    printf("complete\n");
    displayDLL(stdout,a);
	return 0;
	}
