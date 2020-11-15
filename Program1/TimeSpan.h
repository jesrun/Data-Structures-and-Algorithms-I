// Name: Jessica Runandy
// Date: October 9, 2019
// Program 1: TimeSpan (Operator Overloads)
// Description: TimeSpan class represents a duration of time in hours, minutes, and seconds. The number
// of seconds should be between-60 and 60 and the number of minutes should be between -60 and 60.


#include <iostream>
using namespace std;

class TimeSpan {
public:
    TimeSpan();
    TimeSpan(double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double hours, double minutes, double seconds);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool setTime(int hours, int minutes, int seconds);

    TimeSpan operator+(const TimeSpan &time) const;
    TimeSpan operator-(const TimeSpan &time) const;

    TimeSpan operator+=(const TimeSpan &time);
    TimeSpan operator-=(const TimeSpan &time);
    bool operator==(const TimeSpan& time) const;
    bool operator!=(const TimeSpan& time) const;
    TimeSpan operator-() const;

    friend ostream& operator<<(ostream &outStream, const TimeSpan& time);
    friend istream& operator>>(istream &inStream, TimeSpan &time);

private:
    double hours;
    double minutes;
    double seconds;
};
