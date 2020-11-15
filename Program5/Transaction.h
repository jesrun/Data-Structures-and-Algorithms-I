// Name: Jessica Runandy
// Date: December 5, 2019
// Program 5: The Jolly Banker
// Description: Transaction class keeps track of the different transactions (open,
// deposit, withdraw, transfer, display history).


#ifndef PROGRAM_TRANSACTION_H
#define PROGRAM_TRANSACTION_H

#include <iostream>
using namespace std;

class Transaction {
    friend ostream& operator<<(ostream &outStream, const Transaction &other);
public:
    Transaction();
    ~Transaction();

    // Process open account.
    Transaction(char type, string firstName, string lastName, int ID);

    // Process deposit and withdraw.
    Transaction(char type, int ID, int fundType, int balance);

    // Failed withdraw transactions.
    Transaction(char type, int ID, int fundType, int balance, string fail);

    // Process transfer.
    Transaction(char type, int ID, int fundType, int balance, int account2ID, int account2FundType);

    // Failed transfer transactions.
    Transaction(char type, int ID, int fundType, int balance, int account2ID, int account2FundType, string fail);

    // Process history.
    Transaction(char type, int ID, int fundType);
    Transaction(char type, int ID);

    char getType() const;
    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    int getBalance() const;
    int getFundType() const;
    int getAccount2ID() const;
    int getAccount2FundType() const;
    string getFailedTransaction() const;

private:
    int ID;
    int balance;
    int fundType;
    char type;
    string firstName;
    string lastName;
    int account2ID;
    int account2FundType;
    string failedTransaction; // Failed transactions will have " (Failed) " next to the transaction information.
};

#endif
