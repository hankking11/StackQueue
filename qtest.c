#include <stdio.h>
#include "queue.h"
#include "integer.h"
#include "stack.h"
static void showStack(stack *s)
       {
       printf("The stack is ");
       displayStack(stdout,s);
       printf(".\n");
       }
static void showItems(dll *items)
    {
    printf("The items are ");
    displayDLL(stdout,items);
    printf(".\n");
    }

int main(void)
	{
	queue *items = newQueue(displayInteger);
	int i;
	for(i = 0; i < 4; i++)
		{
		printf("Enqueuing %d\n", i);
		enqueue(items, newInteger(i) );
		printf("The queue is ");
		displayQueue(stdout, items);
		printf(".\n");
		printf("size is: %d", items->list->size);
		printf("\n");
		}
	for(i = 0; i < 5; i++)
		{
		printf("peek shows the next value to dequeue is: ");
		displayInteger(stdout, peekQueue(items) );
		printf(".\n");
		printf("dequeuing the value: ");
		displayInteger(stdout, dequeue(items) );
		printf(". The queue is now ");
		displayQueue(stdout, items);
		printf(".\n");
		printf("size is: %d", sizeQueue(items) );
		printf("\n");
		}
	
	for(i = 0; i < 3; i++)
		{
		printf("Enqueuing %d\n", i);
		enqueue(items, newInteger(i) );
		printf("The queue is ");
		displayQueue(stdout, items);
		printf(".\n");
		printf("size is: %d", items->list->size);
		printf("\n");
		}
	printf("about to enter 200 values into the queue\n");
	for(i = 0; i < 200; i++)
		enqueue(items, newInteger(i + 1) );

	printf("The queue is ");
	displayQueue(stdout, items);
	printf(".\n");
	printf("size is: %d", items->list->size);
	printf("\n");
	stack *items2 = newStack(displayInteger);
       showStack(items2);
       push(items2,newInteger(3));
       push(items2,newInteger(2));
       showStack(items2);
       printf("The value ");
       displayInteger(stdout,pop(items2));
       printf(" was popped.\n");
       showStack(items2);
	dll *dlist = newDLL(displayInteger);
	showItems(dlist);
	printf("size is: %d\n", sizeDLL(dlist));
	insertDLL(dlist,0,newInteger(3));                   //insert at front
	insertDLL(dlist,sizeDLL(dlist),newInteger(2));      //insert at back
	insertDLL(dlist,1,newInteger(1));                   //insert at middle
	showItems(dlist);
	printf("size is: %d\n", sizeDLL(dlist));
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
	printf(" was removed\n");
	dll *b = newDLL(displayInteger);
    dll *c = newDLL(displayInteger);
    //(inserting 100 random integers into list a at random locations)
    for(i = 0; i < 100; i++)
		insertDLL(b, 0, newInteger(i));
	insertDLL(b, 1, newInteger(7));
	//(inserting 100 random integers into list b at random locations)
    for(i = 0; i < 100; i++)
		insertDLL(c, 0,newInteger(i));
	insertDLL(c, 1, newInteger(7));
    //(unioning list a and list b, 10000 times)
    for(i = 0; i < 4; i++)
		{
		unionDLL(b,c);
		unionDLL(c,b);
		}
	printf("b is: ");
	displayDLL(stdout,b);
    printf("\nc is: ");
    displayDLL(stdout,c);	
	printf("\n");
	


	sll *x = newSLL(displayInteger);
	sll *y = newSLL(displayInteger);

    for(i = 0; i < 100; i++)
		insertSLL(x, 0, newInteger(i));
	insertSLL(x, 1, newInteger(7));
	//(inserting 100 random integers into list b at random locations)
    for(i = 0; i < 100; i++)
		insertSLL(y, 0,newInteger(i));
	insertSLL(y, 1, newInteger(7));
    //(unioning list a and list b, 10000 times)
	printf("x is: ");
	displaySLL(stdout,x);
    printf("\ny is: ");
    displaySLL(stdout,y);	
	printf("\n");
    for(i = 0; i < 4; i++)
		{
		unionSLL(x,y);
		
		printf("x is: ");
		displaySLL(stdout,x);
    	printf("\ny is: ");
    	displaySLL(stdout,y);	
		printf("\n");
		
		unionSLL(y,x);
		
		printf("x is: ");
		displaySLL(stdout,x);
	    printf("\ny is: ");
	    displaySLL(stdout,y);	
		printf("\n");
		}
	printf("x is: ");
	displaySLL(stdout,x);
    printf("\ny is: ");
    displaySLL(stdout,y);	
	printf("\n");
	



	return 0;
	}
