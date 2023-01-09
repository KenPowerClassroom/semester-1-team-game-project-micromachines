#include "lap_logic.h"
#include <cmath>
#include <iostream>
float LapsLogicController::getX(int t_desiredCheckpoint)
{
    return points[t_desiredCheckpoint][m_x];
}

float LapsLogicController::getY(int t_desiredCheckpoint)
{
    return points[t_desiredCheckpoint][m_y];
}

bool LapsLogicController::collisionCheck(float t_x, float t_y, int t_desiredCheckpoint)
{
    float carSize = 22; 

    float distance = (points[t_desiredCheckpoint][m_x] + m_checkpointRadius - t_x) * (points[t_desiredCheckpoint][m_x] + m_checkpointRadius - t_x) 
                    + (points[t_desiredCheckpoint][m_y] + m_checkpointRadius - t_y) * (points[t_desiredCheckpoint][m_y] + m_checkpointRadius - t_y);

    float distanceSquared = sqrt(distance);

    if (distanceSquared <= m_checkpointRadius+carSize)
    {
        std::cout << "you have collide with checkpoint" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}
