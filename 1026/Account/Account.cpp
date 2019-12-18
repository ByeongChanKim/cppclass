#include "BankingCommonDecl.h"
#include "Account.h"
#include <string>
#include <iostream>
using namespace std;

Account::Account(int ID, int money, char* name)
    : accID(ID), balance(money){
        cusName = new char[strlen(name)+1];
        strcpy(cusName, name);
}
Account::Account(const Account& account)
    : accID(account.accID), balance(account.balance){
        cusName = new char[strlen(account.cusName+1)];
        strcpy(cusName, account.cusName);
}

int Account::getAccID() const{
    return accID;
}
void Account::Deposit(int money){
    balance+=money;
}
int Account::Withdraw(int money){
    if(balance<money)
        return 0;
    balance-=money;
    return money;
}
void Account::ShowAccInfo() const{
    cout << "Account ID : " << accID << endl;
    cout << "Name : " << cusName << endl;
    cout << "Balance : " << balance << endl;
}
Account::~Account(){
    delete[] cusName;
}