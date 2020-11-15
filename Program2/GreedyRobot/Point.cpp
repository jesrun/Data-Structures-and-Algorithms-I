// Name: Jessica Runandy
// Date: October 22, 2019
// Program 2 : The Greedy Robot (Recursion)
// Description: Point represents the x and y coordinates in a Cartesian plane.


#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0) {
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

// Prints the x and y coordinates in the form (x, y).
void Point::PrintCoordinates() {
    cout << "(" << x << ", " << y << ")" << endl;
}

bool Point::operator==(const Point &point2) const {
    return (x == point2.x) && (y == point2.y);
}

bool Point::operator!=(const Point &point2) const {
    return (x != point2.x) && (y != point2.y);
}

int Point::ShortestDistance(Point point2) {
    int calculate = abs(x - point2.x) + abs(y - point2.y);
    return calculate;
}