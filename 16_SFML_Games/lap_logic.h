#pragma once

class LapsLogic
{
public:
    float getX(float t_i);  
    float getY(float t_i);

    bool collisionCheck(float t_x, float t_y);

private:
    int checkpoint;
    int num = 8;
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