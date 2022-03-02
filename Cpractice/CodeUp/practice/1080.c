#include <stdio.h>

int main() {
    int input, sum, count;
    scanf("%d", &input);
    sum = 0;
    count = 1;
    while (sum < input) {
        sum += count;
        count++;
    }
    printf("%d", count - 1);
    return 0;
}