cmake_minimum_required(VERSION 3.21)
project(Cpractice C)

set(CMAKE_C_STANDARD 99)

add_executable(Cpractice book/chap06/InfixCalculator/InfixCalculator.h book/chap06/InfixCalculator/InfixCalculator.c book/chap06/InfixCalculator/InfixToPostfix.h book/chap06/InfixCalculator/InfixToPostfix.c book/chap06/InfixCalculator/PostCalculator.h book/chap06/InfixCalculator/PostCalculator.c book/chap06/InfixCalculator/ListBaseStack.h book/chap06/InfixCalculator/ListBaseStack.c book/chap06/InfixCalculator/InfixCalculatorMain.c)
