// Name: Jessica Runandy
// Date: December 5, 2019
// Program 5: The Jolly Banker
// Description: Bank class reads the transactions from the file to determine, call, and
// keep track of the different transactions that needs to be executed.


#include "Bank.h"
#include "Transaction.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Bank::Bank() {
}

Bank::~Bank() {
}

// Reads the transactions from fileName. The transactions can open accounts, withdraw funds, deposit funds, transfer
// funds, or ask for the transactional history to be printed. Returns false if the file could not be found.
bool Bank::BuildQueue(string fileName) {
    ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open()) {
        string line = "";
        while (!inFile.eof()) {
            getline(inFile, line);
            stringstream ss(line);
            char transactionType;
            ss >> transactionType;
            if (transactionType == 'O') {
                string firstName, lastName;
                int ID;
                ss >> lastName >> firstName >> ID;
                if (firstName == "" || lastName == "") {
                    cerr << "ERROR: First Name and Last Name Is Empty." << endl;
                }
                Transaction client(transactionType, firstName, lastName, ID);
                transactionQueue.push(client);
            } else if (transactionType == 'D' || transactionType == 'W') {
                int ID, amount;
                ss >> ID >> amount;
                int fundType = ID % 10;
                ID = ID / 10;
                Transaction client(transactionType, ID, fundType, amount);
                transactionQueue.push(client);
            } else if (transactionType == 'T') {
                int ID, fundType, amount, account2ID, account2FundType;
                ss >> ID >> amount >> account2ID;

                // Separate the ID from the fundType
                fundType = ID % 10;
                ID = ID / 10;
                account2FundType = account2ID % 10;
                account2ID = account2ID / 10;

                Transaction client(transactionType, ID, fundType, amount, account2ID, account2FundType);
                transactionQueue.push(client);
            } else if (transactionType == 'H') {
                int ID, fundType;
                ss >> ID;

                // If the int includes ID and fundType, divide it into two integers of the ID and fundType.
                if (ID > 9999) {
                    fundType = ID % 10;
                    ID = ID / 10;
                    Transaction client(transactionType, ID, fundType);
                    transactionQueue.push(client);
                } else {
                    Transaction client(transactionType, ID);
                    transactionQueue.push(client);
                }
            } else {
                cerr << "ERROR: Transaction type does not exist." << endl;
            }
        }
        inFile.close();
    } else {
        cerr << "Could not find file: " << fileName << endl;
        return false;
    }
    return true;
}


// Displays history once queue is empty. Prints out all open accounts and balances in those accounts.
void Bank::DisplayHistory() {
    if (transactionQueue.empty()) {
        cout << "Processing Done. Final Balances" << endl;
        binarySearchTree.Display();
    }
}

// Read each transaction in the queue and removes the completed transactions from the queue.
void Bank::ReadQueue() {
    while (!transactionQueue.empty()) {
        char fund = transactionQueue.front().getType();
        if (fund == 'O') {
            string firstName = transactionQueue.front().getFirstName();
            string lastName = transactionQueue.front().getLastName();
            int ID = transactionQueue.front().getID();
            Account *client = new Account(firstName, lastName, ID);
            binarySearchTree.Insert(client);
        } else if (fund == 'D') {
            Account *client = nullptr;

            // Finds the client in the binary search tree.
            if (binarySearchTree.Retrieve(transactionQueue.front().getID(), client)) {
                int balance = transactionQueue.front().getBalance();
                int fundType = transactionQueue.front().getFundType();
                client->Deposit(balance, fundType);
                client->RecordHistory(fundType, transactionQueue.front());
            } else {
                cerr << "ERROR: Account " << client->getID() << " not found. Transaction refused." << endl;
            }
        } else if (fund == 'W') {
            Account *client = nullptr;
            if (binarySearchTree.Retrieve(transactionQueue.front().getID(), client)) {
                client->Withdraw(transactionQueue.front().getBalance(), transactionQueue.front().getFundType(), fund);
            }
        } else if (fund == 'T') {
            Account *client1 = nullptr;
            Account *client2 = nullptr;
            int ID = transactionQueue.front().getID();
            int fundType = transactionQueue.front().getFundType();
            int balance = transactionQueue.front().getBalance();

            int account2ID = transactionQueue.front().getAccount2ID();
            int account2FundType = transactionQueue.front().getAccount2FundType();

            // Check if the account exists in the BSTree.
            bool account1Exists = binarySearchTree.Retrieve(transactionQueue.front().getID(), client1);
            bool account2Exists = binarySearchTree.Retrieve(transactionQueue.front().getAccount2ID(), client2);
            if (account1Exists && account2Exists) {
                client1->Transfer(balance, fundType, client2, account2FundType, fund);
            } else if (!account1Exists) {
                cerr << "ERROR: Account " << ID << " not found. Transferal refused." << endl;
            } else {
                cerr << "ERROR: Account " << account2ID << " not found. Transferal refused." << endl;
            }
        } else if (fund == 'H') {
            int ID = transactionQueue.front().getID();
            int fundType = transactionQueue.front().getFundType();
            Account *client = nullptr;
            if (fundType == -1) {
                if (binarySearchTree.Retrieve(ID, client)) {
                    client->PrintAccountHistory();
                }
            } else {
                if (binarySearchTree.Retrieve(ID, client)) {
                    client->PrintFundHistory(fundType);
                }
            }
        }
        transactionQueue.pop();
    }
}