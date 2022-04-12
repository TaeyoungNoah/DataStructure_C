#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NameCard.h"


NameCard *MakeNameCard(char *name, char *phone) {
    NameCard *pNamecard = (NameCard *) malloc(sizeof(NameCard));
    strcpy(pNamecard->name, name);
    strcpy(pNamecard->phone, phone);
    return pNamecard;
}

void ShowNameCardInfo(NameCard *pcard) {
    printf("[name : %s / phone : %s]\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard *pcard, char *name) {
    return strcmp(pcard->name, name); // pcard->name = name
}

void ChangePhoneNum(NameCard *pcard, char *phone) {
    strcpy(pcard->phone, phone); // 두 문자열이 같으면 0 반환
}
