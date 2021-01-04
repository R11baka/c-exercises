Program to write
Your program will use a hash table to count the number of occurrences of words in a text file. The basic algorithm goes as follows. For each word in the file:

Look up the word in the hash table.

If it isn’t there, add it to the hash table with a value of 1. In this case you’ll have to create a new node and link it to the hash table as described above.

If it is there, add 1 to its value. In this case you don’t create a new node.

At the end of the program, you should output all the words in the file, one per line, with the count next to the word e.g.

cat 2
hat 4
green 12
eggs 3
ham 5
algorithmic 14
deoxyribonucleic 3
dodecahedron 400
Also, make sure that you explicitly free all memory that you’ve allocated during the run of the program before your program exits. This includes:

all the nodes in the linked lists that the hash table’s node pointer array points to,

the hash table’s node pointer array itself,

the hash table struct itself,

the string keys used in the linked list nodes (allocated in the main() function (see below)).

The memory leak checker will help ensure that you get this right.

The hash function
The hash function you will use is extremely simple: it will

go through the string a character at a time,

convert each character to an integer,

add up the integer values,

and return the sum modulo 128.

(Don’t hard-code the number 128 into your code; that would be an example of the "magic number" pitfall we’ve discussed previously.)
This will give an integer in the range of [0, 127]. This is a poor hash function; for one thing, anagrams will always hash to the same value. However, it’s very simple to implement. Note that a value of type char in a C program can also be treated as if it were an int, because internally it’s a one-byte integer represented by the ASCII character encoding. If you like, you can convert the char to an int explicitly using a type cast. However, a string of characters is not an int, and you can’t use atoi to convert it into one (mainly because most of the keys will be words, not string representations of numbers). You also shouldn’t try to type cast the string to an int (it’ll just cast the address into an integer, which might work but it’s not what you want). A string is an array of chars, which is not the same as a single char; keep that in mind. So you’ll need a loop to go through the string character-by-character.

Other details
Since a value associated with a key will always be positive, if you search for a key and don’t find it in a hash table, just return 0. That’s the special "not found" value for this hash table.

For simplicity, the program assumes that the input file has one word per line (we’ve written this code for you). The order of the words you output isn’t important, since the test script will sort them.

Things to watch out for
You should design your hash table functions to be generic i.e. independent of the purpose those functions are used for. Specifically, don’t assume that particular values to be assigned mean anything special (for instance, don’t assume that the value represents the count of the keys, just because that’s how it will be used in the rest of the program). You should think of the hash table functions as being part of a hash table library that you are writing. Functions in a library could be used in many different programs, so the fewer the assumptions you make about how the functions will be used, the better. The only exception to this is the rule that says if you are searching for a key and it isn’t found, you should return zero. That’s not very generic (you can imagine a hash table in which it would be OK to store a value of zero), but it makes the program simpler.

There is one memory leak which may be hard to get rid of which involves the set_value function. You should assume that the key value that is passed to set_value is newly-allocated, and so it either has to go into the hash table or it has to be freed.

