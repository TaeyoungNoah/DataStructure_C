#include <stdio.h>

struct point {
    int x;
    int y;
};

float average(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

int main() {
    struct point point1;
    struct point point2;
    struct point point3;

    scanf("%d %d %d %d %d %d", &point1.x, &point1.y, &point2.x, &point2.y, &point3.x, &point3.y);

    printf("(%.1f, %.1f)", average(point1.x, point2.x, point3.x), average(point1.y, point2.y, point3.y));
}
