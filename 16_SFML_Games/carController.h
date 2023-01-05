#pragma once
#include <cmath>
#include <SFML/System/Vector2.hpp>
class carController
{
public:
    carController();

    /// <summary>
    /// handles how the players car will be effected by input
    /// changing is speed and angle 
    /// </summary>
    /// parameters taken in are used to determine what input was used by player
    void inputHandler(bool Up, bool Down, bool Right, bool Left);

    /// <summary>
    /// adjusts angle of the car so it moves towards the checkpoint 
    /// </summary>
    /// <param name="nextCheckpoint"> the position of the targeted checkpoint the car is going towrds</param>
    /// <returns> whether it has found its current checkpoint its looking for</returns>
    bool foundTarget(sf::Vector2f nextCheckpoint);
 
    /// <summary>
    /// final positition after being effects by the current angle of the car 
    /// </summary>
    /// <returns></returns>
    sf::Vector2f getUpdatedPositioning();

    void collisionHandler(sf::Vector2f t_otherCarPosition); 


    // set functions 
    void setPosition(sf::Vector2f t_position);
    void setSpeed(float t_speed);
    void setAngle(float t_angle);


    // get functions 
    sf::Vector2f getPosition();
    float getSpeed();
    float getAngle();
private:

    sf::Vector2f m_position; 
    float m_speed = 0;
    float m_angle = 0;
    float carRadius = 22; 

    float m_maxSpeed = 12.0;
    float m_acceleration = 0.2;
    float m_deceleration = 0.3;
    float m_turnSpeed = 0.08;

};