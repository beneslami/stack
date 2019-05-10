CC = gcc
default = main

main: main.o stack.o
	$(CC) stack.o main.o -o a.out

main.o:
	$(CC) -c main.c

stack.o: stack.c stack.h
	$(CC) -c stack.c stack.h

clean:
	rm -rf *.o *.gch *.out
