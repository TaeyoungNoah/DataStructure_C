#ifndef __ADTWALLET_H
#define __ADTWALLET_H

typedef struct _wallet {
    int coin100Num; // 100원짜리 동전 수
    int bill5000Num; // 5,000 원 짜리 지폐 수
} Wallet;

int WalletInit(Wallet * pw); // 지갑 초기화
int TakeOutMoney(Wallet * pw, int coinNum, int billNum); // 돈 꺼내는 연산
void PutMoney(Wallet * pw, int coinNum, int billNum); // 돈 넣는 연산
void CheckRemain(Wallet * pw); // 잔고 확인

#endif
