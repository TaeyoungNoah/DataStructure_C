cmake_minimum_required(VERSION 3.21)
project(PracticeSelf C)

set(CMAKE_C_STANDARD 99)

add_executable(PracticeSelf
#        main.c
        # ======================== chap03 ==========================
        # ArrayList
#        chapter03/ArrayList/ArrayList.c
#        chapter03/ArrayList/ArrayList.h
#        chapter03/ArrayList/ListMain.c


        # ArrayList Point
#        chapter03/ArrayListPoint/ArrayList.h
#        chapter03/ArrayListPoint/ArrayList.c
#        chapter03/ArrayListPoint/Point.h
#        chapter03/ArrayListPoint/Point.c
#        chapter03/ArrayListPoint/PointListMain.c

        # ArrayList NameCard
#        chapter03/ArrayList_NameCard/ArrayList.h
#        chapter03/ArrayList_NameCard/ArrayList.c
#        chapter03/ArrayList_NameCard/NameCard.h
#        chapter03/ArrayList_NameCard/NameCardMain.c
#        chapter03/ArrayList_NameCard/NameCard.c


        # ======================== chap04 ==========================
        # 더미 연결 리스트
#        chapter04/DLinkedList/DLinkedList.h
#        chapter04/DLinkedList/DLinkedList.c
#        chapter04/DLinkedList/DLinkedListMain.c

        # 더미 연결 리스트 sort
#        chapter04/DLinkedListSort/DLinkedList.h
#        chapter04/DLinkedListSort/DLinkedList.c
#        chapter04/DLinkedListSort/DLinkedListSortMain.c


        # Problem 04-1 꼬리에 노드 추가하기
#        chapter04/LinkedRead/LinkedRead.c

        # Problem 04-1 머리에 노드 추가하기
#        chapter04/Problem04-1/LinkedRead.c

        # Problem 04-2 더미노드
#        chapter04/Problem04-2/LinkedRead.c

        # Problem 04-3 point에 연결리스트 적용
#        chapter04/Problem04-3/DLinkedList.h
#        chapter04/Problem04-3/DLinkedList.c
#        chapter04/Problem04-3/Point.h
#        chapter04/Problem04-3/Point.c
#        chapter04/Problem04-3/PointListMain.c

        # Problem 04-3 point에 연결리스트 적용
#        chapter04/Problem04-4/DLinkedList.h
#        chapter04/Problem04-4/DLinkedList.c
#        chapter04/Problem04-4/Point.h
#        chapter04/Problem04-4/Point.c
#        chapter04/Problem04-4/PointListMain.c
        # ======================== chap05 ==========================

        # 원형연결리스트
#        chapter05/CLinkedList/CLinkedList.c
#        chapter05/CLinkedList/CLinkedList.h
#        chapter05/CLinkedList/CLinkedListMain.c

        # Problem 05-1 사원 당직문제
#        chapter05/Problem05-1/CLinkedList.h
#        chapter05/Problem05-1/CLinkedList.c
#        chapter05/Problem05-1/Employee.h
#        chapter05/Problem05-1/EmployeeMain.c

        # Problem 05-1 사원 당직문제 인풋받아서 해보기
#        chapter05/Problem05-1_self/CLinkedList.h
#        chapter05/Problem05-1_self/CLinkedList.c
#        chapter05/Problem05-1_self/Employee.h
#        chapter05/Problem05-1_self/EmployeeMain.c

        # 양방향연결리스트
#        chapter05/DBLinkedList/DBLinkedList.h
#        chapter05/DBLinkedList/DBLinkedList.c
#        chapter05/DBLinkedList/DBLinkedListMain.c

        # Problem 05-2 더미 양방향연결리스트
#        chapter05/Problem05-2/DBDLinkedList.h
#        chapter05/Problem05-2/DBDLinkedList.c
#        chapter05/Problem05-2/DBDLinkedListMain.c

        # ======================== chap06 ========================
        # 배열 기반 스택
#        chapter06/ArrayBaseStack/ArrayBaseStack.h
#        chapter06/ArrayBaseStack/ArrayBaseStack.c
#        chapter06/ArrayBaseStack/ArrayBaseStackMain.c

        # 연결리스트 기반 스택
#        chapter06/ListBaseStack/ListBaseStack.h
#        chapter06/ListBaseStack/ListBaseStack.c
#        chapter06/ListBaseStack/ListBaseStackMain.c

        # Problem 06-1_CLL 원형연결리스트 기반 스택
#        chapter06/Problem06-1_CLL/CLinkedList.h
#        chapter06/Problem06-1_CLL/CLinkedList.c
#        chapter06/Problem06-1_CLL/CLLBaseStack.h
#        chapter06/Problem06-1_CLL/CLLBaseStack.c
#        chapter06/Problem06-1_CLL/CLLBaseStackMain.c

        # Problem 06-1_DB 양방향연결리스트 기반 스택
#        chapter06/Problem06-1_DB/DBLinkedList.h
#        chapter06/Problem06-1_DB/DBLinkedList.c
#        chapter06/Problem06-1_DB/DBLBaseStack.h
#        chapter06/Problem06-1_DB/DBLBaseStack.c
#        chapter06/Problem06-1_DB/DBLBaseStackMain.c

        # InfixToPostfix : 후위표기식 만들기
#        chapter06/InfixToPostfix/ListBaseStack.h
#        chapter06/InfixToPostfix/ListBaseStack.c
#        chapter06/InfixToPostfix/InfixToPostfix.h
#        chapter06/InfixToPostfix/InfixToPostfix.c
#        chapter06/InfixToPostfix/InfixToPostfixMain.c

        # PostCalculator : 후위 표기식 계산하기
#        chapter06/PostCalculator/ListBaseStack.h
#        chapter06/PostCalculator/ListBaseStack.c
#        chapter06/PostCalculator/PostCalculator.h
#        chapter06/PostCalculator/PostCalculator.c
#        chapter06/PostCalculator/PostCalculatorMain.c

        # InfixCalculator
#        chapter06/InfixToPostfix/ListBaseStack.h
#        chapter06/InfixToPostfix/ListBaseStack.c
#        chapter06/InfixToPostfix/PostCalculator.h
#        chapter06/InfixToPostfix/PostCalculator.c
#        chapter06/InfixToPostfix/InfixToPostfix.h
#        chapter06/InfixToPostfix/InfixToPostfix.c
#        chapter06/InfixToPostfix/InfixCalculator.h
#        chapter06/InfixToPostfix/InfixCalculator.c
#        chapter06/InfixToPostfix/InfixCalculatorMain.c

        # ======================== SelfMade ========================
        # 원형양방향 연결 리스트
#        SelfMade/DBCLinkedList/DBCLinkedList.h
#        SelfMade/DBCLinkedList/DBCLinkedList.c
#        SelfMade/DBCLinkedList/DBCLinkedListMain.c

        # 양방향 연결 리스트 정렬
#        SelfMade/DBLinkedListSort/DBLinkedList.h
#        SelfMade/DBLinkedListSort/DBLinkedList.c
#        SelfMade/DBLinkedListSort/DBLinkedListSort.c

        # 양방향 연결리스트 과제 변형
#        SelfMade/DBLinkedListSortNameCard/DBLinkedList.h
#        SelfMade/DBLinkedListSortNameCard/DBLinkedList.c
#        SelfMade/DBLinkedListSortNameCard/NameCard.h
#        SelfMade/DBLinkedListSortNameCard/NameCard.c
#        SelfMade/DBLinkedListSortNameCard/DBNameCardSortMain.c

        # 풍선터트리기 다시풀기
#        SelfMade/Balloon_again/DBCLinkedList.h
#        SelfMade/Balloon_again/DBCLinkedList.c
#        SelfMade/Balloon_again/Balloon.h
#        SelfMade/Balloon_again/Balloon.c
#        SelfMade/Balloon_again/BalloonMain.c

#        SelfMade/Balloon_again/2346_again.c

        # NumFlip : 숫자뒤집기
#        SelfMade/NumFlip/ListBaseStack.h
#        SelfMade/NumFlip/ListBaseStack.c
#        SelfMade/NumFlip/NumFlipMain.c

        # CharFlip : 문자열 뒤집기
#        SelfMade/CharFlip/ListBaseStack.h
#        SelfMade/CharFlip/ListBaseStack.c
#        SelfMade/CharFlip/CharFlipMain.c



        # ======================== BOJ ========================
        # 1158 요세푸스
#        BOJ/1158/CLinkedList.h
#        BOJ/1158/CLinkedList.c
#        BOJ/1158/1158_pakage.c
#        BOJ/HW5/1158.c

        # 9012 괄호문제
#        BOJ/9012/ListBaseStack.h
#        BOJ/9012/ListBaseStack.c
#        BOJ/9012/9012_package.c
#        BOJ/9012/9012.c

        # 10773 제로 : 회식비 계산
#        BOJ/10773/ListBaseStack.h
#        BOJ/10773/ListBaseStack.c
#        BOJ/10773/10773_package.c
#        BOJ/10773/10773.c

        # 1874 스택스열 : + -
#        BOJ/1874/ListBaseStack.h
#        BOJ/1874/ListBaseStack.c
#        BOJ/1874/1874_package.c
#        BOJ/1874/1874.c

        # 2940 : 돌려돌려 돌림판 원형 양방향 리스트는 썼는데 반례 구현 못함
#        BOJ/2840/DBCLinkedList.h
#        BOJ/2840/DBCLinkedList.c
#        BOJ/2840/2840_package.c
#        BOJ/2840/2840.c

        # 1406 : 에디터 커서 옮기기
#        BOJ/1406/ListBaseStack.h
#        BOJ/1406/ListBaseStack.c
#        BOJ/1406/1406_package.c
#        BOJ/1406/1406.c

        # 1935 : 후위표기식 2 ABCD 머시기 해서 숫자 받아서 하는거
#        BOJ/1935/ListBaseStack.h
#        BOJ/1935/ListBaseStack.c
#        BOJ/1935/1935_package.c
#        BOJ/1935/1935.c

#        BOJ/1935_again/ListBaseStack.h
#        BOJ/1935_again/ListBaseStack.c
#        BOJ/1935_again/1935_again_package.c
#        BOJ/1935_again/1935_again.c

        # 17298 : 오큰수
#        BOJ/17298/ListBaseStack.h
#        BOJ/17298/ListBaseStack.c
#        BOJ/17298/17298_package.c
        BOJ/17298/17298.c

        # 10799 : 괄호 레이저
#        BOJ/10799/ListBaseStack.h
#        BOJ/10799/ListBaseStack.c
#        BOJ/10799/10799_package.c
#        BOJ/10799/10799.c

        # 2346 : 풍선 터뜨리기
#        BOJ/2346/DBCLinkedList.h
#        BOJ/2346/DBCLinkedList.c
#        BOJ/2346/Balloon.h
#        BOJ/2346/Balloon.c
#        BOJ/2346/2346_package.c
#        BOJ/2346/2346.c'

        # 5397 : 키로거 비밀번호 입력
#        BOJ/5397/ListBaseStack.h
#        BOJ/5397/ListBaseStack.c
#        BOJ/5397/5497_package.c
#        BOJ/5397/5497.c

        # 3986 : 좋은단어 고르기
#        BOJ/3986/ListBaseStack.h
#        BOJ/3986/ListBaseStack.c
#        BOJ/3986/3986_package.c
#        BOJ/3986/3986.c

        # 11899 : 괄호 끼워넣기 괄호중에 멀쩡한거 개수 세기
#        BOJ/11899/ListBaseStack.h
#        BOJ/11899/ListBaseStack.c
#        BOJ/11899/11899_package.c
#        BOJ/11899/11899.c

        # 17608 : 막대기 보기 (순서대로 쌓고 보이는 막대기)
#        BOJ/17608/ListBaseStack.h
#        BOJ/17608/ListBaseStack.c
#        BOJ/17608/17608_package.c
#        BOJ/17608/17608.c

        # 4949 : 균형잡힌 세상 괄호랑 문자열 다나오는거 입력받는거 애매하면 이거 봐
#        BOJ/4949/ListBaseStack.h
#        BOJ/4949/ListBaseStack.c
#        BOJ/4949/4949_package.c
#        BOJ/4949/4949.c

#        BOJ/1918/1918_package.c

        # 2605 : 학생 줄세우기 새치기문제
#        BOJ/2605/ListBaseStack.h
#        BOJ/2605/ListBaseStack.c
#        BOJ/2605/2605_package.c
#        BOJ/2605/2605.c


        # ======================== HW ========================
        # HW2
#        HW/HW2/ArrayList.h
#        HW/HW2/ArrayList.c
#        HW/HW2/ListMainChar.c

        # HW3

        # HW4
#        HW/HW4/DLinkedList.c
#        HW/HW4/DLinkedList.h
#        HW/HW4/NameCard.c
#        HW/HW4/NameCard.h
#        HW/HW4/NameCardMain.c

        # 메뉴조회까지
#        HW/HW4_again/DLinkedList.h
#        HW/HW4_again/DLinkedList.c
#        HW/HW4_again/NameCard.h
#        HW/HW4_again/NameCard.c
#        HW/HW4_again/NameCardMain.c

        # HW5
#        HW/HW5/CLinkedList.h
#        HW/HW5/CLinkedList.c
#        HW/HW5/HW5_package.c
        )

