#include <stdio.h>
#include <stdlib.h>

int main() {
    int K, N;
    long long mid, sum, result, max, left, right;
    int * cableArr;
    scanf("%d %d", &K, &N);
    cableArr = (int*) malloc(K*sizeof(int));
    max = 0;
    for (int i=0; i<K; i++) {
        scanf("%d", &cableArr[i]);
        if (max < cableArr[i])
            max = cableArr[i];
    }
    left = 1;
    right = max;
    result = 0;
    while(left<=right) {
        mid = (left + right) / 2;
        sum = 0;
        if (mid!=0) {
            for (int i=0; i<K; i++) {
                sum += (cableArr[i]/mid);
            }
        }


        if (sum<N) {
            right = mid-1;
        }
        else {
            if (result < mid)
                result = mid;
            left = mid+1;
        }
    }
    printf("%lld", result);
    return 0;
}