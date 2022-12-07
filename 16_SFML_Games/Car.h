#pragma once
#include <SFML/Graphics.hpp>
const int num = 8; //checkpoints
int points[num][2] = { 300, 610,
                      1270,430,
                      1380,2380,
                      1900,2460,
                      1970,1700,
                      2550,1680,
                      2560,3150,
                      500, 3300 };

struct Car
{
    float x, y, speed, angle; int checkpoint;

    // Constructor
    Car() { speed = 2; angle = 0; checkpoint = 0; }

    void move()
    {
        x += sin(angle) * speed;
        y -= cos(angle) * speed;
    }

    void findTarget()
    {
        float tx = points[checkpoint][0];
        float ty = points[checkpoint][1];
        float beta = angle - atan2(tx - x, -ty + y);
        if (sin(beta) < 0) angle += 0.005 * speed; else angle -= 0.005 * speed;

        if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25) /*When close to checkpoint*/ checkpoint = (checkpoint + 1) % num; //Goes from 0 to 8 and wraps around
    }   
};