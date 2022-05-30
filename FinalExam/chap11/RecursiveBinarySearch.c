#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target) {
    int mid;

    if(first > last)
        return -1;

    mid = (first + last) / 2;

    if(target == ar[mid]) // mid 에 있으면 return
        return mid;
    else if(target < ar[mid])
        return BSearchRecur(ar, first, mid - 1, target); // 타겟이 mid 에 있는 데이터 보다 작으면 mid 왼쪽
    else
        return BSearchRecur(ar, mid + 1, last, target); // // 타겟이 mid 에 있는 데이터 보다 크면 mid 오른쪽
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 7);
    if(idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스 : %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 10);
    if(idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스 : %d\n", idx);

    return 0;
}