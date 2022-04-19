#ifndef PRACTICESELF_DBLBASESTACK_H
#define PRACTICESELF_DBLBASESTACK_H

#include "DBLinkedList.h"

typedef int Data;

typedef struct _listStack {
    List *plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);


#endif //PRACTICESELF_DBLBASESTACK_H
