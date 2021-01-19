cmake_minimum_required(VERSION 3.17)
project(doublePointers C)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES main.c src/linkedList.c src/linkedList.h src/memcheck.c)

add_executable(main ${SOURCE_FILES})