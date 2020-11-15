// Name: Jessica Runandy
// Date: November 7, 2019
// Program 3: Linked Lists
// Description: The Child class compares names alphabetically by last name,
// first name, then age. A child is considered a duplicate if all three fields
// (firstName, lastName, id) are equivalent.

#include <iostream>
using namespace std;

#ifndef LIST342_CHILD_H
#define LIST342_CHILD_H


class Child {
public:
    Child();
    Child(string firstName, string lastName, int age);
    string getFirstName() const;
    string getLastName() const;
    int getAge() const;

    friend istream& operator>>(istream &inStream, Child &other);
    friend ostream& operator<<(ostream &outStream, const Child &other);

    Child& operator=(const Child & source);

    bool operator==(const Child &other) const;
    bool operator!=(const Child &other) const;

    bool operator<(const Child &other) const;
    bool operator>(const Child &other) const;

    bool operator<=(const Child &other) const;
    bool operator>=(const Child &other) const;

private:
    string firstName;
    string lastName;
    int age;
};


#endif //LIST342_CHILD_H
