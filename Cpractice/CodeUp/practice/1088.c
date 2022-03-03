#include <stdio.h>

int main() {
    int i, userInput;

    scanf("%d", &userInput);

    for (i=0; i<=userInput; i++) {
        if (i%3==0) {
            continue;
        }
        printf("%d ", i);
    }
    return 0;
}