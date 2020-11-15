// Name: Jessica Runandy
// Date: October 22, 2019
// Program 2 : The Greedy Robot (Recursion)
// Description: Point class represents the x and y coordinates in a Cartesian plane.


#include <iostream>
using namespace std;

#ifndef GREEDYROBOT_POINT_H
#define GREEDYROBOT_POINT_H

class Point {

public:
    Point();
    Point(int x,int y);
    int getX() const;
    int getY() const;
    void PrintCoordinates();
    int ShortestDistance(Point point2);
    bool operator==(const Point &point2) const;
    bool operator!=(const Point &point2) const;

private:
    int x;
    int y;
};

#endif
