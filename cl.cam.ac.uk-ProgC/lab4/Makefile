CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic
THIS_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
INCS = lab4.c tree.c tree.h
BIN = lab4

all:
	gcc -Wall -c lab4.c
	gcc -Wall -c tree.c 
	gcc -fsanitize=address  -o lab4 lab4.o tree.o

clean:
	rm -f lab4.o tree.o lab4
