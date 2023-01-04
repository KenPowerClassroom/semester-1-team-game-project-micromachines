#pragma once
#include <cmath>
#include <SFML/System/Vector2.hpp>
class carController
{
public:
    carController();
    void inputHandler(bool Up, bool Down, bool Right, bool Left);
    bool foundTarget(sf::Vector2f nextCheckpoint, sf::Vector2f t_currentPositin); 
    float getSpeed();
    float getAngle();
private:

    
    float m_speed = 0;
    float m_angle = 0;
    float m_maxSpeed = 12.0;
    float m_acceleration = 0.2;
    float m_deceleration = 0.3;
    float m_turnSpeed = 0.08;

};