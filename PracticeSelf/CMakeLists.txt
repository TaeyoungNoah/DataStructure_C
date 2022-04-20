cmake_minimum_required(VERSION 3.21)
project(PracticeSelf C)

set(CMAKE_C_STANDARD 99)

add_executable(PracticeSelf

        # ================================================ chap03 ==================================================
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


        # ================================================ chap04 ==================================================
        # ���� ���� ����Ʈ
#        chapter04/DLinkedList/DLinkedList.h
#        chapter04/DLinkedList/DLinkedList.c
#        chapter04/DLinkedList/DLinkedListMain.c

        # ���� ���� ����Ʈ sort
#        chapter04/DLinkedListSort/DLinkedList.h
#        chapter04/DLinkedListSort/DLinkedList.c
#        chapter04/DLinkedListSort/DLinkedListSortMain.c


        # Problem 04-1 ������ ��� �߰��ϱ�
#        chapter04/LinkedRead/LinkedRead.c

        # Problem 04-1 �Ӹ��� ��� �߰��ϱ�
#        chapter04/Problem04-1/LinkedRead.c

        # Problem 04-2 ���̳��
#        chapter04/Problem04-2/LinkedRead.c

        # Problem 04-3 point�� ���Ḯ��Ʈ ����
#        chapter04/Problem04-3/DLinkedList.h
#        chapter04/Problem04-3/DLinkedList.c
#        chapter04/Problem04-3/Point.h
#        chapter04/Problem04-3/Point.c
#        chapter04/Problem04-3/PointListMain.c

        # Problem 04-3 point�� ���Ḯ��Ʈ ����
#        chapter04/Problem04-4/DLinkedList.h
#        chapter04/Problem04-4/DLinkedList.c
#        chapter04/Problem04-4/Point.h
#        chapter04/Problem04-4/Point.c
#        chapter04/Problem04-4/PointListMain.c
        # ================================================ chap05 ==================================================

        # �������Ḯ��Ʈ
#        chapter05/CLinkedList/CLinkedList.c
#        chapter05/CLinkedList/CLinkedList.h
#        chapter05/CLinkedList/CLinkedListMain.c

        # Problem 05-1 ��� ��������
#        chapter05/Problem05-1/CLinkedList.h
#        chapter05/Problem05-1/CLinkedList.c
#        chapter05/Problem05-1/Employee.h
#        chapter05/Problem05-1/EmployeeMain.c

        # Problem 05-1 ��� �������� ��ǲ�޾Ƽ� �غ���
#        chapter05/Problem05-1_self/CLinkedList.h
#        chapter05/Problem05-1_self/CLinkedList.c
#        chapter05/Problem05-1_self/Employee.h
#        chapter05/Problem05-1_self/EmployeeMain.c

        # ����⿬�Ḯ��Ʈ
#        chapter05/DBLinkedList/DBLinkedList.h
#        chapter05/DBLinkedList/DBLinkedList.c
#        chapter05/DBLinkedList/DBLinkedListMain.c

        # Problem 05-2 ���� ����⿬�Ḯ��Ʈ
#        chapter05/Problem05-2/DBDLinkedList.h
#        chapter05/Problem05-2/DBDLinkedList.c
#        chapter05/Problem05-2/DBDLinkedListMain.c

        # ================================================ chap06 ================================================
        # �迭 ��� ����
#        chapter06/ArrayBaseStack/ArrayBaseStack.h
#        chapter06/ArrayBaseStack/ArrayBaseStack.c
#        chapter06/ArrayBaseStack/ArrayBaseStackMain.c

        # ���Ḯ��Ʈ ��� ����
#        chapter06/ListBaseStack/ListBaseStack.h
#        chapter06/ListBaseStack/ListBaseStack.c
#        chapter06/ListBaseStack/ListBaseStackMain.c

        # Problem 06-1_CLL �������Ḯ��Ʈ ��� ����
#        chapter06/Problem06-1_CLL/CLinkedList.h
#        chapter06/Problem06-1_CLL/CLinkedList.c
#        chapter06/Problem06-1_CLL/CLLBaseStack.h
#        chapter06/Problem06-1_CLL/CLLBaseStack.c
#        chapter06/Problem06-1_CLL/CLLBaseStackMain.c

        # Problem 06-1_DB ����⿬�Ḯ��Ʈ ��� ����
#        chapter06/Problem06-1_DB/DBLinkedList.h
#        chapter06/Problem06-1_DB/DBLinkedList.c
#        chapter06/Problem06-1_DB/DBLBaseStack.h
#        chapter06/Problem06-1_DB/DBLBaseStack.c
#        chapter06/Problem06-1_DB/DBLBaseStackMain.c

        # InfixToPostfix : ����ǥ��� �����
#        chapter06/InfixToPostfix/ListBaseStack.h
#        chapter06/InfixToPostfix/ListBaseStack.c
#        chapter06/InfixToPostfix/InfixToPostfix.h
#        chapter06/InfixToPostfix/InfixToPostfix.c
#        chapter06/InfixToPostfix/InfixToPostfixMain.c

        # PostCalculator : ���� ǥ��� ����ϱ�
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

        # ================================================ SelfMade ================================================
        # ��������� ���� ����Ʈ
#        SelfMade/DBCLinkedList/DBCLinkedList.h
#        SelfMade/DBCLinkedList/DBCLinkedList.c
#        SelfMade/DBCLinkedList/DBCLinkedListMain.c

        # ����� ���� ����Ʈ ����
#        SelfMade/DBLinkedListSort/DBDLinkedList.h
#        SelfMade/DBLinkedListSort/DBDLinkedList.c
#        SelfMade/DBLinkedListSort/DBLinkedListSort.c

        # ����� ���Ḯ��Ʈ ���� ����
#        SelfMade/DBLinkedListSortNameCard/DBDLinkedList.h
#        SelfMade/DBLinkedListSortNameCard/DBDLinkedList.c
#        SelfMade/DBLinkedListSortNameCard/NameCard.h
#        SelfMade/DBLinkedListSortNameCard/NameCard.c
#        SelfMade/DBLinkedListSortNameCard/DBNameCardSortMain.c

        # ǳ����Ʈ���� �ٽ�Ǯ��
#        SelfMade/Balloon_again/DBCLinkedList.h
#        SelfMade/Balloon_again/DBCLinkedList.c
#        SelfMade/Balloon_again/Balloon.h
#        SelfMade/Balloon_again/Balloon.c
#        SelfMade/Balloon_again/BalloonMain.c

#        SelfMade/Balloon_again/2346_again.c

        # NumFlip : ���ڵ�����
#        SelfMade/NumFlip/ListBaseStack.h
#        SelfMade/NumFlip/ListBaseStack.c
#        SelfMade/NumFlip/NumFlipMain.c

        # CharFlip : ���ڿ� ������
#        SelfMade/CharFlip/ListBaseStack.h
#        SelfMade/CharFlip/ListBaseStack.c
#        SelfMade/CharFlip/CharFlipMain.c

        # ����ǥ��� ������ ������ ����
#        SelfMade/InfixCalcutaor_boj/InfixToPostfix.h
#        SelfMade/InfixCalcutaor_boj/InfixToPostfix.c
#        SelfMade/InfixCalcutaor_boj/ListBaseStack.h
#        SelfMade/InfixCalcutaor_boj/ListBaseStack.c
#        SelfMade/InfixCalcutaor_boj/InFixCalculator_bojMain.c



        # ================================================ BOJ ================================================
        # 1158 �似Ǫ��
#        BOJ/1158/CLinkedList.h
#        BOJ/1158/CLinkedList.c
#        BOJ/1158/1158_pakage.c
#        BOJ/HW5/1158.c

        # 9012 ��ȣ����
#        BOJ/9012/ListBaseStack.h
#        BOJ/9012/ListBaseStack.c
#        BOJ/9012/9012_package.c
#        BOJ/9012/9012.c

        # 10773 ���� : ȸ�ĺ� ���
#        BOJ/10773/ListBaseStack.h
#        BOJ/10773/ListBaseStack.c
#        BOJ/10773/10773_package.c
#        BOJ/10773/10773.c

        # 1874 ���ý��� : + -
#        BOJ/1874/ListBaseStack.h
#        BOJ/1874/ListBaseStack.c
#        BOJ/1874/1874_package.c
#        BOJ/1874/1874.c

        # 2840 : �������� ������ ���� ����� ����Ʈ
#        BOJ/2840/DBCLinkedList.h
#        BOJ/2840/DBCLinkedList.c
#        BOJ/2840/2840_package.c
#        BOJ/2840/2840.c

        # 1406 : ������ Ŀ�� �ű��
#        BOJ/1406/ListBaseStack.h
#        BOJ/1406/ListBaseStack.c
#        BOJ/1406/1406_package.c
#        BOJ/1406/1406.c

        # 1935 : ����ǥ��� 2 ABCD �ӽñ� �ؼ� ���� �޾Ƽ� �ϴ°�
#        BOJ/1935/ListBaseStack.h
#        BOJ/1935/ListBaseStack.c
#        BOJ/1935/1935_package.c
#        BOJ/1935/1935.c

#        BOJ/1935_again/ListBaseStack.h
#        BOJ/1935_again/ListBaseStack.c
#        BOJ/1935_again/1935_again_package.c
#        BOJ/1935_again/1935_again.c

        # 17298 : ��ū��
#        BOJ/17298/ListBaseStack.h
#        BOJ/17298/ListBaseStack.c
#        BOJ/17298/17298_package.c
#        BOJ/17298/17298.c

        # 10799 : ��ȣ ������
#        BOJ/10799/ListBaseStack.h
#        BOJ/10799/ListBaseStack.c
#        BOJ/10799/10799_package.c
#        BOJ/10799/10799.c

        # 2346 : ǳ�� �Ͷ߸���
#        BOJ/2346/DBCLinkedList.h
#        BOJ/2346/DBCLinkedList.c
#        BOJ/2346/Balloon.h
#        BOJ/2346/Balloon.c
#        BOJ/2346/2346_package.c
#        BOJ/2346/2346.c'

        # 5397 : Ű�ΰ� ��й�ȣ �Է�
#        BOJ/5397/ListBaseStack.h
#        BOJ/5397/ListBaseStack.c
#        BOJ/5397/5497_package.c
#        BOJ/5397/5497.c

        # 3986 : �����ܾ� ������
#        BOJ/3986/ListBaseStack.h
#        BOJ/3986/ListBaseStack.c
#        BOJ/3986/3986_package.c
#        BOJ/3986/3986.c

        # 11899 : ��ȣ �����ֱ� ��ȣ�߿� �����Ѱ� ���� ����
#        BOJ/11899/ListBaseStack.h
#        BOJ/11899/ListBaseStack.c
#        BOJ/11899/11899_package.c
#        BOJ/11899/11899.c

        # 17608 : ����� ���� (������� �װ� ���̴� �����)
#        BOJ/17608/ListBaseStack.h
#        BOJ/17608/ListBaseStack.c
#        BOJ/17608/17608_package.c
#        BOJ/17608/17608.c

        # 4949 : �������� ���� ��ȣ�� ���ڿ� �ٳ����°� �Է¹޴°� �ָ��ϸ� �̰� ��
#        BOJ/4949/ListBaseStack.h
#        BOJ/4949/ListBaseStack.c
#        BOJ/4949/4949_package.c
#        BOJ/4949/4949.c

#        BOJ/1918/1918_package.c

        # 2605 : �л� �ټ���� ��ġ�⹮��
#        BOJ/2605/ListBaseStack.h
#        BOJ/2605/ListBaseStack.c
#        BOJ/2605/2605_package.c
#        BOJ/2605/2605.c

        # 2562 : �ִ밪ã��
#        BOJ/2562/DLinkedList.h
#        BOJ/2562/DLinkedList.c
#        BOJ/2562/2562_package.c
#        BOJ/2562/2562.c



        # ================================================ HW ================================================
        # HW2
#        HW/HW2/ArrayList.h
#        HW/HW2/ArrayList.c
#        HW/HW2/ListMainChar.c

        # HW3
#        HW/HW3/ArrayList.h
#        HW/HW3/ArrayList.c
#        HW/HW3/NameCard.h
#        HW/HW3/NameCard.c
#        HW/HW3/NameCardMain.c

        # HW4
#        HW/HW4/DLinkedList.c
#        HW/HW4/DLinkedList.h
#        HW/HW4/NameCard.c
#        HW/HW4/NameCard.h
#        HW/HW4/NameCardMain.c

        # �޴���ȸ����
#        HW/HW4_again/DLinkedList.h
#        HW/HW4_again/DLinkedList.c
#        HW/HW4_again/NameCard.h
#        HW/HW4_again/NameCard.c
#        HW/HW4_again/NameCardMain.c

        # HW5
#        HW/HW5/CLinkedList.h
#        HW/HW5/CLinkedList.c
#        HW/HW5/HW5_package.c


        # ================================================ TEST ================================================
#        SelfMade/TEST/ListBaseStack.h
#        SelfMade/TEST/ListBaseStack.c
#        SelfMade/TEST/TestMain.c
#        SelfMade/TEST/TestBoj.c
        # ================================================ EXAM ================================================





        main.c

        )
