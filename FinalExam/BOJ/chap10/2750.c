#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1001

void Swap(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}


int Partition(int arr[], int left, int right) {
    int pivot = arr[left];    // 가장 왼쪽을 피벗
    int low = left+1;
    int high = right;

    while(low <= high) {    // 교차되지 않을 때까지 반복
        while(pivot >= arr[low] && low <= right) // 피벗보다 큰 값을 찾을 때 까지 & 경계 검사
            low++;

        while(pivot <= arr[high] && high >= (left+1)) // 피벗보다 작은 값을 찾을 때 까지 & 경계 검사
            high--;

        if(low <= high)    // 교차되지 않은 상태라면
            Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
    }

    Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
    return high;    // 옮겨진 피벗의 인덱스 반환
}

void QuickSort(int arr[], int left, int right) {
    if(left <= right) {
        int pivot = Partition(arr, left, right);    // 좌 우 나누기 위한 피벗
        QuickSort(arr, left, pivot-1);    // 피벗 좌측
        QuickSort(arr, pivot+1, right);    // 피벗 우측
    }
}


int main() {
    int N;
    int numArr[MAX];

    scanf("%d", &N); // 총 데이터의 개수
    for (int i=0; i<N; i++) {
        scanf("%d", &numArr[i]);
    }

    QuickSort(numArr, 0, N-1);

    for(int i = 0; i < N; i++)
        printf("%d\n", numArr[i]);

    return 0;
}