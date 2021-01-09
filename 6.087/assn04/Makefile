CC = gcc
CFLAGS = -Wall -Wstrict-prototypes -ansi -pedantic -std=c11

build:
	$(CC) $(CFLAGS) main.c src/treeNode.c src/memcheck.c -o main

run:build
	./main

clean:
	rm -f *.o *.mem main