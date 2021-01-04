cmake_minimum_required(VERSION 3.17)
project(hashtable)

set(CMAKE_C_FLAGS "-Wall -Wstrict-prototypes -ansi -pedantic")
set(SOURCE_FILES test_hash.c hash_table.c hash_table.h memcheck.h memcheck.c)
set(SOURCE_FILES_MAIN main.c hash_table.c hash_table.h memcheck.h memcheck.c)
#add_executable(test ${SOURCE_FILES})
add_executable(main ${SOURCE_FILES_MAIN})