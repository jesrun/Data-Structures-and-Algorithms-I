// Bank class
#ifndef PROGRAM_BANK_H
#define PROGRAM_BANK_H

#include <iostream>
#include <queue>
#include "Account.h"
#include "Fund.h"
#include "Transaction.h"
#include "BSTree.h"
using namespace std;

class Bank {
public:
    Bank();
    ~Bank();
    bool BuildQueue(string fileName);
    void DisplayHistory();
    void ReadQueue();

private:
    queue<Transaction> transactionQueue;
    BSTree binarySearchTree;
};


#endif
// anything that dynamically allocates memory (new), copy constructor & assignment overload: BSTree, Bank. if dont do new, dont need bank copy and assignment
