#
# CS 11 C track: Makefile for assignment 4.
#
CC = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

build-lab5_array:
	$(CC) $(CFLAGS) lab5_array.c memcheck.c -o lab5_array

build-lab5_pointer:
	$(CC) $(CFLAGS) lab5_pointer.c memcheck.c -o lab5_pointer

run_lab5_array: build-lab5_array
	./lab5_array 50 10

run_lab5_pointer: build-lab5_pointer
	./lab5_pointer 50 10

clean:
	rm -f *.o lab5_array

