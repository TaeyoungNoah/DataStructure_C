#include <stdio.h>

int main() {
    char input;

    while (input != 'q') {
        scanf("%c", &input);
        printf("%c", input);
    }

    return 0;
}