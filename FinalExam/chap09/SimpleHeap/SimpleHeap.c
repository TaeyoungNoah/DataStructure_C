#include "SimpleHeap.h"

void HeapInit(Heap *ph) {
    ph->numOfData = 0;
}

int HIsEmpty(Heap *ph) {
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx) { // Helper
    return idx / 2;
}

int GetLChildIDX(int idx) { // Helper
    return idx * 2;
}

int GetRChildIDX(int idx) { // Helper
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx) { // Helper

    if(GetLChildIDX(idx) > ph->numOfData) // �ڽ� ��尡 ���ٸ�
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData) // �ڽ� ��尡 �ϳ� �� �̶��
        return GetLChildIDX(idx);
    else {
        if(ph->heapArr[GetLChildIDX(idx)].pr < ph->heapArr[GetRChildIDX(idx)].pr) // ���� �ڽ��� �켱������ ���ٸ�
            return GetLChildIDX(idx);
        else // ������ �ڽ��� �켱������ ���ٸ�
            return GetRChildIDX(idx);
    }
}
void HInsert(Heap *ph, HData data, Priority pr) {
    int idx = ph->numOfData + 1;
    HeapElem nElem = {pr, data};

    while(idx != 1) {
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = nElem;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph) {
    HData retData = (ph->heapArr[1]).data; // ������ ������
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // ���� ������ ���

    int parentIdx = 1; // �� ������ ��尡 ������ �ε��� ǥ��
    int childIdx;
    while((childIdx = GetHiPriChildIDX(ph, parentIdx))) { // �ڽ� ��� ���� : True | �ڽ� ��� ���� : False | �� ������ ��带 �� ���� �÷��� �ڸ��� ã�ư��� ����
        if(lastElem.pr <= ph->heapArr[childIdx].pr) // �ø� ������ ����� �켱������ �ڽĺ��� ������ Ż��
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // �ڽĳ�� �Ѵܰ� �ø���
        parentIdx = childIdx; // ������ ��� ��ġ �缳��
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;

    return retData;
}