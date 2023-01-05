#include "Car.h"
#include <iostream>
newCar::newCar()
{
   /* m_speed = 2; 
    m_angle = 0;*/
}

newCar::newCar(sf::Texture &t_carTexture, sf::Vector2f t_startPosition, float t_speed, sf::Color t_carColor)
{
	m_body.setTexture(t_carTexture); 
	m_body.setOrigin(22, 22);
    m_body.setColor(t_carColor);

    carController.setPosition(t_startPosition); 
    carController.setSpeed(t_speed); 

	/*m_position =  t_startPosition; 
	m_speed = t_speed; */
}

void newCar::setPosition(sf::Vector2f t_position)
{
    //carController.setPosition(t_position);
	m_body.setPosition(t_position); 
}





void newCar::findNextCheckpoint()
{


    float tx = points[checkpoint][0];
    float ty = points[checkpoint][1];
   
    if (carController.foundTarget({tx,ty}))
    {
        checkpoint = (checkpoint + 1) % num;
        
    }
  
}

sf::Vector2f newCar::getPosition()
{
    return carController.getPosition();
}

void newCar::setRotation()
{
    m_body.setRotation(carController.getAngle());
}

void newCar::updatePosition()
{
   
   m_body.setPosition(carController.getUpdatedPositioning()); 
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
}



