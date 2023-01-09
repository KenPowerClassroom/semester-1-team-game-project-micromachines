#pragma once

class LapsLogicController
{
public:

    /// <summary>
    /// gets the current x axis position of the the desired checkpoint 
    /// </summary>
    /// <param name="t_desiredCheckpoint">which checkpoint in array you wish to check</param>
    /// <returns></returns>
    float getX(int t_desiredCheckpoint);

    /// <summary>
    /// gets the current y axis position of the the desired checkpoint 
    /// </summary>
    /// <param name="t_desiredCheckpoint"> which checkpoint in array you wish to check </param>
    /// <returns></returns>
    float getY(int t_desiredCheckpoint);

    /// <summary>
    /// collision logic
    /// gets the distance squared and checks if it is smaller than the size of the circle and car addedtogether
    /// </summary>
    /// <param name="t_x"> current position of the car on x axis</param>
    /// <param name="t_y"> current position of the car on y axis </param>
    /// <param name="t_desiredCheckpoint"> which checkpoint is being checked for a coliison </param>
    /// <returns></returns>
    bool collisionCheck(float t_x, float t_y, int t_desiredCheckpoint);

private:

    int m_checkpointRadius = 100;
    int NUM_OF_CHECKPOINTS = 8;
    
    int m_x = 0; 
    int m_y = 1;
    float points[8][2] = 
    {
        {300 - 75, 610},
        {1270,430},
        {1380,2380 + 75},
        {1900 - 115,2460},
        {1970 - 145,1700},
        {2550 - 80,1680},
        {2560 - 290,3150},
        {500, 3300 - 100} 
    };

    
   
};