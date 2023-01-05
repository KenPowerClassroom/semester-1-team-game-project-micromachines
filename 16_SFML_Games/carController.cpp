#include "carController.h"

carController::carController()
{
}

void carController::inputHandler(bool Up, bool Down, bool Right, bool Left)
{
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

 bool carController::foundTarget(sf::Vector2f nextCheckpoint, sf::Vector2f t_currentPositin, float t_speed)
{
    m_speed = t_speed; 
    float beta = m_angle - atan2(nextCheckpoint.x - t_currentPositin.x, -nextCheckpoint.y + t_currentPositin.y);
    m_angle;
    if (sin(beta) < 0)
    {
        m_angle += 0.005 * m_speed;
    }
    else
    {
        m_angle -= 0.005 * m_speed;
    }

    if ((t_currentPositin.x - nextCheckpoint.x) * (t_currentPositin.x - nextCheckpoint.x) 
        + (t_currentPositin.y - nextCheckpoint.y) * (t_currentPositin.y - nextCheckpoint.y) < 25 * 25) /*When close to checkpoint*/
    {
        return true; //Goes from 0 to 8 and wraps around
    }
    else
    {
        return false; 
    }
}


float carController::getSpeed()
{
    return m_speed;
}

float carController::getAngle()
{
    return m_angle;
}
