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

bool LapsLogicController::isNextValidCheckPoint( int t_nextCheckpoint)
{
    if (m_playerCurrentLap + 1 == t_nextCheckpoint)
    {
        return true; 
    }
    else
    {
        return false;
    }
}

bool LapsLogicController::collisionCheck(float t_x, float t_y, int t_desiredCheckpoint)
{
    if (isNextValidCheckPoint(t_desiredCheckpoint))
    {
        float carSize = 22;
        float checkpointRadius = 100;
        float distance = (points[t_desiredCheckpoint][m_x] + checkpointRadius - t_x) * (points[t_desiredCheckpoint][m_x] + checkpointRadius - t_x)
            + (points[t_desiredCheckpoint][m_y] + checkpointRadius - t_y) * (points[t_desiredCheckpoint][m_y] + checkpointRadius - t_y);

        float distanceSquared = sqrt(distance);

        if (distanceSquared <= checkpointRadius + carSize)
        {
            m_checkPointsPassed[t_desiredCheckpoint] = true;
            m_playerCurrentLap++;
            return true;
        }
    }
    
   
   return false;
    
    
}

bool LapsLogicController::allcheckPointsPassed()
{
    int passed = 0; 
    for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
    {
        if (m_checkPointsPassed[i])
        {
            passed++; 
        }
    }

    if (passed == NUM_OF_CHECKPOINTS)
    {
        // resets variables so lap can be reset
        for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
        {
            m_playerCurrentLap = -1; 
            m_checkPointsPassed[i] = false;
        }
        return true;
    }



    return false;
}
