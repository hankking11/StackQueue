#include <stdio.h>
#include "queue.h"
#include "integer.h"
#include "stack.h"
#include "dll.h"
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
	int i;
	dll *dlist = newDLL(displayInteger);
/*	for(i = 0; i < 10; i++)
		{
		insertDLL(dlist, 0, newInteger(i));
		printf("The value(%d) was added\n", i);
		showItems(dlist);
		printf("size is: %d\n", sizeDLL(dlist));
		}
	*/
	dll *b = newDLL(displayInteger);
    dll *c = newDLL(displayInteger);
    //(inserting 100 random integers into list a at random locations)
    for(i = 0; i < 10; i++)
		insertDLL(b, 0, newInteger(i));
	//(inserting 100 random integers into list b at random locations)
    for(i = 0; i < 10; i++)
		insertDLL(c, 0,newInteger(i));
    //(unioning list a and list b, 10000 times)
	

	printf("b is: ");
	displayDLL(stdout,b);
    printf("\nc is: ");
    displayDLL(stdout,c);	
	printf("\n");
  	unionDLL(b,c);
	
	for(i = 0; i < 10; i++)
		{
		unionDLL(b,c);
	printf("LOOP - b is: ");
	displayDLL(stdout,b);
    printf("\nc is: ");
    displayDLL(stdout,c);	
		unionDLL(c,b);
	printf("LOOP - b is: ");
	displayDLL(stdout,b);
    printf("\nc is: ");
    displayDLL(stdout,c);	
	printf("\n");
		} 
	printf("b is: ");
	displayDLL(stdout,b);
    printf("\nc is: ");
    displayDLL(stdout,c);	
	printf("\n");
	
	unionDLL(c,b);
	printf("b is: ");
	displayDLL(stdout,b);
    printf("\nc is: ");
    displayDLL(stdout,c);	
	printf("\n");
	return 0;
	}
