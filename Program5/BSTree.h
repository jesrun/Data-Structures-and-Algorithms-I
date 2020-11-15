// Class BSTree stores the client accounts.

#ifndef PROGRAM_BSTREE_H
#define PROGRAM_BSTREE_H

#include "Account.h"


class BSTree {
    struct Node;
public:
    BSTree();
    ~BSTree();

    bool Insert(Account *client);
    bool Retrieve(const int & ID, Account * & accountPtr) const;
    void Display() const;
    void Empty();
    void Remove(const int &ID);
    bool isEmpty() const;
    Node* Minimum(Node* current);

private:
    struct Node {
        Account *pAcct = nullptr;
        Node *right = nullptr;
        Node *left = nullptr;
    };
    Node *root;
    Node* InsertHelper(Account *client, Node* current);
    void DisplayHelper(Node* current) const;
    void EmptyHelper(Node* current);
};

#endif
