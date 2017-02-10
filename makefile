qtest:	qtest.o queue.o integer.o sll.o dll.o stack.o
	gcc qtest.o queue.o integer.o sll.o dll.o stack.o -o qtest
qtest.o:	qtest.c integer.h queue.h
	gcc -Wall -Wextra -g -c qtest.c
queue.o:	queue.c sll.h queue.h
	gcc -Wall -Wextra -g -c queue.c
integer.o:	integer.c integer.h
	gcc -Wall -Wextra -g -c integer.c
sll.o:	sll.c sll.h
	gcc -Wall -Wextra -g -c sll.c
stack.o:	stack.c dll.h stack.h
	gcc -Wall -Wextra -g -c stack.c
dll.o:	dll.c dll.h
	gcc -Wall -Wextra -g -c dll.c
clean:
	rm queue.o integer.o sll.o qtest.o stack.o dll.o qtest test
test: qtest
	./qtest  
