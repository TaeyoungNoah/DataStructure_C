cmake_minimum_required(VERSION 3.21)
project(FinalExam C)

set(CMAKE_C_STANDARD 99)

add_executable(FinalExam
#        main.c


        # ========================================== CHAP 07 ================================================
        # 원형 큐
#        chap07/CircularQueue/CircularQueue.h
#        chap07/CircularQueue/CircularQueue.c
#        chap07/CircularQueue/CircularQueueMain.c

        # 연결 리스트 기반 큐
#        chap07/ListBaseQueue/ListBaseQueue.h
#        chap07/ListBaseQueue/ListBaseQueue.c
#        chap07/ListBaseQueue/ListBaseQueueMain.c

        # 햄버거 시뮬레이션
#        chap07/HamburgerSim/CircularQueue.h
#        chap07/HamburgerSim/CircularQueue.c
#        chap07/HamburgerSim/HamburgerSimMain.c

        # 덱
#        chap07/Deque/Deque.h
#        chap07/Deque/Deque.c
#        chap07/Deque/DequeMain.c

        # Problem07-1 : 덱으로 큐 만들기
        chap07/Problem07-1/Deque.h
        chap07/Problem07-1/Deque.c
        chap07/Problem07-1/DequeBaseQueue.h
        chap07/Problem07-1/DequeBaseQueue.c
        chap07/Problem07-1/DQBQueueMain.c)
