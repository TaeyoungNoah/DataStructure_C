#include <stdio.h>

int main() {
    int i, sum, userInput;
    scanf("%d", &userInput);
    sum = 0;
    for (i = 0; i <= userInput; i += 2) {
        sum += i;
    }

    printf("%d", sum);
    return 0;
}