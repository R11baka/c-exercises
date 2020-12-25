#
# Makefile for C track, assignment 6.
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic
THIS_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
INCS = quicksorter.c src/linked_list.c src/memcheck.c
BIN = main

all:main
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

build_docker:
	docker run --workdir $(THIS_DIR) --entrypoint $(CC) -v $(THIS_DIR):$(THIS_DIR) mooreryan/valgrind  src/memcheck.c src/linked_list.c quicksorter.c -o $(BIN)

valgrind: build_docker
	docker run --workdir $(THIS_DIR) -v $(THIS_DIR):$(THIS_DIR) mooreryan/valgrind  --leak-check=full --show-leak-kinds=all ./main 1 2 3

main: quicksorter
	./quicksorter 1 4 3

check:
	c_style_check quicksorter.c

clean:
	rm -f *.o quicksorter *.out main



