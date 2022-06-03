#include <stdio.h>

#define MAX 1000

void Swap(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}


int Partition(int arr[], int left, int right) {
    int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽!
    int low = left+1;
    int high = right;

    while(low <= high) {    // 교차되지 않을 때까지 반복
        while(pivot >= arr[low] && low <= right)
            low++;

        while(pivot <= arr[high] && high >= (left+1))
            high--;

        if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
            Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
    }

    Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
    return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right) {
    if(left <= right) {
        int pivot = Partition(arr, left, right);    // 둘로 나눠서
        QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
        QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
    }
}


int main(void) {
    int arr[MAX];
    int N, result;

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }


    QuickSort(arr, 0, N - 1);

    result = 0;
    for(int i = 0; i<N; i++) {
        result+=(arr[i]*(N-i));
    }

    printf("%d", result);


    return 0;
}