cmake_minimum_required(VERSION 3.17)
project(cl_cam_ac_uk_ProgC)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES lab6.c graph.c graph.h)

add_executable(lab6 ${SOURCE_FILES})