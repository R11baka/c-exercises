cmake_minimum_required(VERSION 3.17)
project(cl_cam_ac_uk_ProgC C)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES lab3.c list.c list.h)

add_executable(lab3 ${SOURCE_FILES})