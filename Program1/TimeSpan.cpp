// Name: Jessica Runandy
// Date: October 9, 2019
// Program 1: TimeSpan (Operator Overloads)
// Description: TimeSpan class represents a duration of time in hours, minutes, and seconds. The number
// of seconds should be between-60 and 60 and the number of minutes should be between -60 and 60.


#include <iostream>
#include <algorithm>
#include "TimeSpan.h"
#include <cmath>
using namespace std;

// Default constructor.
TimeSpan::TimeSpan() : hours(0), minutes(0), seconds(0) {
}

// Constructor with 1 argument to initialize seconds.
TimeSpan::TimeSpan(double seconds) : seconds(seconds) {
}

// Constructor with 2 arguments to initialize minutes and seconds.
TimeSpan::TimeSpan(double minutes, double seconds) : minutes(minutes), seconds(seconds) {
}

// Constructor with 3 arguments to initialize hours, minutes, and seconds.
TimeSpan::TimeSpan(double hours, double minutes, double seconds) : hours(hours), minutes(minutes), seconds(seconds) {
}

int TimeSpan::getHours() const {
    return int (round(hours));
}

int TimeSpan::getMinutes() const {
    return int (round(minutes));
}

int TimeSpan::getSeconds() const {
    return int (round(seconds));
}

// Returns true if successful in setting the number of hours, minutes, seconds.
bool TimeSpan::setTime(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    return true;
}

// Overloads the << operator to print out the duration.
ostream &operator<<(ostream &outStream, const TimeSpan &time) {
    int convertHours, convertMinutes;
    double calculateSeconds;
    convertHours = time.hours * 3600;
    convertMinutes = time.minutes * 60;
    calculateSeconds = convertHours + convertMinutes + time.seconds;
    int newHours = calculateSeconds / 3600;
    int newMinutes = (calculateSeconds - (newHours * 3600)) / 60;
    double newSeconds = fmod(calculateSeconds, 60);
    outStream << "Hours: " << newHours << ", " << "Minutes: " << newMinutes << ", " << "Seconds: "
     << round(newSeconds) << endl;
    return outStream;
}

// Overloads the >> operator.
istream &operator>>(istream &inStream, TimeSpan &time) {
    inStream >> time.hours >> time.minutes >> time.seconds;
    return inStream;
}

// Overloads the == operator to determine if two durations are equal.
bool TimeSpan::operator==(const TimeSpan& time) const {
    return (hours == time.hours) && (minutes == time.minutes) && (seconds == time.seconds);
}

// Overloads the != operator to determine if two durations are not equal.
bool TimeSpan::operator!=(const TimeSpan &time) const {
    return !(*this == time);
}

// Overloads the += operator.
TimeSpan TimeSpan::operator+=(const TimeSpan &time) {
    hours = time.hours + hours;
    minutes = time.minutes + minutes;
    seconds = time.seconds + seconds;
    return *this;
}

// Overloads the -= operator.
TimeSpan TimeSpan::operator-=(const TimeSpan &time) {
    hours = hours - time.hours;
    minutes = minutes - time.minutes;
    seconds = seconds - time.seconds;
    return *this;
}

// Overloads the + operator to add two durations.
TimeSpan TimeSpan::operator+(const TimeSpan &time) const {
    TimeSpan result = *this;
    result += time;
    return result;
}

// Overloads the - operator to subtract two durations.
TimeSpan TimeSpan::operator-(const TimeSpan &time) const {
    TimeSpan result = *this;
    result -= time;
    return result;
}

// Overloads unary negation operator to produce the negative of its operand.
TimeSpan TimeSpan::operator-() const {
    TimeSpan temp;
    temp.hours = -hours;
    temp.minutes = -minutes;
    temp.seconds = -seconds;
    return temp;
}