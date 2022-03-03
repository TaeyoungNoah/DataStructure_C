#include <stdio.h>

int main() {
    int count, sum, userInput;

    scanf("%d", &userInput);
    sum = 0;
    count = 1;
    while(userInput>sum) {
        sum += count;
        count++;
    }

    printf("%d", sum);
    return 0;
}