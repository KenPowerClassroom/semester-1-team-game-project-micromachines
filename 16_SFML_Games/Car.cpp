#include "Car.h"
#include <iostream>
newCar::newCar()
{
    speed = 2; 
    angle = 0;
}

newCar::newCar(sf::Texture &t_carTexture, sf::Vector2f t_startPosition, float t_speed, sf::Color t_carColor)
{
	m_body.setTexture(t_carTexture); 
	m_body.setOrigin(22, 22);
    m_body.setColor(t_carColor);
	m_position =  t_startPosition; 
	m_speed = t_speed; 
}

void newCar::setPosition(sf::Vector2f t_position)
{
	m_body.setPosition(t_position); 
}

void newCar::direction(int t_direction)
{

	int Up = 1, Right = 2, Down = 3, Left = 4;

    if (t_direction ==Up && speed < maxSpeed)
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


    if (t_direction == Down && speed > -maxSpeed)
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


    if (t_direction!=Up && t_direction!=Down)
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
    if (t_direction==Right && speed != 0)
    {
        angle += turnSpeed * speed / maxSpeed;
    }
    if (t_direction==Left && speed != 0)
    {
        angle -= turnSpeed * speed / maxSpeed;
    }

}

void newCar::findTarget()
{
    

    //float tx = points[0][0];
    //float ty = points[0][1];
    //// Atan2 converts an angle in degrees to a vector
    //float beta = angle - atan2(tx - m_position.x, -ty + m_position.y);
    //if (sin(beta) < 0) angle += 0.005 * speed; else angle -= 0.005 * speed;

   // if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25) /*When close to checkpoint*/ checkpoint = (checkpoint + 1) % num; //Goes from 0 to 8 and wraps around
}

sf::Vector2f newCar::getPosition()
{
    return m_position;
}

void newCar::setRotation()
{
    m_body.setRotation(angle * 180 / 3.141593);
}

void newCar::move()
{
    std::cout << speed << std::endl; 
    m_position.x += sin(angle) * speed;
    m_position.y -= cos(angle) * speed;
    m_body.setPosition(m_position); 
}

void newCar::draw(sf::RenderWindow &t_window)
{
    t_window.draw(m_body); 
}
