#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NameCard.h"


NameCard *MakeNameCard(char *name, char *phone) {
    NameCard *pNamecard = (NameCard *) malloc(sizeof(NameCard));
    stpcpy(pNamecard->name, name);
    stpcpy(pNamecard->phone, phone);
    return pNamecard;
}

void ShowNameCardInfo(NameCard *pcard) {
    printf("[name : %s / phone : %s]\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard *pcard, char *name) {
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone) {
    stpcpy(pcard->phone, phone);
}
