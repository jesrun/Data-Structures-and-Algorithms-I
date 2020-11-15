// Name: Jessica Runandy
// Date: December 5, 2019
// Program 5: The Jolly Banker
// Description: Account class keeps track of the account information and undergoes the
// transactions of depositing, withdrawing, and the transfer of funds.


#ifndef PROGRAM_ACCOUNT_H
#define PROGRAM_ACCOUNT_H

#include "Transaction.h"
#include "Fund.h"

#include <iostream>
using namespace std;


class Account {
    friend ostream& operator<<(ostream &outStream, const Account &other);
public:
    Account();
    Account(string firstName, string lastName, int ID);

    void InitializeFundNames();

    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    int getFundBalance(int FundNumber) const;
    string getFundType(int fundNumber) const;

    void setFirstName(string first);
    void setLastName(string last);
    void setID(int identification);

    bool operator>(const Account &other) const;
    bool operator>=(const Account &other) const;
    bool operator<(const Account &other) const;
    bool operator<=(const Account &other) const;
    bool operator==(const Account &other) const;
    bool operator!=(const Account &other) const;

    void Deposit(int amount, int fundNumber);
    bool Withdraw(int amount, int fundNumber, char fund);
    bool WithdrawLinkedEven(int amount, int fundNumber, char fund);
    bool WithdrawLinkedOdd(int amount, int fundNumber, char fund);
    void Transfer(int amount, int fundNumber, Account *& other, int fundType, char fund);

    void RecordHistory(int fundNumber, Transaction client);
    void PrintFundHistory(int fundNumber) const;
    void PrintAccountHistory() const;

private:
    string firstName;
    string lastName;
    int ID;
    Fund funds[10]; // Stores the 10 types of funds.
};

#endif
