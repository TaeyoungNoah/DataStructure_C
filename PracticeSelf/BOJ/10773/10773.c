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
    StackInit(&stack);

    int K, T, sum;
    scanf("%d", &K);
    sum = 0;

    for (int i=0; i<K; i++) {
        scanf("%d", &T);
        if (T!=0)
            SPush(&stack, T);
        else
            SPop(&stack);
    }

    while(!SIsEmpty(&stack)) {
        sum+= SPop(&stack);
    }

    printf("%d", sum);


    return 0;
}
