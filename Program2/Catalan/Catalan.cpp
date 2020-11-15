// Name: Jessica Runandy
// Date: October 22, 2019
// Program 2 : Catalan (Recursion)
// Description: This program calculates the nth Catalan number and prints it.


#include <iostream>
#include <stdlib.h>
using namespace std;

int Catalan(int numberInput);

int main(int argc, char* argv[]) {
    int number = 0;
    if (argc != 2) {
        cerr << "Error, there must be 2 arguments.";
        return -1;
    }
    number = atoi(argv[1]);
    cout << Catalan(number + 1) << endl;
    return 0;
}

// Calculates and returns the Catalan number using a number inputted by the user.
int Catalan(int numberInput) {
    int result = 0;
    if (numberInput < 0) {
        cout << "Error, number must be a natural number" << endl;
    }
    if ((numberInput == 0) || (numberInput == 1)) {
        return 1;
    }
    for (int i = 1; i < numberInput; i++) {
            result += Catalan(i) * Catalan(numberInput - i);
    }
    return result;
}