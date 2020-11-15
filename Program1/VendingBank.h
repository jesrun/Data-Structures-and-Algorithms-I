// Name: Jessica Runandy
// Date: October 9, 2019
// Program 1:  The Vending Bank (Class Design)
// Description: Models the coin-operated “bank” part of a Vending machine which sells snacks.


#include <string>
using namespace std;
class VendingBank
{
public:
    VendingBank();
    VendingBank(int id);
    ~VendingBank();
    VendingBank(int quarters, int dime, int penny, int nickels);

    int ReturnChange();
    int GetTotalMoneyInBank();
    int CountMoneyInserted();
    int EmptyBank();
    bool isBankEmpty();
    int PrintAmountInBank();
    int CountNumberOfQuarters();
    int CountNumberOfDime();
    int CountNumberOfPennies();
    int CountNumberOfNickles();
    int CountTotalNumberOfCoins();
    int GetQuarter() const;
    int GetDime() const;
    int GetPenny() const;
    int GetNickle() const;

    VendingBank operator+(const VendingBank &other) const;
    VendingBank operator-(const VendingBank &other) const;
    VendingBank operator+=(const VendingBank &other);
    VendingBank operator-=(const VendingBank &other);
    bool operator==(const VendingBank& other) const;
    bool operator!=(const VendingBank& other) const;
    friend ostream& operator<<(ostream &outStream, const VendingBank& other);
    friend istream& operator>>(istream &inStream, VendingBank &other);

private:
    int kQuarter;
    int kDime;
    int kPenny;
    int kNickle;
    int totalMoneyInBank;
};

