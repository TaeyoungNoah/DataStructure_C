#include <stdio.h>

int main() {
    int a, d, n, i;
    double result;

    scanf("%d %d %d", &a, &d, &n);

    result = a;
    for (i=1; i<n; i++) {
        result *= d;
    }

    printf("%.0lf", result);
    return 0;
}