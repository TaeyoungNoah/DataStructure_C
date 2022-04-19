#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

#define MAX 100005

int main() {
    Stack stack;
    StackInit(&stack);

    int n, result_count, num_count, input_count, flag;
    int input[MAX];
    char result[MAX * 2];
    result_count = 0;
    num_count = 1;
    input_count = 0;
    flag = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    while (flag==1) {
        if (num_count < input[input_count]) {
            SPush(&stack, num_count);
            result[result_count] = '+';
            result_count++;
            num_count++;
        }
        else if (num_count ==  input[input_count]) {
            result[result_count] = '+';
            result_count++;
            result[result_count] = '-';
            result_count++;
            num_count++;
            input_count++;
        }
        else {
            while (!SIsEmpty(&stack)) {
                if (SPeek(&stack) == input[input_count]) {
                    SPop(&stack);
                    result[result_count] = '-';
                    result_count++;
                    input_count++;
                }
                else if (SPeek(&stack) > input[input_count]) {
                    flag = 0;
                    break;
                }
                else
                    break;

            }
        }
        if (input_count==n)
            break;
    }

    if (flag == 1) {
        for (int i = 0; i < strlen(result); i++) {
            printf("%c\n", result[i]);
        }
    } else
        printf("NO");


    return 0;
}