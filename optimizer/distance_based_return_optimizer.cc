#include "optimizer.h"
#include <cmath>
#include <iostream>

#define OPPONENT_LEFT_TOP_CORNER position(0.0, 44.0)
#define OPPONENT_RIGHT_TOP_CORNER position(20.0, 44.0)
#define OPPONENT_LEFT_BOTTOM_CORNER position(0.0, 22.0)
#define OPPONENT_RIGHT_BOTTOM_CORNER position(20.0, 22.0)

// Return the position of the corner which is furthest away from the opponent position.
position DistanceBasedReturnOptimizer::FindBestPositionForReturn(position opponentPosition, position myPosition)
{
    position positionWithMaximumDistance = opponentPosition;
    double maxDistanceSoFar = 0.0, distance;

    position prospectivePositions[] = {OPPONENT_LEFT_TOP_CORNER, OPPONENT_RIGHT_TOP_CORNER, OPPONENT_LEFT_BOTTOM_CORNER, OPPONENT_RIGHT_BOTTOM_CORNER};
    for (int i = 0; i < 4; i++)
    {
        distance = FindDistance(opponentPosition, prospectivePositions[i]);
        if (distance > maxDistanceSoFar)
        {
            maxDistanceSoFar = distance;
            positionWithMaximumDistance = prospectivePositions[i];
        }
    }
    return positionWithMaximumDistance;
}

double DistanceBasedReturnOptimizer::FindDistance(position pos1, position pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}