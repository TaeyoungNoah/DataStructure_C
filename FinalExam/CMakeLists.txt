cmake_minimum_required(VERSION 3.21)
project(FinalExam C)

set(CMAKE_C_STANDARD 99)

add_executable(FinalExam
#        main.c


#        EXAM/practice/new.c




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


        # ========================================== CHAP 09 ================================================
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

        # Problem09-1 : 문자열 저장하고, 저장된 문자열 꺼내서 출력. 짧을수록 우선순위 높음
#        chap09/Problem09-1/UsefulHeap.h
#        chap09/Problem09-1/UsefulHeap.c
#        chap09/Problem09-1/PriorityQueue.h
#        chap09/Problem09-1/PriorityQueue.c
#        chap09/Problem09-1/PriorityQueueMain.c



        # ========================================== CHAP 10 ================================================
        # ====== O(n^2) ======
        # 버블 정렬
#        chap10/Sort/BubbleSort.c

        # 선택 정렬
#        chap10/Sort/SelectionSort.c

        # 삽입 정렬
#        chap10/Sort/InsertionSort.c

        # ====== O(nlog2n) ======
        # 힙정렬
#        chap10/HeapSort/UsefulHeap.h
#        chap10/HeapSort/UsefulHeap.c
#        chap10/HeapSort/HeapSort.c

        # 병합 정렬
#        chap10/Sort/MergeSort.c


        # 퀵 정렬
#        chap10/Sort/QuickSort.c

        # Problem 10-1 퀵정렬 개선
#        chap10/Problem10-1/QuickSort.c

        # 기수 정렬
#        chap10/RadixSort/ListBaseQueue.h
#        chap10/RadixSort/ListBaseQueue.c
#        chap10/RadixSort/RadixSort.c


        # ========================================== CHAP 11 ================================================
        # 이진 탐색
#        chap11/RecursiveBinarySearch.c

        # 보간 탐색
#        chap11/InterpolSearch.c

        # 이진 탐색 트리
#        chap11/BinarySearchTree/BinarySearchTree.h
#        chap11/BinarySearchTree/BinarySearchTree.c
#        chap11/BinarySearchTree/BinaryTree2.h
#        chap11/BinarySearchTree/BinaryTree2.c
#        chap11/BinarySearchTree/BinarySearchTreeMain.c

        # 이진 탐색 트리 삭제까지
        chap11/BinarySearchTreeDelAdded/BinarySearchTree2.h
        chap11/BinarySearchTreeDelAdded/BinarySearchTree2.c
        chap11/BinarySearchTreeDelAdded/BinaryTree3.h
        chap11/BinarySearchTreeDelAdded/BinaryTree3.c
        chap11/BinarySearchTreeDelAdded/BinarySearchTreeDelMain.c

        # ========================================== CHAP 14 ================================================
        # 그래프 구현
#        chap14/ALGraph/DLinkedList.h
#        chap14/ALGraph/DLinkedList.c
#        chap14/ALGraph/ALGraph.h
#        chap14/ALGraph/ALGraph.c
#        chap14/ALGraph/ALGraphMain.c

        # DFS : 깊이 우선 탐색 (비밀)
#        chap14/ALGraphDFS/DLinkedList.h
#        chap14/ALGraphDFS/DLinkedList.c
#        chap14/ALGraphDFS/ArrayBaseStack.h
#        chap14/ALGraphDFS/ArrayBaseStack.c
#        chap14/ALGraphDFS/ALGraphDFS.h
#        chap14/ALGraphDFS/ALGraphDFS.c
#        chap14/ALGraphDFS/DFSMain.c

        # Problem14-2 : 사전 뒤부터 방문
#        chap14/Problem14-2/DLinkedList.h
#        chap14/Problem14-2/DLinkedList.c
#        chap14/Problem14-2/ArrayBaseStack.h
#        chap14/Problem14-2/ArrayBaseStack.c
#        chap14/Problem14-2/ALGraphDFS.h
#        chap14/Problem14-2/ALGraphDFS.c
#        chap14/Problem14-2/DFSMain.c

        # BFS : 너비 우선 탐색
#        chap14/ALGraphBFS/DLinkedList.h
#        chap14/ALGraphBFS/DLinkedList.c
#        chap14/ALGraphBFS/CircularQueue.h
#        chap14/ALGraphBFS/CircularQueue.c
#        chap14/ALGraphBFS/ALGraphBFS.h
#        chap14/ALGraphBFS/ALGraphBFS.c
#        chap14/ALGraphBFS/BFSMain.c

        # KruskalAlgorithms : 최소 비용 신장 트리
#        chap14/KruskalAlgorithms/ALEdge.h
#        chap14/KruskalAlgorithms/DLinkedList.h
#        chap14/KruskalAlgorithms/DLinkedList.c
#        chap14/KruskalAlgorithms/UsefulHeap.h
#        chap14/KruskalAlgorithms/UsefulHeap.c
#        chap14/KruskalAlgorithms/PriorityQueue.h
#        chap14/KruskalAlgorithms/PriorityQueue.c
#        chap14/KruskalAlgorithms/ArrayBaseStack.h
#        chap14/KruskalAlgorithms/ArrayBaseStack.c
#        chap14/KruskalAlgorithms/ALGraphKruskal.h
#        chap14/KruskalAlgorithms/ALGraphKruskal.c
#        chap14/KruskalAlgorithms/KruskalMain.c






        # ========================================== BOJ ================================================
        # -------------------chap08-------------------
        # 2164 : 카드2 카드 넣다 뺐다 마지막장 (성공)
#        BOJ/chap07/2164/CircularQueue.h
#        BOJ/chap07/2164/CircularQueue.c
#        BOJ/chap07/2164/CircularQueueMain.c
#        BOJ/chap07/2164/2164_package.c


        # -------------------chap08-------------------
        # 1991 : 트리 순회 (트리 만들기부터)
#        BOJ/chap08/1991/BinaryTree2.h
#        BOJ/chap08/1991/BinaryTree2.c
#        BOJ/chap08/1991/1991_package.c
#        BOJ/chap08/1991/1991.c

        # 2263 : 트리 순회 (과제 6)
#        BOJ/chap08/2263/2263.c


        # -------------------chap09-------------------
        # 1966 프린터 큐 : 중요도를 판단해서 출력 (내 멋대로 변형해서 풀이 완료)
#        BOJ/chap09/1966/UsefulHeap.h
#        BOJ/chap09/1966/UsefulHeap.c
#        BOJ/chap09/1966/PriorityQueue.h
#        BOJ/chap09/1966/PriorityQueue.c
#        BOJ/chap09/1966/1966_package.c

        # 14729 칠무해 : 성적 하위 7명 고르기 (성공)
#        BOJ/chap09/14729/UsefulHeap.h
#        BOJ/chap09/14729/UsefulHeap.c
#        BOJ/chap09/14729/PriorityQueue.h
#        BOJ/chap09/14729/PriorityQueue.c
#        BOJ/chap09/14729/PriorityQueueMain.c






        # -------------------chap10-------------------
        # 2750 수 정렬 (과제)
#        BOJ/chap10/2750.c

        # 11399 : ATM 돈 인출 최소 시간 구하기
#        BOJ/chap10/11399.c

        # 1427 : 소트인사이드 (내림차순)
#        BOJ/chap10/1427.c

        # 1947 : 신입사원
#        BOJ/chap10/1946.c

        # 18870 : 좌표압축
#        BOJ/chap11/18870.c

        # 10814 : 나이순정렬
#        BOJ/chap10/10814/QuickSort.c

        # -------------------chap11-------------------
        # 1920 수 찾기 (해보라고 하심)
#        BOJ/chap11/1920.c

        # 10815 : 숫자 카드 (있는지 없는지)
#        BOJ/chap11/10815/BinaryTree2.h
#        BOJ/chap11/10815/BinaryTree2.c
#        BOJ/chap11/10815/BinarySearchTree.h
#        BOJ/chap11/10815/BinarySearchTree.c
#        BOJ/chap11/10815/BinarySearchTreeMain.c
#        BOJ/chap11/10815/10815_package.c
#        BOJ/chap11/10815/10815_builtIn.c

        # 5639 : 전위 순회 받아서 후위 순회 출력 (문제 변형해서 품)
#        BOJ/chap11/5639/BinaryTree2.h
#        BOJ/chap11/5639/BinaryTree2.c
#        BOJ/chap11/5639/BinarySearchTree.h
#        BOJ/chap11/5639/BinarySearchTree.c
#        BOJ/chap11/5639/BinarySearchTreeMain.c
#        BOJ/chap11/5639/5639_BOJ.c # 백준 제출용

        # 2805 : 나무 자르기
#        BOJ/chap11/2805.c

        # 1654 : 랜선 자르기
#        BOJ/chap11/1654.c

        # 2512 : 예산
#        BOJ/chap11/2512.c


        # -------------------chap14-------------------
        # 1260 : 단순 문제
#        BOJ/chap14/1260/BFS/DLinkedList.h
#        BOJ/chap14/1260/BFS/DLinkedList.c
#        BOJ/chap14/1260/BFS/CircularQueue.h
#        BOJ/chap14/1260/BFS/CircularQueue.c
#        BOJ/chap14/1260/BFS/ALGraphBFS.h
#        BOJ/chap14/1260/BFS/ALGraphBFS.c
#        BOJ/chap14/1260/BFS/BFSMain.c

#        BOJ/chap14/1260/DFS/DLinkedList.h
#        BOJ/chap14/1260/DFS/DLinkedList.c
#        BOJ/chap14/1260/DFS/ArrayBaseStack.h
#        BOJ/chap14/1260/DFS/ArrayBaseStack.c
#        BOJ/chap14/1260/DFS/ALGraphDFS.h
#        BOJ/chap14/1260/DFS/ALGraphDFS.c
#        BOJ/chap14/1260/DFS/DFSMain.c

        # 2606 : 바이러스 (감염된 컴퓨터 수 구하기)
#        BOJ/chap14/2606/BFS/DLinkedList.h
#        BOJ/chap14/2606/BFS/DLinkedList.c
#        BOJ/chap14/2606/BFS/CircularQueue.h
#        BOJ/chap14/2606/BFS/CircularQueue.c
#        BOJ/chap14/2606/BFS/ALGraphBFS.h
#        BOJ/chap14/2606/BFS/ALGraphBFS.c
#        BOJ/chap14/2606/BFS/BFSMain.c
#        BOJ/chap14/2606/BFS/2606_BFS.c

#        BOJ/chap14/2606/DFS/DLinkedList.h
#        BOJ/chap14/2606/DFS/DLinkedList.c
#        BOJ/chap14/2606/DFS/ArrayBaseStack.h
#        BOJ/chap14/2606/DFS/ArrayBaseStack.c
#        BOJ/chap14/2606/DFS/ALGraphDFS.h
#        BOJ/chap14/2606/DFS/ALGraphDFS.c
#        BOJ/chap14/2606/DFS/DFSMain.c
#        BOJ/chap14/2606/DFS/2606_DFS.c

        # 11724 : 연결 요소 개수 (시간초과 나긴 하는데 구현은 함)
#        BOJ/chap14/11724/BFS/DLinkedList.h
#        BOJ/chap14/11724/BFS/DLinkedList.c
#        BOJ/chap14/11724/BFS/CircularQueue.h
#        BOJ/chap14/11724/BFS/CircularQueue.c
#        BOJ/chap14/11724/BFS/ALGraphBFS.h
#        BOJ/chap14/11724/BFS/ALGraphBFS.c
#        BOJ/chap14/11724/BFS/BFSMain.c
#        BOJ/chap14/11724/BFS/11724_BFS.c

#        BOJ/chap14/11724/DFS/DLinkedList.h
#        BOJ/chap14/11724/DFS/DLinkedList.c
#        BOJ/chap14/11724/DFS/ArrayBaseStack.h
#        BOJ/chap14/11724/DFS/ArrayBaseStack.c
#        BOJ/chap14/11724/DFS/ALGraphDFS.h
#        BOJ/chap14/11724/DFS/ALGraphDFS.c
#        BOJ/chap14/11724/DFS/DFSMain.c
#        BOJ/chap14/11724/DFS/11724_DFS.c

        # 10451 : 순열 사이클
#        BOJ/chap14/10451/BFS/DLinkedList.h
#        BOJ/chap14/10451/BFS/DLinkedList.c
#        BOJ/chap14/10451/BFS/CircularQueue.h
#        BOJ/chap14/10451/BFS/CircularQueue.c
#        BOJ/chap14/10451/BFS/ALGraphBFS.h
#        BOJ/chap14/10451/BFS/ALGraphBFS.c
#        BOJ/chap14/10451/BFS/BFSMain.c
#        BOJ/chap14/10451/BFS/10451_BFS.c

#        BOJ/chap14/10451/DFS/DLinkedList.h
#        BOJ/chap14/10451/DFS/DLinkedList.c
#        BOJ/chap14/10451/DFS/ArrayBaseStack.h
#        BOJ/chap14/10451/DFS/ArrayBaseStack.c
#        BOJ/chap14/10451/DFS/ALGraphDFS.h
#        BOJ/chap14/10451/DFS/ALGraphDFS.c
#        BOJ/chap14/10451/DFS/DFSMain.c
#        BOJ/chap14/10451/DFS/10451_DFS.c


        # 1197 : 최소 스패닝 트리
#        BOJ/chap14/1197/DLinkedList.h
#        BOJ/chap14/1197/DLinkedList.c
#        BOJ/chap14/1197/ArrayBaseStack.h
#        BOJ/chap14/1197/ArrayBaseStack.c
#        BOJ/chap14/1197/UsefulHeap.h
#        BOJ/chap14/1197/UsefulHeap.c
#        BOJ/chap14/1197/PriorityQueue.h
#        BOJ/chap14/1197/PriorityQueue.c
#        BOJ/chap14/1197/ALGraphKruskal.h
#        BOJ/chap14/1197/ALGraphKruskal.c
#        BOJ/chap14/1197/ALEdge.h
#        BOJ/chap14/1197/KruskalMain.c

        # 1197 : 최소 스패닝 트리
#        BOJ/chap14/13023/DLinkedList.h
#        BOJ/chap14/13023/DLinkedList.c
#        BOJ/chap14/13023/ArrayBaseStack.h
#        BOJ/chap14/13023/ArrayBaseStack.c
#        BOJ/chap14/13023/ALGraphDFS.h
#        BOJ/chap14/13023/ALGraphDFS.c
#        BOJ/chap14/13023/DFSMain.c


        )
