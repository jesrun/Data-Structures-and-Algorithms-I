#include <iostream>
#include "BSTree.h"

using namespace std;

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    Empty();
}

// Inserts the account in the binary search tree.
bool BSTree::Insert(Account *client) {
    if (client->getID() < 1000 || client->getID() > 9999) {
        cerr << "ERROR: Invalid account ID." << endl;
        return false;
    }

    if (root == nullptr) {
        root = new Node;
        root->pAcct = client;
        return true;
    } else {
        Node *current = root;
        InsertHelper(client, current);
        return true;
    }
}

BSTree::Node *BSTree::InsertHelper(Account *client, BSTree::Node *current) {
    if (current == nullptr) {
        Node *insertNode = new Node;
        insertNode->pAcct = client;
        insertNode->left = nullptr;
        insertNode->right = nullptr;
        current = insertNode;
        return current;
    } else {
        // If the client ID is less than the current Node ID, search through the left side of the BSTree.
        if (client->getID() < current->pAcct->getID()) {
            current->left = InsertHelper(client, current->left);
        } else if (client->getID() == current->pAcct->getID()) {
            // If the client ID is equal to the current Node ID, return (cannot insert).
            cerr << "ERROR: Account " << client->getID() << " is already open. Transaction refused." << endl;
        } else {
            // If the client ID is greater than the current Node ID, search through the right side of BSTree.
            current->right = InsertHelper(client, current->right);
        }
    }
    return current;
}

// Returns true if the account exists in the binary search tree.
bool BSTree::Retrieve(const int &ID, Account *&accountPtr) const {
    Node *current = root;
    while (current != nullptr) {
        if (ID == current->pAcct->getID()) {
            accountPtr = current->pAcct;
            return true;
        } else if (ID < current->pAcct->getID()) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    accountPtr = nullptr;
    return false;
}

// Prints the binary search tree.
void BSTree::Display() const {
    if (root == nullptr) {
        cerr << "ERROR: Empty client account list." << endl;
    } else {
        DisplayHelper(root);
    }
}

void BSTree::DisplayHelper(BSTree::Node *current) const {
    if (current == nullptr) {
        return;
    }
    DisplayHelper(current->left);
    cout << *(current->pAcct) << endl;
    DisplayHelper(current->right);
}

// Empties the binary search tree.
void BSTree::Empty() {
    if (root == nullptr) {
        return;
    }
    EmptyHelper(root);
}

void BSTree::EmptyHelper(BSTree::Node *current) {
    if (current != nullptr) {
        EmptyHelper(current->left);
        EmptyHelper(current->right);
        delete current->pAcct;
        delete current;
        current = nullptr;
    }
}

// Removes a node from the binary search tree.
void BSTree::Remove(const int &ID) {
    if (isEmpty()) {
        return;
    }

    Node *current = root;
    Node *parent = nullptr;
    while ((current != nullptr)) {
        if (ID < current->pAcct->getID()) {
            parent = current;
            current = current->left;
        } else if(ID > current->pAcct->getID()){
            parent = current;
            current = current->right;
        } else {
            break; // Current points to the element in the tree.
        }
    }

    // Returns if element is not in the tree.
    if (current == nullptr) {
        return;
    }

    // Case 1: If the node have 2 children
    if ((current->left != nullptr) && (current->right != nullptr)) {

        // Takes the smallest value of the right subtree.
        Node *temp = Minimum(current->right);
        Account *value = temp->pAcct;
        current->pAcct = value;
        delete temp->pAcct;
        delete temp;
        temp = nullptr;
        return;

    // Case 2: If the node does not have any children
    } else if ((current->left == nullptr) && (current->right == nullptr)) {
        if (current == root) {
            root = nullptr;
            delete current->pAcct;
            delete current;
            current = nullptr;
            return;
        }
        if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current->pAcct;
        delete current;
        current = nullptr;
        return;

    // Case 3: If the node only has 1 child
    } else {
        Node *child;
        if (current->left != nullptr) {
            child = current->left;
        } else {
            child = current->right;
        }

        if (current != root) {
            if (current == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
        delete current->pAcct;
        delete current;
        current = nullptr;
    }
}

// Returns true if the binary search tree is empty.
bool BSTree::isEmpty() const {
    return root == nullptr;
}

// Returns the node with the smallest value in the tree.
BSTree::Node *BSTree::Minimum(BSTree::Node *current) {
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}