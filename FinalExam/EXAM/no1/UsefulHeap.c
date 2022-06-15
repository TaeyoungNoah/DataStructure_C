#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "UsefulHeap.h"

Work* makeWork(int date, int score) {
    Work * pWork = (Work*) malloc(sizeof (Work));
    pWork->date = date;
    pWork->score = score;
    return pWork;
}


void HeapInit(Heap *ph, PriorityComp pc) {
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph) {
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx) {
    return idx / 2;
}

int GetLChildIDX(int idx) {
    return idx * 2;
}

int GetRChildIDX(int idx) {
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx) {
    if(GetLChildIDX(idx) > ph->numOfData) // �ڽ� ��尡 ���ٸ�
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData) // �ڽ� ��尡 �ϳ� �� �̶��
        return GetLChildIDX(idx);
    else {
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) > 0) // ���� �ڽ��� �켱������ ���ٸ�
            return GetLChildIDX(idx);
        else // ������ �ڽ��� �켱������ ���ٸ�
            return GetRChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data) {
    int idx = ph->numOfData + 1;

    while(idx != 1) {
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) < 0) // comp(a, b) : a �� b ���� �켱������ ������ ���
            break;
        ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
        idx = GetParentIDX(idx);
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph) {
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while((childIdx = GetHiPriChildIDX(ph, parentIdx))) {
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}