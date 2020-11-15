// Name: Jessica Runandy
// Date: October 22, 2019
// Program 2 : The Greedy Robot (Recursion)
// Description: Uses the command line arguments to output the GreedyRobot program.


#include <iostream>
#include <stdlib.h>
#include "GreedyRobot.h"
using namespace std;

int main(int argc, char* argv[]) {
    int startingX = 0;
    int startingY = 0;
    int endX = 0;
    int endY = 0;
    int maximumDistance = 0;
    if (argc != 6) {
        cerr << "Usage error." << endl;
        return -1;
    }

    startingX = atoi(argv[1]);
    startingY = atoi(argv[2]);
    endX = atoi(argv[3]);
    endY = atoi(argv[4]);
    maximumDistance = atoi(argv[5]);
    GreedyRobot robot1(Point(startingX, startingY), Point(endX, endY), maximumDistance);
    robot1.FindTreasure(Point(startingX, startingY), Point(endX, endY), maximumDistance);
    return 0;
}