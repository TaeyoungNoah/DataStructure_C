#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard *MakeNameCard(char *name, char *phone) {
    NameCard *nameCard = (NameCard *) malloc(sizeof(NameCard));
    stpcpy(nameCard->name, name);
    stpcpy(nameCard->phone, phone);
    return nameCard;
}

void ShowNameCardInfo(NameCard *pcard) {
    printf("name : %s\n", pcard->name);
    printf("phone : %s\n", pcard->phone);
}

int NameCompare(NameCard *pcard, char *name) {
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone) {
    stpcpy(pcard->phone, phone);
}