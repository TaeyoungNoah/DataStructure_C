cmake_minimum_required(VERSION 3.21)
project(Cpractice C)

set(CMAKE_C_STANDARD 99)

add_executable(Cpractice
        book/chap07/CircularQueue/CircularQueue.h
        book/chap07/CircularQueue/CircularQueue.c book/chap07/CircularQueue/CircularQueueMain.c)
