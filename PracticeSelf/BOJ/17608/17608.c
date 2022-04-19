#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Data;

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
    Stack stack;
    int T, temp, top, result;
    StackInit(&stack);
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        scanf("%d", &temp);
        SPush(&stack, temp);
    }

    result = 1;
    top = SPop(&stack);
    while(!SIsEmpty(&stack)) {
        temp = SPop(&stack);
        if (temp>top) {
            top = temp;
            result+=1;
        }
    }

    printf("%d", result);

    return 0;
}
