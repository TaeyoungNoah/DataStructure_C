#include <stdio.h>

struct Person {
    char name[20];
    char schoolName[20];
    int grade;
} Person;

int main() {
    struct Person person;
    scanf("%s %s %d", person.name, person.schoolName, &person.grade);

    printf("Name : %s\n", person.name);
    printf("School : %s\n", person.schoolName);
    printf("Grade : %d\n", person.grade);
}

