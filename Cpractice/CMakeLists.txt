cmake_minimum_required(VERSION 3.21)
project(Cpractice C)

set(CMAKE_C_STANDARD 99)

add_executable(Cpractice
        Self/chap03/Wallet/ADTWallet.h Self/chap03/Wallet/ADTWallet.c Self/chap03/Wallet/ADTWalletMain.c)
