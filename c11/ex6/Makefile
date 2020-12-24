#
# Makefile for C track, assignment 6.
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

quicksorter: quicksorter.o linked_list.o memcheck.o
	$(CC) quicksorter.o linked_list.o memcheck.o -o quicksorter

quicksorter.o: quicksorter.c src/linked_list.h
	$(CC) $(CFLAGS) -c quicksorter.c

linked_list.o: src/linked_list.c src/linked_list.h
	$(CC) $(CFLAGS) -c src/linked_list.c

memcheck.o: src/memcheck.c src/memcheck.h
	$(CC) $(CFLAGS) -c src/memcheck.c

test:
	./run_test

main:
	./quicksorter 1 2 

check:
	c_style_check quicksorter.c

clean:
	rm -f *.o quicksorter



