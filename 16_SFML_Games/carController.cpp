#include "carController.h"
#include <iostream>
carController::carController()
{
}

void carController::inputHandler(bool Up, bool Down, bool Right, bool Left, bool t_onTrack)
{
    //std::cout << m_angle << std::endl; 

    if (t_onTrack == true)
    {
        m_maxSpeed = 12.0;
    }
    if (t_onTrack == false)//if the car us off the track cap its movement speed
    {
        m_maxSpeed = 6.0;
        if (m_speed >= m_maxSpeed)// if the car is already above the capped speed slow it down
        {
            m_speed = m_maxSpeed;
        }
    }
    
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

 bool carController::foundTarget(float t_x, float t_y)
{
   ; 
    float beta = m_angle - atan2(t_x -m_x, -t_y + m_y);
    m_angle;
    if (sin(beta) < 0)
    {
        m_angle += 0.005 * m_speed;
    }
    else
    {
        m_angle -= 0.005 * m_speed;
    }

    if ((m_x - t_x) * (m_x - t_x)
        + (m_y - t_y) * (m_y - t_y) < 25 * 25) /*When close to checkpoint*/
    {
        return true; //Goes from 0 to 8 and wraps around
    }
    else
    {
        return false; 
    }
}

 void carController::setPosition(float t_x, float t_y)
 {
     m_x = t_x;
     m_y = t_y;
 }

 void carController::setSpeed(float t_speed)
 {
     m_speed = t_speed; 
 }

 void carController::setAngle(float t_angle)
 {
     m_angle = t_angle;
 }

 

 float carController::getUpdatedX()
 {
     m_x += sin(m_angle) * m_speed;
     
     return m_x;
 }

 float carController::getUpdatedY()
 {
     m_y -= cos(m_angle) * m_speed;
     return m_y;
 }

 void carController::collisionHandler(float t_x, float t_y)
 {
   
     const int CAR_HITBOX = 4 * carRadius * carRadius;
     int distanceBetweenX = 0, distanceBetweenY = 0;

     // if the distance between the cars is lesser than the radisu 
     while (distanceBetweenX * distanceBetweenX + distanceBetweenY * distanceBetweenY < CAR_HITBOX)
     {
         // pushes car to the side by a tenth of the distance between the cars 
         m_x += distanceBetweenX / 10.0;
         m_x += distanceBetweenY / 10.0;
         t_x -= distanceBetweenX / 10.0;
         t_y -= distanceBetweenY / 10.0;

         distanceBetweenX = m_x - t_x;
         distanceBetweenY = m_y - t_y;


         // if the cars are touching 
         if (distanceBetweenX == 0 && distanceBetweenY == 0)
         {
             break;
         }

     }
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

float carController::getX()
{
    return m_x;
}

float carController::getY()
{
    return m_y;
}

int& carController::getCurrentLap()
{
   
    return m_lapsCompleted;
}

float carController::getMaxSpeed()
{
    return m_maxSpeed;

}

void carController::activateNitroBoost()
{
    m_speed = 20.0f;
}

void carController::activateSlowDown()
{
    m_speed = 3.0f;
}
