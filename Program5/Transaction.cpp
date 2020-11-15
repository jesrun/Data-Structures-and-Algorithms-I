// Name: Jessica Runandy
// Date: December 5, 2019
// Program 5: The Jolly Banker
// Description: Transaction class keeps track of the different transactions (open,
// deposit, withdraw, transfer, display history).


#include "Transaction.h"

Transaction::Transaction() {
    string firstName = "";
    string lastName = "";
    int ID = 0;
    int balance = 0;
    int fundType = 0;
    int account2ID = 0;
    int account2FundType = 0;
    string failedTransaction = "";
}

Transaction::~Transaction() {
}

Transaction::Transaction(char type, string firstName, string lastName, int ID) {
    this->type = type;
    this->firstName = firstName;
    this->lastName = lastName;
    this->ID = ID;
}

Transaction::Transaction(char type, int ID, int fundType, int balance) {
    this->type = type;
    this->ID = ID;
    this->fundType = fundType;
    this->balance = balance;
}

Transaction::Transaction(char type, int ID, int fundType, int balance, int account2ID, int account2FundType) {
    this->type = type;
    this->ID = ID;
    this->fundType = fundType;
    this->balance = balance;
    this->account2ID = account2ID;
    this->account2FundType = account2FundType;
}

Transaction::Transaction(char type, int ID, int fundType) {
    this->type = type;
    this->ID = ID;
    this->fundType = fundType;
}

Transaction::Transaction(char type, int ID) {
    this->type = type;
    this->ID = ID;
    fundType = -1;
}

Transaction::Transaction(char type, int ID, int fundType, int balance, string failedTransaction) {
    this->type = type;
    this->ID = ID;
    this->fundType = fundType;
    this->balance = balance;
    this->failedTransaction = failedTransaction;
}

Transaction::Transaction(char type, int ID, int fundType, int balance, int account2ID, int account2FundType,
                         string failedTransaction) {
    this->type = type;
    this->ID = ID;
    this->fundType = fundType;
    this->balance = balance;
    this->account2ID = account2ID;
    this->account2FundType = account2FundType;
    this->failedTransaction = failedTransaction;
}

char Transaction::getType() const {
    return type;
}

string Transaction::getFirstName() const {
    return firstName;
}

string Transaction::getLastName() const {
    return lastName;
}

int Transaction::getID() const {
    return ID;
}

int Transaction::getBalance() const {
    return balance;
}

int Transaction::getFundType() const {
    return fundType;
}

int Transaction::getAccount2ID() const {
    return account2ID;
}

int Transaction::getAccount2FundType() const {
    return account2FundType;
}

string Transaction::getFailedTransaction() const {
    return failedTransaction;
}

// Overloads the << operator, prints out the transaction history depending on the transaction type.
ostream &operator<<(ostream &outStream, const Transaction &other) {
    if (other.getType() == 'D' || other.getType() == 'W') {
        if (other.getFailedTransaction() == " (Failed) ") {
            outStream << other.getType() << " " << other.getID() << other.getFundType() << " " << other.getBalance() <<
                         other.getFailedTransaction();
        } else {
            outStream << other.getType() << " " << other.getID() << other.getFundType() << " " << other.getBalance();
        }
    } else if (other.getType() == 'T') {
        if (other.getFailedTransaction() == " (Failed) ") {
            outStream << other.getType() << " " << other.getID() << other.getFundType() << " " << other.getBalance() <<
                      " " << other.getAccount2ID() << other.getAccount2FundType() << other.getFailedTransaction();
        } else {
            outStream << other.getType() << " " << other.getID() << other.getFundType() << " " << other.getBalance() <<
                      " " << other.getAccount2ID() << other.getAccount2FundType();
        }
    }
    return outStream;
}