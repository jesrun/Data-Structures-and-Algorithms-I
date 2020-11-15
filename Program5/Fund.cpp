#include "Fund.h"
#include <vector>

Fund::Fund() {
    balance = 0;
    fundName = "";
}

Fund::Fund(int balance, string fundName) {
    this->balance = balance;
}

Fund::~Fund() {
}

int Fund::getBalance() const {
    return balance;
}

string Fund::getName() const {
    return fundName;
}

void Fund::setBalance(int amount) {
    balance = amount;
}

void Fund::setName(const string name) {
    this->fundName = name;
}

// Deposits the amount in the specified fund.
void Fund::DepositFund(int amount) {
    balance += amount;
}

// Returns true if the amount that the client wants to withdraw is less than or equal to the amount that they have
// in that fund.
bool Fund::Withdraw(int amount) {
    if (balance < amount) {
        return false;
    }
    balance -= amount;
    return true;
}

// Records the transaction.
void Fund::RecordHistory(Transaction transaction) {
    fundHistory.push_back(transaction);
}

// Prints the history of the fund type.
void Fund::PrintHistory() const {
    if (fundHistory.size() == 0) {
        return;
    }
    cout << getName() << ": $" << getBalance() << endl;
    for (int i = 0; i < fundHistory.size(); i++) {
        cout << "  " << fundHistory[i] << endl;
    }
}

void Fund::PrintSpecificFundHistory() const {
    if (fundHistory.size() == 0) {
        return;
    }
    for (int i = 0; i < fundHistory.size(); i++) {
        cout << "  " << fundHistory[i] << endl;
    }
}
