#include "Car.h"
#include <iostream>
newCar::newCar()
{
    m_speed = 2; 
    m_angle = 0;
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





void newCar::findNextCheckpoint()
{


    float tx = points[checkpoint][0];
    float ty = points[checkpoint][1];
   
    if (carController.foundTarget({tx,ty}, m_position, m_speed))
    {
        checkpoint = (checkpoint + 1) % num;
        
    }
   m_angle = carController.getAngle(); 
  
}

sf::Vector2f newCar::getPosition()
{
    return m_position;
}

void newCar::setRotation()
{
    m_body.setRotation(m_angle * 180 / 3.141593);
}

void newCar::updatePosition()
{
    m_position.x += sin(m_angle) * m_speed;
    m_position.y -= cos(m_angle) * m_speed;
    m_body.setPosition(m_position); 
}

void newCar::draw(sf::RenderWindow &t_window)
{
    t_window.draw(m_body); 
}

void newCar::steer()
{

    bool Up = 0, Down = 0,  Right= 0, Left = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Up = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Down = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Right = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
         Left = 1;
    }

    carController.inputHandler(Up, Down, Right, Left); 
   

    m_speed = carController.getSpeed(); 
    m_angle = carController.getAngle(); 

}



