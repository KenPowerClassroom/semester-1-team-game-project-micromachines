#include "carController.h"
#include <iostream>
carController::carController()
{
}

void carController::inputHandler(bool Up, bool Down, bool Right, bool Left)
{
    std::cout << m_angle << std::endl; 
    //car movement
    if (Up && m_speed < m_maxSpeed)
    {
        if (m_speed < 0)
        {
            m_speed += m_deceleration;
        }
        else
        {
            m_speed += m_acceleration;
        }
    }


    if (Down && m_speed > -m_maxSpeed)
    {
        if (m_speed > 0)
        {
            m_speed -= m_deceleration;
        }
        else
        {
            m_speed -= m_acceleration;
        }
    }


    if (!Up && !Down)
    {
        if (m_speed - m_deceleration > 0)
        {
            m_speed -= m_deceleration;
        }
        else if (m_speed + m_deceleration < 0)
        {
            m_speed += m_deceleration;
        }
        else
        {
            m_speed = 0;
        }
    }


    if (Right && m_speed != 0)
    {
        m_angle += m_turnSpeed * m_speed / m_maxSpeed;
    }
    if (Left && m_speed != 0)
    {
        m_angle -= m_turnSpeed * m_speed / m_maxSpeed;
    }


}

 bool carController::foundTarget(sf::Vector2f nextCheckpoint)
{
   ; 
    float beta = m_angle - atan2(nextCheckpoint.x -m_position.x, -nextCheckpoint.y + m_position.y);
    m_angle;
    if (sin(beta) < 0)
    {
        m_angle += 0.005 * m_speed;
    }
    else
    {
        m_angle -= 0.005 * m_speed;
    }

    if ((m_position.x - nextCheckpoint.x) * (m_position.x - nextCheckpoint.x)
        + (m_position.y - nextCheckpoint.y) * (m_position.y - nextCheckpoint.y) < 25 * 25) /*When close to checkpoint*/
    {
        return true; //Goes from 0 to 8 and wraps around
    }
    else
    {
        return false; 
    }
}

 void carController::setPosition(sf::Vector2f t_position)
 {
     m_position = t_position; 
 }

 void carController::setSpeed(float t_speed)
 {
     m_speed = t_speed; 
 }

 void carController::setAngle(float t_angle)
 {
     m_angle = t_angle;
 }

 sf::Vector2f carController::getUpdatedPositioning()
 {
     m_position.x += sin(m_angle) * m_speed;
     m_position.y -= cos(m_angle) * m_speed; 

     return m_position; 

 }

 void carController::collisionHandler(sf::Vector2f t_otherCarPosition)
 {
     const int CAR_HITBOX = 4 * carRadius * carRadius;
     int distanceBetweenX = 0, distanceBetweenY = 0;

     // if the distance between the cars is lesser than the radisu 
     while (distanceBetweenX * distanceBetweenX + distanceBetweenY * distanceBetweenY < CAR_HITBOX)
     {
         // pushes car to the side by a tenth of the distance between the cars 
         m_position.x += distanceBetweenX / 10.0;
         m_position.x += distanceBetweenY / 10.0;
         t_otherCarPosition.x -= distanceBetweenX / 10.0;
         t_otherCarPosition.y -= distanceBetweenY / 10.0;

         distanceBetweenX = m_position.x - t_otherCarPosition.x;
         distanceBetweenY = m_position.y - t_otherCarPosition.y;


         // if the cars are touching 
         if (distanceBetweenX == 0 && distanceBetweenY == 0)
         {
             break;
         }

     }
 }


 sf::Vector2f carController::getPosition()
 {
     return m_position;
 }

 float carController::getSpeed()
{
    return m_speed;
}

float carController::getAngle()
{
    return m_angle * 180 / 3.141593;
}

int& carController::getCurrentCHeckPoint()
{
    return m_currentCheckpoint; 
}

int& carController::getCurrentLap()
{
    return m_lapsCompleted;
}
