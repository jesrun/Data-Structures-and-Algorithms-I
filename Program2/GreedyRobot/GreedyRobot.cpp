// Name: Jessica Runandy
// Date: October 22, 2019
// Program 2 : The Greedy Robot (Recursion)
// Description: GreedyRobot uses recursion to determine all the unique shortest possible paths
// from the robot to the treasure. There is a constraint of how the user determines the maximum
// times the robot can move in one direction.


#include <iostream>
#include "GreedyRobot.h"
using namespace std;

GreedyRobot::GreedyRobot() {
}

// Initializes the initialPoint, finalPoint, and maxDistance to the user input.
GreedyRobot::GreedyRobot(Point initialPoint, Point finalPoint, int maxDistance) {
    this->initialPoint = initialPoint;
    this->finalPoint = finalPoint;
    this->maxDistance = maxDistance;
    numberOfPaths = 0;
}

Point GreedyRobot::getInitialPoint() const {
    return initialPoint;
}

Point GreedyRobot::getFinalPoint() const {
    return finalPoint;
}

// Overloads the << operator to print out the total number of unique shortest possible paths that
// the robot can take.
ostream &operator<<(ostream &outStream, const GreedyRobot &robot) {
    outStream << robot.numberOfPaths << endl;
    return outStream;
}


// Determines all the unique shortest possible paths from the robot to the treasure, and the robot cannot
// move in the same direction more than MaxDistance times in a row (MaxDistance is determined by the client).
// Prints the unique shortest possible paths and the number of paths.
void GreedyRobot::FindTreasure(Point initialPoint, Point finalPoint, int maxDistance) {
    if (initialPoint.ShortestDistance(finalPoint) == 0) {
        cout << "Number of paths: 0" << endl;
    } else {
        FindTreasureHelper(initialPoint, finalPoint, "");
        cout << "Number of paths: " << numberOfPaths << endl;
    }
}

// Determines all the unique shortest paths and the number of paths that the robot can take to the treasure.
// The robot cannot move in the same direction more than maxDistance times in a row.
void GreedyRobot::FindTreasureHelper(Point initialPoint, Point finalPoint, string path) {
    int shortestPossibleDistance = initialPoint.ShortestDistance(finalPoint);
    int initialX = initialPoint.getX();
    int initialY = initialPoint.getY();
    int finalX = finalPoint.getX();
    int finalY = finalPoint.getY();
    if (initialPoint == finalPoint) {
        numberOfPaths++;
        cout << "moves: " << path << endl;
    }
    if ((initialX > finalX) && (Point(initialX - 1, initialY).ShortestDistance(finalPoint) <
         shortestPossibleDistance) && (ValidStep(path, 'W', maxDistance))) {
        FindTreasureHelper(Point(initialX - 1, initialY), finalPoint, path + "W");
    }
    if ((initialX < finalX) && (Point(initialX + 1, initialY).ShortestDistance(finalPoint) <
         shortestPossibleDistance) && (ValidStep(path, 'E', maxDistance))) {
        FindTreasureHelper(Point(initialX + 1, initialY), finalPoint, path + "E");
    }
    if ((initialY > finalY) && (Point(initialX, initialY - 1).ShortestDistance(finalPoint) <
         shortestPossibleDistance) && (ValidStep(path, 'S', maxDistance))) {
        FindTreasureHelper(Point(initialX, initialY - 1), finalPoint, path + "S");
    }
    if ((initialY < finalY) && (Point(initialX, initialY + 1).ShortestDistance(finalPoint) <
         shortestPossibleDistance) && (ValidStep(path, 'N', maxDistance))) {
        FindTreasureHelper(Point(initialX, initialY + 1), finalPoint, path + "N");
    }
}

// Determines if the next direction is a valid step using the string path that is passed in.
// Uses the maxDistance to compare the letter with the direction, and returns true if it is a valid step.
bool GreedyRobot::ValidStep(string path, char direction, int maxDistance) {
    int count = 0;
    if (path.length() < maxDistance) {
        return true;
    } else if (path.length() == maxDistance) {
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == direction) {
                count++;
            }
        }
    } else {
        string countPath = path.substr(path.length() -  maxDistance);
        for (int i = 0; i < countPath.length(); i++) {
            if (countPath[i] == direction) {
                count++;
            }
        }
    }
    if (count == maxDistance) {
        return false;
    }
    return true;
}