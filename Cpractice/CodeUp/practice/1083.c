#include <stdio.h>

int main() {
    int userInput, i;
    scanf("%d", &userInput);

    for (i = 1; i <= userInput; i++) {
        if (i % 3 == 0)
            printf("X ");
        else
            printf("%d ", i);
    }
    return 0;
}
