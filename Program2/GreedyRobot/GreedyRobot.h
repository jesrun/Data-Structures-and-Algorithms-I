// Name: Jessica Runandy
// Date: October 22, 2019
// Program 2 : The Greedy Robot (Recursion)
// Description: A robot is positioned in a two-dimensional coordinate grid of only integral numbers,
// and there is a treasure placed at the same grid. The robot can move up(North), down(South), left(West),
// or right(East). There is a constraint of how the robot may never move in the same direction more than
// MaxDistance times in a row.


#include <string>
#include "Point.h"
using namespace std;

#ifndef GREEDYROBOT_GREEDYROBOT_H
#define GREEDYROBOT_GREEDYROBOT_H

class GreedyRobot {
    friend ostream& operator<<(ostream &outStream, const GreedyRobot &robot2);
public:
    GreedyRobot();
    GreedyRobot(Point initialPoint, Point finalPoint, int maxDistance);
    void FindTreasure(Point initialPoint, Point finalPoint, int maxDistance);
    Point getInitialPoint() const;
    Point getFinalPoint() const;
    bool ValidStep(string path, char direction, int maxDistance);


private:
    void FindTreasureHelper(Point initialPoint, Point finalPoint, string path);
    Point initialPoint;
    Point finalPoint;
    int maxDistance;
    string path;
    int numberOfPaths;
};

#endif
