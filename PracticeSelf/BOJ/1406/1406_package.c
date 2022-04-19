#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

#define MAX 100000

int main() {
    Stack leftStack;
    Stack rightStack;
    Stack resultLeftStack;
    char userInput[MAX], result[2*MAX], order, temp;
    int M;

    StackInit(&leftStack);
    StackInit(&rightStack);

    scanf("%s", userInput);
    for (int i=0; i<strlen(userInput); i++) {
        SPush(&leftStack, userInput[i]);
    }
    scanf("%d", &M);


    for (int i=0; i<M; i++) {
        scanf(" %c", &order);
        switch (order) {
            case 'L':
                if (!SIsEmpty(&leftStack)) {
                    temp = SPop(&leftStack);
                    SPush(&rightStack,temp);
                }
                break;
            case 'D':
                if (!SIsEmpty(&rightStack)) {
                    temp = SPop(&rightStack);
                    SPush(&leftStack,temp);
                }
                break;
            case 'B':
                if (!SIsEmpty(&leftStack)) {
                    SPop(&leftStack);
                }
                break;
            case 'P':
                scanf(" %c", &temp);
                SPush(&leftStack,temp);
                break;
        }
    }

    while(!SIsEmpty(&leftStack))
        SPush(&resultLeftStack, SPop(&leftStack));

    while(!SIsEmpty(&resultLeftStack))
        printf("%c", SPop(&resultLeftStack));
    while(!SIsEmpty(&rightStack))
        printf("%c", SPop(&rightStack));


    return 0;
}