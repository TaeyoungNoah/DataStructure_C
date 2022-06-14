#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int PriorityComp(HData data1, HData data2);
// data1 이 data2 보다 우선순위 높으면 양수
// 우선순위 같으면 0
// data2 의 우선순위가 높다면 음수

typedef struct _heap {
    PriorityComp *comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif