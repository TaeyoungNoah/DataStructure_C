#include <stdio.h>

int main() {
    int n, input, i, min;

    min=24;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &input);
        if (input < min)
            min = input;
    }

    printf("%d", min);


    return 0;
}