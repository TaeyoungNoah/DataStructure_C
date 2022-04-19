#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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

Data SPeek(Stack *pstack) {
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->head->data;
}


int main() {
    Stack stack;
    char sentence[105], tok;
    int flag;



    while(1) {
        StackInit(&stack);
        flag = 1;

        fgets(sentence, 105, stdin);
        // 이부분에 rewind(stdin);
        //        scanf("%[^\n]", sentence); 적으면 안됨,,  이때는 밑에 조건 "." 이었음
        if (strcmp(sentence, ".\n")==0) {
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
        else {
            if (SIsEmpty(&stack))
                printf("yes\n");
            else
                printf("no\n");
        }


    }


    return 0;
}