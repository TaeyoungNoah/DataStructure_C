#include <stdio.h>

struct member {
    char name[100];
    char number[100];
    char address[100];
};

int main() {
    struct member member;
    scanf("%s %s %s", member.name, member.number, member.address);

    printf("name : %s\n", member.name);
    printf("tel : %s\n", member.number);
    printf("addr : %s\n", member.address);

    return 0;
}
