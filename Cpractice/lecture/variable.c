#include <stdio.h>
// variable - 변할 수 있는 어떤 것
// constant - 변할 수 없는 것

#define pi 3.1415 // constant 생성

int main() {
    int age = 25;
    float weight = 58.4;
    char letter_grade = 'a';

    printf("%d\n", age);
    printf("%f.2\n", weight);
    printf("%c\n", letter_grade);
}

