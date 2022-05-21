#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
    int fIdx = left; // 배열의 앞쪽 영역을 가리킴
    int rIdx = mid + 1; // 배열의 뒤쪽 영역을 가리킴
    int i;

    int *sortArr = (int *)malloc(sizeof(int) * (right + 1));
    int sIdx = left; // 새 배열에 넣을 인덱스

    while(fIdx <= mid && rIdx <= right) {
        if(arr[fIdx] <= arr[rIdx]) // 병합 할 두 영역의 데이터들을 비교하여,
            sortArr[sIdx] = arr[fIdx++]; // 정렬 순서대로 sortArr에 하나씩 옮겨 담는다.
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    if(fIdx > mid) { // 배열의 앞부분이 모두 sortArr에 옮겨졌다면
        for(i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i]; // 배열 뒷부분에 남은 데이터들을 sortArr에 그대로 옮긴다
    }
    else { // 배열의 뒷부분이 모두 sortArr에 옮겨졌다면,
        for(i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i]; // 배열 앞부분에 에은 데이터들을 sortArr에 그대로 옮긴다
    }

    for(i = left; i <= right; i++) {
        arr[i] = sortArr[i];
    }

    free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
    int mid;

    if(left < right) {
        mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void) {
    int arr[] = {3, 2, 7, 1, 4, 6, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int i;
    MergeSort(arr, 0, len - 1);

    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}