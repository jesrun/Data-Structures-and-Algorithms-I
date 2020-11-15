// Name: Jessica Runandy
// Date: December 5, 2019
// Program 5: The Jolly Banker
// Description: Account class keeps track of the account information and undergoes the
// transactions of depositing, withdrawing, and the transfer of funds.


#include "Account.h"
#include <array>

Account::Account() {
}

Account::Account(string firstName, string lastName, int ID) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->ID = ID;

    InitializeFundNames();
}

// Initializes fund types.
void Account::InitializeFundNames() {
    string fundTypes[] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund",
                          "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund",
                          "Value Stock Index"};
    for (int i = 0; i < 10; i++) {
        funds[i].setName(fundTypes[i]);
    }
}

ostream &operator<<(ostream &outStream, const Account &other) {
    outStream << other.getFirstName() << " " << other.getLastName() << " Account ID: " << other.getID() << endl;
    for (int i = 0; i < 10; i++) {
        outStream << "\t" << other.getFundType(i) << ": $" << other.getFundBalance(i) << endl;
    }
    return outStream;
}

string Account::getFirstName() const {
    return firstName;
}

string Account::getLastName() const {
    return lastName;
}

int Account::getID() const {
    return ID;
}

int Account::getFundBalance(int fundNumber) const {
    return funds[fundNumber].getBalance();
}

string Account::getFundType(int fundNumber) const {
    return funds[fundNumber].getName();
}

void Account::setFirstName(string first) {
    firstName = first;
}

void Account::setLastName(string last) {
    lastName = last;
}

void Account::setID(int identification) {
    ID = identification;
}

void Account::PrintFundHistory(int fundNumber) const {
    cout << "Transaction History for " << getFirstName() << " " << getLastName() << " " <<
            getFundType(fundNumber) << ": $" << getFundBalance(fundNumber) << endl;
    funds[fundNumber].PrintSpecificFundHistory();
}

void Account::PrintAccountHistory() const {
    cout << "Transaction History for " << getFirstName() << " " << getLastName() << " by fund." << endl;
    for (int i = 0; i < 10; i++) {
        funds[i].PrintHistory();
    }
    cout << endl;
}

bool Account::operator>(const Account &other) const {
    return ID > other.ID;
}

bool Account::operator>=(const Account &other) const {
    return ID >= other.ID;
}

bool Account::operator<(const Account &other) const {
    return ID < other.ID;
}

bool Account::operator<=(const Account &other) const {
    return ID <= other.ID;
}

bool Account::operator==(const Account &other) const {
    return ID == other.ID;
}

bool Account::operator!=(const Account &other) const {
    return ID != other.ID;
}

void Account::Deposit(int amount, int fundNumber) {
    funds[fundNumber].DepositFund(amount);
}

void Account::RecordHistory(int fundNumber, Transaction client) {
    funds[fundNumber].RecordHistory(client);
}

// Checks if the fund is linked, and withdraws the amount if there is enough money in the fund.
// Returns true if there is enough money to withdraw.
bool Account::Withdraw(int amount, int fundNumber, char fund) {
    if (fundNumber == 0 || fundNumber == 2) {
        bool withdraw = WithdrawLinkedEven(amount, fundNumber, fund);
        return withdraw;
    } else if (fundNumber == 1 || fundNumber == 3) {
        bool withdraw = WithdrawLinkedOdd(amount, fundNumber, fund);
        return withdraw;
    } else {
        if (amount > funds[fundNumber].getBalance()) {
            if (fund == 'T') {
                return false;
            }
            cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName << " " << lastName
                 << " " << funds[fundNumber].getName() << endl;
            Transaction withdrawFail('W', getID(), fundNumber, amount, " (Failed) ");
            funds[fundNumber].RecordHistory(withdrawFail);
            return false;
        } else {
            funds[fundNumber].Withdraw(amount);
            if (fund == 'T') {
                return true;
            }
            Transaction withdraw('W', getID(), fundNumber, amount);
            funds[fundNumber].RecordHistory(withdraw);
            return true;
        }
    }
}

// Withdraw from fund number 0 and 2. (Fund 0 is linked to Fund 1. Fund 2 is linked to Fund 3).
// Returns true if there is enough money in the linked accounts to withdraw.
bool Account::WithdrawLinkedEven(int amount, int fundNumber, char fund) {
    if ((funds[fundNumber].getBalance() + funds[fundNumber + 1].getBalance()) >= amount) {
        if (amount < funds[fundNumber].getBalance())  {
            funds[fundNumber].Withdraw(amount);
            if (fund == 'W') {
                Transaction withdraw1('W', getID(), fundNumber, amount);
                funds[fundNumber].RecordHistory(withdraw1);
            }
        } else {
            int amountWithdraw = -(funds[fundNumber].getBalance() - amount);
            funds[fundNumber + 1].Withdraw(amountWithdraw);
            int fundBalance = funds[fundNumber].getBalance();
            funds[fundNumber].setBalance(0);
            if (fund == 'W') {
                Transaction withdraw2('W', getID(), fundNumber + 1, amountWithdraw);
                funds[fundNumber + 1].RecordHistory(withdraw2);
                Transaction withdraw1('W', getID(), fundNumber, fundBalance);
                funds[fundNumber].RecordHistory(withdraw1);
            }
        }
        if (fund == 'T') {
            return true;
        }
        return true;
    } else {
        if (fund == 'T') {
            return false;
        }
        cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName << " " << lastName
             << " " << funds[fundNumber].getName() << endl;
        Transaction withdrawFail('W', getID(), fundNumber, amount, " (Failed) ");
        funds[fundNumber].RecordHistory(withdrawFail);
        return false;
    }
}

// Withdraw from fund number 1 and 3. (Fund 0 is linked to Fund 1. Fund 2 is linked to Fund 3).
// Returns true if there is enough money in the linked accounts to withdraw.
bool Account::WithdrawLinkedOdd(int amount, int fundNumber, char fund) {
    if ((funds[fundNumber].getBalance() + funds[fundNumber - 1].getBalance()) >= amount) {
        if (amount < funds[fundNumber].getBalance())  {
            funds[fundNumber].Withdraw(amount);
            if (fund == 'W') {
                Transaction withdraw1('W', getID(), fundNumber, amount);
                funds[fundNumber].RecordHistory(withdraw1);
            }
        } else {
            int amountWithdraw = -(funds[fundNumber].getBalance() - amount);
            funds[fundNumber - 1].Withdraw(amountWithdraw);
            int fundBalance = funds[fundNumber].getBalance();
            funds[fundNumber].setBalance(0);
            if (fund == 'W') {
                Transaction withdraw2('W', getID(), fundNumber - 1, amountWithdraw);
                funds[fundNumber + 1].RecordHistory(withdraw2);
                Transaction withdraw1('W', getID(), fundNumber, fundBalance);
                funds[fundNumber].RecordHistory(withdraw1);
            }
        }
        if (fund == 'T') {
            return true;
        }
        return true;
    } else {
        if (fund == 'T') {
            return false;
        }
        cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName << " " << lastName
             << " " << funds[fundNumber].getName() << endl;
        Transaction withdrawFail('W', getID(), fundNumber, amount, " (Failed) ");
        funds[fundNumber].RecordHistory(withdrawFail);
        return false;
    }
}

// Transfers assets between funds (can be funds owned by a single client or transfers between clients).
void Account::Transfer(int amount, int fundNumber, Account *& other, int account2FundType, char fund) {
    bool withdraw = Withdraw(amount, fundNumber, fund);
    if (withdraw) {
        other->funds[account2FundType].DepositFund(amount);
        Transaction transfer('T', ID, fundNumber, amount, other->getID(), account2FundType);
        funds[fundNumber].RecordHistory(transfer);
        funds[account2FundType].RecordHistory(transfer);
    } else {
        cerr << "ERROR: Not enough funds to transfer " << amount << " from " << firstName << " " << lastName
             << " " << funds[fundNumber].getName() << endl;
        Transaction transferFail('T', ID, fundNumber, amount, other->getID(), account2FundType, " (Failed) ");
        funds[fundNumber].RecordHistory(transferFail);
    }
}