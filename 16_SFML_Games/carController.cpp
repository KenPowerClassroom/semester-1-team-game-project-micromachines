#include "carController.h"

carController::carController()
{
}

void carController::inputHandler(bool Up, bool Down, bool Right, bool Left)
{
    //car movement
    if (Up && speed < maxSpeed)
    {
        if (speed < 0)
        {
            speed += deceleration;
        }
        else
        {
            speed += acceleration;
        }
    }


    if (Down && speed > -maxSpeed)
    {
        if (speed > 0)
        {
            speed -= deceleration;
        }
        else
        {
            speed -= acceleration;
        }
    }


    if (!Up && !Down)
    {
        if (speed - deceleration > 0)
        {
            speed -= deceleration;
        }
        else if (speed + deceleration < 0)
        {
            speed += deceleration;
        }
        else
        {
            speed = 0;
        }
    }


    if (Right && speed != 0)
    {
        angle += turnSpeed * speed / maxSpeed;
    }
    if (Left && speed != 0)
    {
        angle -= turnSpeed * speed / maxSpeed;
    }

}


float carController::getSpeed()
{
    return speed;
}

float carController::getAngle()
{
    return angle;
}
