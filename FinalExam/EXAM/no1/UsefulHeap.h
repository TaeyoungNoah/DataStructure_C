#define _CRT_SECURE_NO_WARNINGS
#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__
#define TRUE 1
#define FALSE 0

#define HEAP_LEN 1001

typedef struct _work {
    int date;
    int score;
} Work;

typedef Work *HData;
typedef int PriorityComp(HData data1, HData data2);

typedef struct _heap {
    PriorityComp *comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

Work* makeWork(int date, int score);

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif