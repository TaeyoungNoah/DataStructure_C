#include <stdio.h>

int main() {
    int a, d, n, i, result;

    scanf("%d %d %d", &a, &d, &n);

    result = a;
    for (i=1; i<n; i++) {
        result += d;
    }

    printf("%d", result);
    return 0;
}