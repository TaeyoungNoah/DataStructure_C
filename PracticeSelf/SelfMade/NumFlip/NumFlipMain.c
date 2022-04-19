#include <stdio.h>

#include "ListBaseStack.h"

int main() {
    Stack inputStack;
    Stack resultStack;
    int input, temp;

    StackInit(&inputStack);
    StackInit(&resultStack);

    scanf("%d", &input);

    while (input>0) {
        temp = input%10;
        SPush(&inputStack, temp);
        input/=10;
    }

    while (!SIsEmpty(&inputStack)) {
        SPush(&resultStack, SPop(&inputStack));
    }

    while (!SIsEmpty(&resultStack)) {
        printf("%d", SPop(&resultStack));
    }


    return 0;
}