#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque *pdeq) {
    pdeq->head = NULL;
    pdeq->tail = NULL; // 초기화
}

int DQIsEmpty(Deque *pdeq) {
    if(pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque *pdeq, Data data) {
    Node *newNode =(Node * )malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL; // node 하나 만들고 prev = NULL 로 초기화 (head 에 넣으니까)

    newNode->next = pdeq->head; // 추가되는 노드의 다음 노드는 원래 head 가 가리키는 노드

    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode; // 만약 지금 넣는 데이터가 처음이라면, tail도 이걸 가리킴
    else
        pdeq->head->prev = newNode; // 아니라면, 원래 head가 가리키던 노드의 prev가 방금 추가한 노드로 갱신됨

    pdeq->head = newNode; // head 옮기기
}

void DQAddLast(Deque *pdeq, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // node 하나 만들고 next = NULL 로 초기화 (tail 에 넣으니까)

    newNode->prev = pdeq->tail; // 새로 추가되는 노드의 prev는 원래 tail이 가리키던 노드

    if(DQIsEmpty(pdeq))
        pdeq->head = newNode; // 만약 추가되는 노드가 처음이라면 head도 이걸 가리킴
    else
        pdeq->tail->next = newNode; // 아니라면 기존의 tail의 next가 추가하는 노드가 됨

    pdeq->tail = newNode; // tail 옮기긱
}

Data DQRemoveFirst(Deque *pdeq) {
    Node *delNode;
    Data retData; //

    if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    delNode = pdeq->head;
    retData = pdeq->head->data;

    pdeq->head = pdeq->head->next; // head 옆칸으로 옮김

    free(delNode);

    if(pdeq->head == NULL)
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;

    return retData;
}

Data DQRemoveLast(Deque *pdeq) {
    Node *delNode;
    Data retData;

    if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    delNode = pdeq->tail;
    retData = pdeq->tail->data;

    pdeq->tail = pdeq->tail->prev;

    free(delNode);

    if(pdeq->tail == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;

    return retData;
}

Data DQPeekFirst(Deque *pdeq) {
    if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    return pdeq->head->data;
}

Data DQPeekLast(Deque *pdeq) {
    if(DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    return pdeq->tail->data;
}