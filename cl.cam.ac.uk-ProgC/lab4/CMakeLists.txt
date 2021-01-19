cmake_minimum_required(VERSION 3.17)
project(cl_cam_ac_uk_ProgC)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES lab4.c tree.c tree.h memcheck.c memcheck.h bst.c bst.h)

add_executable(lab4 ${SOURCE_FILES})