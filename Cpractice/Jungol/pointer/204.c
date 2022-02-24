#include <stdio.h>
#include <stdlib.h>

int findMax(int * ptr, int size) {
    int max, i;
    max = *ptr;
    for (i=1; i<size; i++) {
        if (*(ptr+i)>max) {
            max = *(ptr+i);
        }
    }
    return max;
}

int findMin(int * ptr, int size) {
    int min, i;
    min = *ptr;
    for (i=1; i<size; i++) {
        if (*(ptr+i)<min) {
            min = *(ptr+i);
        }
    }
    return min;
}

int main() {
    int num, i;
    scanf("%d", &num);
    int *numbers = (int *) malloc(sizeof(int) * num);

    for (i = 0; i < num; i++) {
        scanf("%d", numbers + i);
    }

    printf("max : %d\n", findMax(numbers, num));
    printf("min : %d\n", findMin(numbers, num));

    return 0;
}