#include "lap_logic.h"
#include <cmath>
#include <iostream>
float LapsLogicController::getCheckpointX(int t_desiredCheckpoint)
{
    return points[t_desiredCheckpoint][m_x];
}

float LapsLogicController::getCheckPointY(int t_desiredCheckpoint)
{
    return points[t_desiredCheckpoint][m_y];
}

bool LapsLogicController::isNextValidCheckPoint( int t_nextCheckpoint,int &t_carsCurrentCheckpoint)
{
    if (t_carsCurrentCheckpoint + 1 == t_nextCheckpoint)
    {
        return true; 
    }
    else
    {
        return false;
    }
}

bool LapsLogicController::collisionCheck(float t_x, float t_y, int t_desiredCheckpoint, int& t_carsCurrentCheckpoint)
{
    if (isNextValidCheckPoint(t_desiredCheckpoint, t_carsCurrentCheckpoint))
    {
        float carSize = 22;
        float checkpointRadius = 100;
        float distance = (points[t_desiredCheckpoint][m_x] + checkpointRadius - t_x) * (points[t_desiredCheckpoint][m_x] + checkpointRadius - t_x)
            + (points[t_desiredCheckpoint][m_y] + checkpointRadius - t_y) * (points[t_desiredCheckpoint][m_y] + checkpointRadius - t_y);

        float distanceSquared = sqrt(distance);

        if (distanceSquared <= checkpointRadius + carSize)
        {
            //m_checkPointsPassed[t_desiredCheckpoint] = true;
            t_carsCurrentCheckpoint++;
            return true;
        }
    }
    
   
   return false;
    
    
}

bool LapsLogicController::allcheckPointsPassed(int& t_carsCurrentCheckpoint, int& t_lapsCompleted)
{
    if(t_carsCurrentCheckpoint == 7)
    {
        t_carsCurrentCheckpoint = -1;
        t_lapsCompleted++;
        return true;
    }
    return false;
}
