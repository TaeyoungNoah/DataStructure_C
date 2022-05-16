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
#        chap07/Problem07-1/Deque.h
#        chap07/Problem07-1/Deque.c
#        chap07/Problem07-1/DequeBaseQueue.h
#        chap07/Problem07-1/DequeBaseQueue.c
#        chap07/Problem07-1/DQBQueueMain.c


        # ========================================== CHAP 08 ================================================
        # 이진 트리
#        chap08/BinaryTree/BinaryTree.h
#        chap08/BinaryTree/BinaryTree.c
#        chap08/BinaryTree/BinaryTreeMain.c

        # 2진트리 순회까지
#        chap08/BinaryTree2/BinaryTree2.h
#        chap08/BinaryTree2/BinaryTree2.c
#        chap08/BinaryTree2/BinaryTree2Main.c

        # 수식 트리
#        chap08/ExpressionTree/BinaryTree2.h
#        chap08/ExpressionTree/BinaryTree2.c
#        chap08/ExpressionTree/ExpressionTree.h
#        chap08/ExpressionTree/ExpressionTree.c
#        chap08/ExpressionTree/ExpressionTreeMain.c
#        chap08/ExpressionTree/ListBaseStack.h
#        chap08/ExpressionTree/ListBaseStack.c

        # Problem08-2 : 수식 트리 괄호 넣기
#        chap08/Problem08-2/BinaryTree2.h
#        chap08/Problem08-2/BinaryTree2.c
#        chap08/Problem08-2/ExpressionTree.h
#        chap08/Problem08-2/ExpressionTree.c
#        chap08/Problem08-2/ExpressionTreeMain.c
#        chap08/Problem08-2/ListBaseStack.h
#        chap08/Problem08-2/ListBaseStack.c


        # ========================================== CHAP 08 ================================================
        # 간단한 Heap
#        chap09/SimpleHeap/SimpleHeap.h
#        chap09/SimpleHeap/SimpleHeap.c
#        chap09/SimpleHeap/SimpleHeapMain.c

        # 유용한 Heap
#        chap09/UsefulHeap/UsefulHeap.h
#        chap09/UsefulHeap/UsefulHeap.c
#        chap09/UsefulHeap/UsefulHeapMain.c

        # 우선순위 큐
#        chap09/PriorityQueue/UsefulHeap.h
#        chap09/PriorityQueue/UsefulHeap.c
#        chap09/PriorityQueue/PriorityQueue.h
#        chap09/PriorityQueue/PriorityQueue.c
#        chap09/PriorityQueue/PriorityQueueMain.c




        # ========================================== BOJ ================================================

        # -------------------chap08-------------------
        # 1991 : 트리 순회 (트리 만들기부터)
#        BOJ/chap08/1991/BinaryTree2.h
#        BOJ/chap08/1991/BinaryTree2.c
#        BOJ/chap08/1991/1991_package.c
#        BOJ/chap08/1991/1991.c

        # 2263 : 트리 순회 (과제 6)
#        BOJ/chap08/2263/2263.c


        # -------------------chap09-------------------
        # 1966 프린터 큐 : 중요도를 판단해서 출력
        BOJ/chap09/1966/UsefulHeap.h
        BOJ/chap09/1966/UsefulHeap.c
        BOJ/chap09/1966/PriorityQueue.h
        BOJ/chap09/1966/PriorityQueue.c
        BOJ/chap09/1966/1966_package.c

        )
