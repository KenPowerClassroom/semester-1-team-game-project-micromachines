#include "lap_logic.h"
#include <cmath>
#include <iostream>
bool LapsLogic::collisionCheck(float t_x, float t_y)
{
    
    float distance; 
    float distanceSquared;

    int x = 0;
    int y = 1;
    for (int i = 0; i < 8; i++)
    {
       distance = (points[i][x]+50 - t_x) * (points[i][x] + 50 - t_x) + (points[i][y] - t_y) * (points[i][y] - t_y);
       distanceSquared = sqrt(distance);
       if (i == 0)
       {
           std::cout << "Distance: "<<distanceSquared << std::endl;
       }
       if (distanceSquared <= 100)
       {
           std::cout << "you have collide with checkpoint" << std::endl; 
       }
    }
    
    return false;
}
