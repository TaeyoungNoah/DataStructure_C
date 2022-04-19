#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ListBaseStack.h"

#define MAX 1000000

int main() {
    Stack leftStack;
    Stack rightStack;
    int T;
    char tok, temp;
    char input[MAX], result[MAX];



    scanf("%d", &T);

    for (int j=0; j<T; j++) {
        scanf("%s", input);
        StackInit(&leftStack);
        StackInit(&rightStack);
        for (int i=0; i<strlen(input); i++) {
            tok = input[i];
            switch(tok) {
                case '<':
                    if (!SIsEmpty(&leftStack)) {
                        temp = SPop(&leftStack);
                        SPush(&rightStack,temp);
                    }
                    break;
                case '>':
                    if (!SIsEmpty(&rightStack)) {
                        temp = SPop(&rightStack);
                        SPush(&leftStack,temp);
                    }
                    break;
                case '-':
                    if (!SIsEmpty(&leftStack)) {
                        SPop(&leftStack);
                    }
                    break;
                default:
                    SPush(&leftStack, tok);
                    break;
            }
        }
        for (int i = SSize(&leftStack)-1; i>=0; i--) {
            result[i]= SPop(&leftStack);
        }

        for (int i = SSize(&leftStack); i<SSize(&leftStack)+SSize(&rightStack); i++) {
            result[i]= SPop(&rightStack);
        }

        memset(input, 0, sizeof(char) * strlen(input)+ 1);
        printf("%s\n", result);
    }
    return 0;
}