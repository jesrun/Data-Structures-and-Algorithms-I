// Fund class keeps track of the 10 different fund types.

#ifndef PROGRAM_FUND_H
#define PROGRAM_FUND_H

#include <iostream>
#include <vector>
#include "Transaction.h"
using namespace std;

class Fund {
public:
    Fund();
    Fund(int balance, string fundName);
    ~Fund();

    int getBalance() const;
    string getName() const;

    void setBalance(int amount);
    void setName(const string name);

    void DepositFund(int amount);
    bool Withdraw(int amount);
    void RecordHistory(Transaction transaction);
    void PrintHistory() const;
    void PrintSpecificFundHistory() const;

private:
    int balance;
    string fundName;
    vector<Transaction> fundHistory;
};

#endif