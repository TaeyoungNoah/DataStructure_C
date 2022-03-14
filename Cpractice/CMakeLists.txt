cmake_minimum_required(VERSION 3.21)
project(Cpractice C)

set(CMAKE_C_STANDARD 99)

add_executable(Cpractice
        book/chap07/Problem07-1/Deque.h
        book/chap07/Problem07-1/Deque.c
        book/chap07/Problem07-1/DequeBaseQueue.h book/chap07/Problem07-1/DequeBaseQueue.c book/chap07/Problem07-1/DQBQueueMain.c)
