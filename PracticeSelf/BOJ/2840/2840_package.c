#include <stdio.h>

#include "DBCLinkedList.h"

void MakeList(List *plist, int N) {
    for (int i=0; i<N; i++){
        LInsert(plist, '?');
    }
}

int main() {
    List list;
    int N, K, spin, flag, charCur;
    char charList[25];

    char data, input;
    ListInit(&list);

    flag=TRUE;
    scanf("%d %d", &N, &K);
    MakeList(&list,N);



    LFirst(&list, &data); // cur ÃÊ±âÈ­

    for (int i=0; i<K; i++) {
        scanf("%d %c", &spin, &input);
        for (int j=0; j<spin; j++) {
            LNext(&list, &data);
        }
        if (data=='?' || data==input)
            LUpdate(&list, input);
        else {
            flag=0;
        }


    }

    charCur = 0;
    if (flag==1) {
        for(int i = 0; i < LCount(&list); i++) {
            if (LPrev(&list, &data)) {
                if (data!='?') {
                    for (int j = 0; j < charCur; j++) {
                        if (charList[j] == data)
                            flag = 0;
                    }
                    charList[charCur] = data;
                    charCur++;
                }

            }
        }
    }




    if (flag==1) {
        LNext(&list, &data);
        for(int i = 0; i < LCount(&list); i++) {
            if(LPrev(&list, &data))
                printf("%c", data);
        }
    }
    else
        printf("!");

    return 0;
}