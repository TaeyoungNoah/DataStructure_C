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
    int size;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack) {
    pstack->head = NULL;
    pstack->size = 0;
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

    (pstack->size)++;
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
    (pstack->size)--;
    return rdata;
}

int main() {
    Stack resultStack;
    Stack tempStack;

    StackInit(&resultStack);
    StackInit(&tempStack);
    int N, K;

    scanf("%d", &N);

    for(int i=1; i<=N; i++) {
        scanf("%d", &K);
        for (int j=0; j<K; j++) {
            SPush(&tempStack, SPop(&resultStack));
        }
        SPush(&resultStack, i);
        while(!SIsEmpty(&tempStack))
            SPush(&resultStack, SPop(&tempStack));
    }

    while(!SIsEmpty(&resultStack))
        SPush(&tempStack, SPop(&resultStack));

    while(!SIsEmpty(&tempStack))
        printf("%d ", SPop(&tempStack));
    return 0;
}

