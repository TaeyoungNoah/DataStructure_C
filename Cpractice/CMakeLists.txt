cmake_minimum_required(VERSION 3.21)
project(Cpractice C)

set(CMAKE_C_STANDARD 99)

add_executable(Cpractice
        book/chap07/ListBaseQueue/ListBaseQueue.h
        book/chap07/ListBaseQueue/ListBaseQueue.c book/chap07/ListBaseQueue/ListBaseQueueMain.c)
