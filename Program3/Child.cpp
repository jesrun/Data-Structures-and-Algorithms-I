// Name: Jessica Runandy
// Date: November 7, 2019
// Program 3: Linked Lists
// Description: The Child class compares names alphabetically by last name,
// first name, then age. A child is considered a duplicate if all three fields
// (firstName, lastName, id) are equivalent.


#include "Child.h"
#include <iostream>


Child::Child() {
    firstName = "";
    lastName = "";
    age = 0;
}

Child::Child(string firstName, string lastName, int age) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
}

string Child::getFirstName() const {
    return firstName;
}

string Child::getLastName() const {
    return lastName;
}

int Child::getAge() const {
    return age;
}

ostream& operator<<(ostream &outStream, const Child &other) {
    outStream << other.firstName << other.lastName << other.age;
    return outStream;
}

istream& operator>>(istream &inStream, Child &other) {
    inStream >> other.firstName >> other.lastName >> other.age;
    return inStream;
}

Child &Child::operator=(const Child &source) {
    if (this == &source) {
        return *this;
    }

    this->firstName = source.firstName;
    this->lastName = source.lastName;
    this->age = source.age;
    return *this;
}

bool Child::operator==(const Child &other) const {
    return ((lastName == other.lastName) && (firstName == other.firstName) && (age == other.age));
}

bool Child::operator!=(const Child &other) const {
    return !(*this == other);
}

bool Child::operator<(const Child &other) const {
    if (lastName < other.lastName) {
        return true;
    } else if ((lastName == other.lastName)) {
        if (firstName < other.firstName) {
            return true;
        } else if (firstName < other.firstName) {
            if (age < other.age) {
                return true;
            }
        }
    }
    return false;
}

bool Child::operator>(const Child &other) const {
    if (lastName > other.lastName) {
        return true;
    } else if ((lastName == other.lastName)) {
        if (firstName == other.firstName) {
            if (age > other.age) {
                return true;
            }
        } else if (firstName < other.firstName) {
            return true;
        }
    }
    return false;
}

bool Child::operator>=(const Child &other) const {
    return!(*this < other);
}

bool Child::operator<=(const Child &other) const {
    return!(*this > other);
}