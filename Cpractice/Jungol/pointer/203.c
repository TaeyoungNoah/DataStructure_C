# include <stdio.h>

int main() {
    int numbers[10], i;
    int *ptr = numbers;
    int even, odd;
    even = 0;
    odd = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", (ptr + i));
        if (*(ptr + i) % 2 == 1)
            odd += 1;
        else
            even +=1;
    }

    printf("odd : %d\n", odd);
    printf("even : %d\n", even);


    return 0;
}