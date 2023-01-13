#pragma once
#include <cmath>


class carController
{
public:
    carController();

    /// <summary>
    /// handles how the players car will be effected by input
    /// changing is speed and angle 
    /// </summary>
    /// parameters taken in are used to determine what input was used by player
    void inputHandler(bool Up, bool Down, bool Right, bool Left, bool t_onTrack);

    /// <summary>
    /// adjusts angle of the car so it moves towards the checkpoint 
    /// </summary>
    /// <param name="nextCheckpoint"> the position of the targeted checkpoint the car is going towrds</param>
    /// <returns> whether it has found its current checkpoint its looking for</returns>
    bool foundTarget(float t_x, float t_y);
 
    /// <summary>
    /// final positition after being effects by the current angle of the car 
    /// </summary>
    /// <returns></returns>
    float getUpdatedX();
    float getUpdatedY();

    void collisionHandler(float t_x, float t_y);


    // set functions 
    void setPosition(float t_x, float t_y);
    void setSpeed(float t_speed);
    void setAngle(float t_angle);

    /// <summary>
    /// return the lap and also make sure it doens't go over 3
    /// </summary>
    /// <returns></returns>
    int& getCurrentLap();

    // get functions 
    int& getCurrentCHeckPoint();

    float  getX();
    float  getY();

    float getSpeed();
    float getAngle();
    float getMaxSpeed();

    void activateNitroBoost();
    void activateSlowDown();

private:
    float m_x;
    float m_y;

    float m_speed = 0;
    float m_angle = 0;
    float carRadius = 22; 

    float m_maxSpeed = 12.0;
    float m_acceleration = 0.2;
    float m_deceleration = 0.3;
    float m_turnSpeed = 0.08;

    // lap & checkpoint data 
    int m_currentCheckpoint = -1; 
    int m_lapsCompleted = 0;


    bool m_slowedDown; 
};