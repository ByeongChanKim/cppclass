#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Account.h"

HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int rate, int special)
    : NormalAccount(ID, money, name, rate), specialRate(special){}
void HighCreditAccount::Deposit(int money){
    NormalAccount::Deposit(money);
    Account::Deposit(money*(specialRate/100.0));
}