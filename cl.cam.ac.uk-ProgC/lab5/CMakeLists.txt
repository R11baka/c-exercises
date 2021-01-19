cmake_minimum_required(VERSION 3.17)
project(cl_cam_ac_uk_ProgC)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES lab5.c expr.h expr.c parse.c parse.h memcheck.h memcheck.c)

add_executable(lab5 ${SOURCE_FILES})