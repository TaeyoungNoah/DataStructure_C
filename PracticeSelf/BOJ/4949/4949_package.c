#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

int main() {
    Stack stack;
    char sentence[100], tok;
    int flag;



    while(1) {
        StackInit(&stack);
        rewind(stdin);
        flag = 1;
        scanf("%[^\n]", sentence);
        if (strcmp(sentence, ".")==0) {
            break;
        }
        for (int i=0; i<strlen(sentence); i++) {
            tok = sentence[i];
            switch (tok) {
                case '(':
                case '[':
                    SPush(&stack, tok);
                    break;
                case ']':
                    if (SIsEmpty(&stack)) {
                        flag = 0;
                        break;
                    }
                    if (SPeek(&stack)=='[') {
                        SPop(&stack);
                        break;
                    }
                    flag = 0;
                    break;
                case ')':
                    if (SIsEmpty(&stack)) {
                        flag = 0;
                        break;
                    }
                    if (SPeek(&stack)=='(') {
                        SPop(&stack);
                        break;
                    }
                    flag = 0;
                    break;

            }
            if (flag == 0)
                break;
        }
        if (flag == 0)
            printf("no\n");
        else
            printf("yes\n");

    }


    return 0;
}