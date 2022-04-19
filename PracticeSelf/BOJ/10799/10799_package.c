#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

#define MAX 100000

int main() {
    Stack stack;
    StackInit(&stack);
    int flag, result;
    char input[MAX];
    scanf("%s", input);
    flag = 0; // 앞에 (면 0, )면 1
    result = 0;

    for (int i=0; i<strlen(input); i++) {
        if (input[i]=='(') {
            SPush(&stack, '(');
            flag = 0;
        }
        else {
            if (flag==0) {
                SPop(&stack);
                result+= LCount(&stack);
                flag=1;
            }
            else {
                SPop(&stack);
                result+=1;
                flag=1;
            }
        }
    }
    printf("%d", result);
    return 0;
}