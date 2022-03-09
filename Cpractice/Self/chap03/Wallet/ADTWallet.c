#include <stdio.h>

#include "ADTWallet.h"

int WalletInit(Wallet * pw) {
    pw->coin100Num=0;
    pw->bill5000Num=0;
}

int TakeOutMoney(Wallet * pw, int coinNum, int billNum) {
    if (pw->coin100Num-coinNum<0 || pw->bill5000Num-billNum<0) {
        return -1;
    }
    pw->coin100Num-=coinNum;
    pw->bill5000Num-=billNum;
    return (coinNum*100) + (billNum*5000);
}

void PutMoney(Wallet * pw, int coinNum, int billNum) {
    pw->coin100Num += coinNum;
    pw->bill5000Num += billNum;
}

void CheckRemain(Wallet * pw) {
    printf("100원 동전 : %d\n", pw->coin100Num);
    printf("5000원 지폐 : %d\n", pw->bill5000Num);
}