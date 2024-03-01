cmake_minimum_required(VERSION 3.26)
project(Lab1_sem2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab1_sem2 main.c
        FileFillingFunctions.c
        FileFillingFunctions.h
        Functions.c
        Functions.h
        FileOutputFunctions.c
        FileOutputFunctions.h
        Tasks.c
        Tasks.h
)
