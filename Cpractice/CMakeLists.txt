cmake_minimum_required(VERSION 3.21)
project(Cpractice C)

set(CMAKE_C_STANDARD 99)

add_executable(Cpractice
        Self/chap03/ArrayListPoint/ArrayList.h
        Self/chap03/ArrayListPoint/ArrayList.c
        Self/chap03/ArrayListPoint/Point.h
        Self/chap03/ArrayListPoint/Point.c
        Self/chap03/ArrayListPoint/PointListMain.c)
