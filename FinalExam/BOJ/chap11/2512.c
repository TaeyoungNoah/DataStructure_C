#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, target;
    int *budgetArr;
    long long max, left, right, mid, result, sum;
    scanf("%d", &N);
    budgetArr = (int*) malloc(N* sizeof(int));

    max = 0;
    for (int i = 0; i < N; i++) {
        scanf(" %d", &budgetArr[i]);
        if (max < budgetArr[i])
            max = budgetArr[i];
    }
    left = 1;
    right = max;
    result = 0;
    scanf("%d", &target);
    while (left<=right) {
        mid = (left + right) / 2;
        sum = 0;
        for (int i = 0; i < N; i++) {
            if (mid < budgetArr[i])
                sum += mid;
            else
                sum += budgetArr[i];
        }

        if(sum>target)
            right = mid - 1;
        else {
            if (result < sum)
                result = mid;
            left = mid + 1;
        }
    }
    printf("%lld", result);
    return 0;
}