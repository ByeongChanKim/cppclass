#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include <iostream>
using namespace std;

void AccountHandler::ShowMenu() const{
    cout << "---Menu---" << endl;
    cout << "1. MakeAccount" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Show Account Infomation" << endl;
    cout << "5. End this program" << endl;
}
void AccountHandler::MakeAccount(){
    int select;
    cout << "choose Account Type" << endl;
    cout << "1. NormalAccount 2.CreditAccount : ";
    cin >> select;

    if(select==NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
    
}

void AccountHandler::MakeNormalAccount(){
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout << "[Make NormalAccount]" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Name : "; cin >> name;
    cout << "Amount of Deposit : "; cin >> balance;
    cout << "InterRate : "; cin >> interRate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(){
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout << "[Make NormalAccount]" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Name : "; cin >> name;
    cout << "Amount of Deposit : "; cin >> balance;
    cout << "InterRate : "; cin >> interRate;
    cout << "CreditLevel(1toA, 2toB, 3toC) : "; cin >> creditLevel;
    cout << endl;

    switch(creditLevel){
        case 1:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
            break;
        case 2:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
            break;
        case 3:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
    }
}

void AccountHandler::DepositMoney(){
    int money;
    int id;
    cout << "[DEPOSIT]" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Amount of Deposit : "; cin >> money;

    for(int i=0; i<accNum; i++){
        if(accArr[i]->getAccID()==id){
            accArr[i]->Deposit(money);
            cout << "Deposit Completed" << endl;
            return;
        }
    }
    cout << "Invalid ID" << endl << endl;
}

void AccountHandler::WithdrawMoney(){
    int money;
    int id;
    cout << "WITHDRAW" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Amount of Withdraw : "; cin >> money;

    for(int i=0; i<accNum; i++){
        if(accArr[i]->getAccID()==id){
            if(accArr[i]->Withdraw(money)==0){
                cout << "Not enough your Balance" << endl << endl;
                return;
            }
            cout << "Withdraw Completed" << endl << endl;
            return;
        }
    }
    cout << "Invalid ID" << endl << endl;
}

AccountHandler::AccountHandler() : accNum(0){}

void AccountHandler::ShowAllAccInfo() const{
    for(int i=0; i<accNum; i++){
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}
AccountHandler::~AccountHandler(){
    for(int i=0; i<accNum; i++)
        delete accArr[i];
}