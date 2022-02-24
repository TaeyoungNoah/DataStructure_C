#include <stdio.h>

int main() {
    int size, i, j, temp;

    scanf("%d", &size);

    int numbers[size];
    int *ptr = numbers;

    for (i=0; i<size; i++) {
        scanf("%d", (ptr+i));
    }

    for (i=0; i<size; i++) {
        for (j=i; j<size; j++) {
            if (*(ptr+i)<*(ptr+j)) {
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }

    for (i=0; i<size; i++) {
        printf("%d ", *(ptr+i));
    }

    return 0;
}