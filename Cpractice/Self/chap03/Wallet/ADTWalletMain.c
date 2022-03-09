#include <stdio.h>
#include <stdlib.h>

#include "ADTWallet.h"

int main() {
    Wallet *myWallet = (Wallet *)malloc(sizeof(Wallet));

    WalletInit(myWallet);
    PutMoney(myWallet, 10, 10);

    CheckRemain(myWallet);

    int money;
    money = TakeOutMoney(myWallet, 5, 5);
    printf("꺼낸 돈 : %d\n", money);

    CheckRemain(myWallet);

    free(myWallet);
    return 0;
}