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

    if(GetLChildIDX(idx) > ph->numOfData) // 자식 노드가 없다면
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData) // 자식 노드가 하나 뿐 이라면
        return GetLChildIDX(idx);
    else {
        if(ph->heapArr[GetLChildIDX(idx)].pr < ph->heapArr[GetRChildIDX(idx)].pr) // 왼쪽 자식의 우선순위가 높다면
            return GetLChildIDX(idx);
        else // 오른쪽 자식의 우선순위가 높다면
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
    HData retData = (ph->heapArr[1]).data; // 삭제할 데이터
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드

    int parentIdx = 1; // 맨 마지막 노드가 들어가야할 인덱스 표시
    int childIdx;
    while((childIdx = GetHiPriChildIDX(ph, parentIdx))) { // 자식 노드 존재 : True | 자식 노드 없음 : False | 맨 마지막 노드를 맨 위로 올려서 자리를 찾아가는 로직
        if(lastElem.pr <= ph->heapArr[childIdx].pr) // 올린 마지막 노드의 우선순위가 자식보다 높으면 탈출
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // 자식노드 한단계 올리고
        parentIdx = childIdx; // 마지막 노드 위치 재설정
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;

    return retData;
}