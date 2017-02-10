#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "integer.h"
#include "sll.h"

int main(int argc,char **argv)
	{
	printf("Hello world!\n");
	sll *items = newSLL(displayInteger);
	insertSLL(items, 0, newInteger(1));
	insertSLL(items, 0, newInteger(2));
	insertSLL(items, 2, newInteger(3));
//	sllnode *new = newSLLNode(newInteger(3));
//	items->head = new;
	displaySLL(stdout, items);
	printf("should be [2,1,3]\n");
	return 0;
	}
/*
void
Fatal(char *fmt, ...)
    {
    va_list ap;

    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
    }
*/
