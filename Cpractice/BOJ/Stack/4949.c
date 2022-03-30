#include <stdio.h>
#include <string.h>

#define MAX 105

typedef struct _stack {
    int top;
    char stack[MAX];
} List;

void ListInit(List *plist) {
    plist->top = -1;
}

void push(List *plist, char data) {
    plist->top++;
    plist->stack[plist->top] = data;
}

char pop(List *plist) {
    char temp = plist->stack[plist->top];
    plist->stack[plist->top] = 0;
    plist->top--;
    return temp;
}

int main() {

    char sentence[MAX];
    int flag=1;

    while (1) {
        List list;
        ListInit(&list);
        fgets(sentence, MAX, stdin);
        if (!strcmp(sentence, ".\n"))
            break;

        for (int i = 0; i < strlen(sentence); i++) {
            if (sentence[i] == '(' || sentence[i] == '[') {
                push(&list, sentence[i]);
            } else if (sentence[i] == ')') {
                char temp = pop(&list);
                if (temp != '(') {
                    flag = 0;
                    break;
                }
            } else if (sentence[i] == ']') {
                char temp = pop(&list);
                if (temp != '[') {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 0)
            printf("no\n");
        else
            if (list.top==-1)
                printf("yes\n");
            else
                printf("no\n");
        flag = 1;
    }
    return 0;
}