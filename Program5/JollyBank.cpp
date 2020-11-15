// Name: Jessica Runandy
// Date: December 5, 2019
// Program 5: The Jolly Banker
// Description: Driver that tests the JollyBank program. Process the transactions
// and displays the history.


#include "Bank.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "ERROR: There must be two arguments." << endl;
        return -1;
    }
    Bank JollyBank;
    JollyBank.BuildQueue(argv[1]);
    JollyBank.ReadQueue();
    cout << endl;
    JollyBank.DisplayHistory();
    return 0;
}