#include <stdio.h>

int main() {

    double numbers[5];
    double *ptr = numbers;

    scanf("%lf %lf %lf %lf %lf", ptr, (ptr+1), (ptr+2), (ptr+3), (ptr+4));
    printf("%.1lf %.1lf %.1lf %.1lf %.1lf", *ptr, *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4));
    return 0;
}
