#include <stdio.h>
   #include <stdlib.h>
   #include "stack.h"
   #include "integer.h"
   static void showStack(stack *s)
       {
       printf("The stack is ");
       displayStack(stdout,s);
       printf(".\n");
       }

   int main(int argc,char **argv)
       {
       stack *items = newStack(displayInteger);
       showStack(items);
       push(items,newInteger(3));
       push(items,newInteger(2));
       showStack(items);
       printf("The value ");
       displayInteger(stdout,pop(items));
       printf(" was popped.\n");
       showStack(items);
	
	
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
	
       return 0;
       }
