Program to write
The program to write for this assignment is a variation on assignment 3. Recall that in that program, you inputted a list of numbers and the program printed them out in sorted order. This time you will be doing the same thing, with these differences:

You will use a linked list to store the numbers entered on the command line. This will have the advantage that you can enter an arbitrary number of numbers (i.e. you’re not limited to just 32 numbers).

You will use the quicksort algorithm to sort the numbers instead of the minimal insertion sort or bubble sort. Quicksort is much more efficient than those algorithms, and is described below.

Your program will be called quicksorter and the source code will be in a file called quicksorter.c. Here is the specification:

The program will accept an arbitrary number of numbers on the command line, as long as there is at least one number.

If there are no command-line arguments, or if there are arguments but none that represent numbers to be sorted, the program should print out instructions on its use (i.e. a usage message). By the way, don’t assume that the test script checks this; currently it doesn’t, so check it yourself (we will).

If any of the arguments to the program are not integers, your program’s response is undefined — it can do anything (in other words, you shouldn’t worry about handling non-integer arguments). The only exception to this is the optional -q argument to suppress output (see below).

The program will sort the numbers using the quicksort algorithm. The numbers on the command line will be stored in a linked list. You should have a separate quicksort function to do the sorting. This function should receive exactly one argument (the list to be sorted) and return a pointer to a newly-allocated list which contains the same integers as the input list, but in sorted (ascending) order. Do not alter the original list in any way. Also, do not pass the length of the list to the quicksort function (it isn’t necessary anyway).

As in assignment 3, use assert to check that the list is sorted after doing the sort. Use the is_sorted() function in linked_list.c to check the list. Put the assert check at the end of the quicksort function, right before it returns the sorted list.

Print out the numbers from smallest to largest, one per line.

Use the memory leak checker as in the previous assignment to check that there are no memory leaks.

Example output
$ quicksorter 5 9 -2 150 -95 23 2 5 80
-95
-2
2
5
5
9
23
80
150
$ quicksorter
usage: quicksorter [-q] number1 [number2 ... ]