#include <stdio.h>
#include <string.h>
#include "ListBaseStack.h"

#define MAX 60

int main() {
    int T ,flag;
    char input[MAX];
    Stack stack;


    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        flag = 1;
        StackInit(&stack);
        scanf("%s", input);
        for (int j=0; j<strlen(input); j++) {
            if (input[j]=='(')
                SPush(&stack, '(');
            else {
                if (SIsEmpty(&stack)) {
                    flag = 0;
                    break;
                }
                SPop(&stack);
            }
        }
        if (flag==0)
            printf("NO\n");
        else {
            if (SIsEmpty(&stack))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}