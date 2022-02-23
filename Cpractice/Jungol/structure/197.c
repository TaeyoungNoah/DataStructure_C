#include <stdio.h>

typedef struct point {
    int x;
    int y;
} point;

struct Rectangle {
    point leftBottom;
    point rightTop;
};

int findMin(int a, int b) {
    if (a>b)
        return b;
    return a;
}

int findMax(int a, int b) {
    if (a>b)
        return a;
    return b;
}

int main() {
    struct Rectangle rectangle1;
    struct Rectangle rectangle2;
    scanf("%d %d %d %d", &rectangle1.leftBottom.x, &rectangle1.leftBottom.y, &rectangle1.rightTop.x, &rectangle1.rightTop.y);
    scanf("%d %d %d %d", &rectangle2.leftBottom.x, &rectangle2.leftBottom.y, &rectangle2.rightTop.x, &rectangle2.rightTop.y);

    struct Rectangle answer;

    answer.leftBottom.x = findMin(rectangle1.leftBottom.x, rectangle2.leftBottom.x);
    answer.leftBottom.y = findMin(rectangle1.leftBottom.y, rectangle2.leftBottom.y);
    answer.rightTop.x = findMax(rectangle1.rightTop.x, rectangle2.rightTop.x);
    answer.rightTop.y = findMax(rectangle1.rightTop.y, rectangle2.rightTop.y);

    printf("%d %d %d %d", answer.leftBottom.x, answer.leftBottom.y, answer.rightTop.x, answer.rightTop.y);

    return 0;
}
