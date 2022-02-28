#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
    int readData;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    head = newNode;
    tail = newNode;
    // == 데이터 추가 ==
    while(1) {
        printf("자연수 입력 : ");
        scanf("%d", &readData);
        if (readData<1)
            break;

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        tail->next = newNode;

        tail = newNode;
    }

    // == 데이터 조회 ==
    printf("== 전체 데이터 조회 ==\n");
    cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
        printf("%d\n", cur->data);
    }

    // == 데이터 삭제 ==
    printf("== 전체 데이터 삭제 ==\n");
    Node *delNode = head;
    Node *delNextNode = delNode->next;

    while (delNextNode != NULL) {
        delNode = delNextNode;
        delNextNode = delNode->next;

        printf("%d 를 삭제합니다.\n", delNode->data);
        free(delNode);
    }
    return 0;
}