#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100000

typedef char Data;

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
    Stack leftStack;
    Stack rightStack;
    Stack resultLeftStack;
    char userInput[MAX], order, temp;
    int M;

    StackInit(&leftStack);
    StackInit(&rightStack);
    StackInit(&resultLeftStack);

    scanf("%s", userInput);
    for (int i=0; i<strlen(userInput); i++) {
        SPush(&leftStack, userInput[i]);
    }
    scanf("%d", &M);


    for (int i=0; i<M; i++) {
        scanf(" %c", &order);
        switch (order) {
            case 'L':
                if (!SIsEmpty(&leftStack)) {
                    temp = SPop(&leftStack);
                    SPush(&rightStack,temp);
                }
                break;
            case 'D':
                if (!SIsEmpty(&rightStack)) {
                    temp = SPop(&rightStack);
                    SPush(&leftStack,temp);
                }
                break;
            case 'B':
                if (!SIsEmpty(&leftStack)) {
                    SPop(&leftStack);
                }
                break;
            case 'P':
                scanf(" %c", &temp);
                SPush(&leftStack,temp);
                break;
        }
    }

    while(!SIsEmpty(&leftStack))
        SPush(&resultLeftStack, SPop(&leftStack));
    while(!SIsEmpty(&resultLeftStack))
        printf("%c", SPop(&resultLeftStack));
    while(!SIsEmpty(&rightStack))
        printf("%c", SPop(&rightStack));


    return 0;
}