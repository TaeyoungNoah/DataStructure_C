#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 60


typedef char Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack {
    Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack) {
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack) {
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data SPop(Stack *pstack) {
    Data rdata;
    Node *rnode;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    rnode = pstack->head;
    rdata = pstack->head->data;

    pstack->head = pstack->head->next;

    free(rnode);
    return rdata;
}

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