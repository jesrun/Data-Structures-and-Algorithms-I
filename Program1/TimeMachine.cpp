// Name: Jessica Runandy
// Date: October 9, 2019
// Program 1: TimeSpan (Operator Overloads)
// Description: Testing code for the TimeSpan class.


#include <iostream>
#include "TimeSpan.h"
using namespace std;

int main() {
    int waitVar;
    TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
    TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
    cout << dur1 << endl;
    cout << dur2 << endl;
    cout << dur3 << endl;
    cout << dur4 << endl;
    cout << dur5 << endl;
    cout << dur6 << endl;
    cout << dur7 << endl;

    dur7 += dur3;
    cout << dur3 << endl;
    cout << dur7 << endl;

    if (dur3 != dur6) {
        cout << "Durations are different." << endl;
    } else {
        cout << "Durations are the same" << endl;
    }

    cout << "\n" << endl;
    cout << "My Testing Code: " << endl;

    TimeSpan dur9(1.5, 4, -11), dur9A(-1.5, -4.5, -11.5);
    cout << "Duration number 9 is " << dur9 << endl;
    cout << "Duration number 9A is " << dur9 << endl;

    TimeSpan dur10(1, 1, 1), dur11(1, 1, 1);
    if (dur10 == dur11) {
        cout << "Duration number 10 is the same as Duration number 11." << endl;
    } else {
        cout << "Duration number 10 and number 11 is different." << endl;
    }

    TimeSpan dur23(1.23456, 2.34567, 3.45678), dur24(1.23456, 2.34567, 3.45678);
    if (dur23 == dur24) {
        cout << "Duration number 23 is the same as Duration number 24." << endl;
    } else {
        cout << "Duration number 23 and number 24 is different." << endl;
    }

    TimeSpan dur25(10.6789, -4), dur26(10.6789, -4);
    if (dur25 == dur26) {
        cout << "Duration number 25 is the same as Duration number 26." << endl;
    } else {
        cout << "Duration number 25 and number 26 is different." << endl;
    }

    TimeSpan dur27( -4.56789), dur28(-4.56789);
    if (dur27 == dur28) {
        cout << "Duration number 27 is the same as Duration number 28." << endl;
    } else {
        cout << "Duration number 27 and number 28 is different." << endl;
    }

    TimeSpan dur12(1, 2, 3);
    if (dur10 != dur12) {
       cout << "Duration number 10 and number 12 is different." << endl;
    } else {
        cout << "Duration number 10 and 12 are the same" << endl;
    }

    if (dur12 != dur25) {
        cout << "Duration number 12 and number 25 is different." << endl;
    } else {
        cout << "Duration number 12 and 25 are the same" << endl;
    }

    if (dur25 != dur23) {
        cout << "Duration number 25 and number 23 is different." << endl;
    } else {
        cout << "Duration number 25 and 23 are the same" << endl;
    }

    TimeSpan dur29(6.2), dur30(5.6), dur31(1.5, 3.5), dur32(-2, 8);
    TimeSpan dur15 = dur11 + dur12;
    cout << "Duration number 15 is " << dur15 << endl;
    cout << "Duration 9 + Duration 10 is " << (dur9 + dur10) << endl;
    cout << "Duration 29 + Duration 30 is " << (dur29 + dur30) << endl;
    cout << "Duration 31 + Duration 32 is " << (dur31 + dur32) << endl;

    TimeSpan dur16 = dur11 - dur12;
    cout << "Duration number 16 is " << dur16 << endl;
    cout << "Duration 9 - Duration 10 is " << (dur9 - dur10) << endl;
    cout << "Duration 29 - Duration 30 is " << (dur29 - dur30) << endl;
    cout << "Duration 31 - Duration 32 is " << (dur31 - dur32) << endl;


    dur10 += dur12;
    cout << "Duration number 10 is " << dur10 << endl;
    cout << "Duration number 12 is " << dur12 << endl;

    dur11 += dur12;
    cout << "Duration number 11 is " << dur10 << endl;
    cout << "Duration number 12 is " << dur12 << endl;

    dur24 += dur12;
    cout << "Duration number 24 is " << dur10 << endl;
    cout << "Duration number 12 is " << dur12 << endl;

    // Check -=
    TimeSpan dur13(2.5, 2.5, 2.5), dur14 (2, 2, 2);
    dur13 -= dur14;
    cout << "Duration number 13 is " << dur13 << endl;
    cout << "Duration number 14 is " << dur14 << endl;

    // Check unary negation
    cout << "Using unary negation for Duration number 29 would be " << -(dur29) << endl;
    cout << "Using unary negation for Duration number 30 would be " << -(dur30) << endl;
    cout << "Using unary negation for Duration number 31 would be " << -(dur31) << endl;
    cout << "Using unary negation for Duration number 32 would be " << -(dur32) << endl;


    TimeSpan dur17, dur18(1.6), dur19(2.8653), dur20(5.5, 6.5), dur21(-1.2, -4);
    TimeSpan dur22(-1, -2.567, -3.5);
    cout << "Duration 17 is " << dur17 << endl;
    cout << "Duration 18 is " << dur18 << endl;
    cout << "Duration 19 is " << dur19 << endl;
    cout << "Duration 20 is " << dur20 << endl;
    cout << "Duration 21 is " << dur21 << endl;
    cout << "Duration 22 is " << dur22 << endl;

    cout << "Duration 17 hours is " << dur17.getHours() << endl;
    cout << "Duration 17 minutes is " << dur17.getMinutes() << endl;
    cout << "Duration 17 seconds is " << dur17.getSeconds() << endl;

    cout << "Duration 18 hours is " << dur18.getHours() << endl;
    cout << "Duration 18 minutes is " << dur18.getMinutes() << endl;
    cout << "Duration 18 seconds is " << dur18.getSeconds() << endl;

    cout << "Duration 19 hours is " << dur19.getHours() << endl;
    cout << "Duration 19 minutes is " << dur19.getMinutes() << endl;
    cout << "Duration 19 seconds is " << dur19.getSeconds() << endl;

    cout << "Duration 20 hours is " << dur20.getHours() << endl;
    cout << "Duration 20 minutes is " << dur20.getMinutes() << endl;
    cout << "Duration 20 seconds is " << dur20.getSeconds() << endl;

    cout << "Duration 21 hours is " << dur21.getHours() << endl;
    cout << "Duration 21 minutes is " << dur21.getMinutes() << endl;
    cout << "Duration 21 seconds is " << dur21.getSeconds() << endl;

    cout << "Duration 22 hours is " << dur22.getHours() << endl;
    cout << "Duration 22 minutes is " << dur22.getMinutes() << endl;
    cout << "Duration 22 seconds is " << dur22.getSeconds() << endl;

    TimeSpan dur33, dur34, dur35, dur36;
    cout <<  dur33.setTime(1, 3, 5) << endl;
    cout <<  dur34.setTime(2, 3, -5) << endl;
    cout <<  dur35.setTime(-10, -8, -6) << endl;
    cout <<  dur36.setTime(-12, 13, 58) << endl;

}