#include <stdio.h>

struct student {
    char school[20];
    int grade;
};

int main(void) {
    struct student student1 = {"Jejuelementary", 6};
    struct student student2;

    scanf("%s %d", student2.school, &student2.grade);

    printf("%d grade in %s School\n",  student1.grade, student1.school);
    printf("%d grade in %s School\n", student2.grade, student2.school);

    return 0;
}