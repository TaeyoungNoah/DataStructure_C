#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

int main() {
    // 기본 세팅
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
    int readData;

    // 데이터 입력 받기
    while (1) {
        printf("자연수 입력 : ");
        scanf("%d", &readData);
        if (readData < 1)
            break;

        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if (tail == NULL) {
            tail = newNode;
        }
        else {
            newNode->next = head;
        }
        head = newNode;
    }

    // 데이터 출력
    printf("== 전체 출력 ==\n");
    if (head == NULL) {
        printf("출력 할 데이터 없음");
    }
    else {
        cur = head;
        printf("%d\n", cur->data);

        while (cur->next != NULL) {
            cur = cur->next;
            printf("%d\n", cur->data);
        }
    }

    // 데이터 삭제
    printf("== 전체 삭제 ==\n");
    if (head == NULL) {
        return 0;
    }
    else {
        Node *delNode = head;
        Node *delNextNode = delNode->next;

        printf("%d 를 삭제합니다.\n", delNode->data);
        free(delNode);

        while (delNextNode != NULL) {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d 를 삭제합니다.\n", delNode->data);
            free(delNode);
        }
    }
    return 0;
}
