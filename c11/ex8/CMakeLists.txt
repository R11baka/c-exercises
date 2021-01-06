cmake_minimum_required(VERSION 3.17)
project(vm)

set(CMAKE_C_FLAGS "-g  -Wall -Wstrict-prototypes -ansi -pedantic")
set(SOURCE_FILES bci.h bci.c main.c)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
add_executable(bci ${SOURCE_FILES})