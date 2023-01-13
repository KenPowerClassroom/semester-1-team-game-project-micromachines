#include "Car.h"
#include <iostream>


newCar::newCar(sf::Vector2f t_startPosition, float t_speed)
{
    carController.setPosition(t_startPosition.x, t_startPosition.y);
    carController.setSpeed(t_speed);
}

newCar::newCar(sf::Texture &t_carTexture, sf::Vector2f t_startPosition, float t_speed, sf::Color t_carColor)
{
	m_body.setTexture(t_carTexture); 
	m_body.setOrigin(22, 22);
    m_body.setColor(t_carColor);

    carController.setPosition(t_startPosition.x, t_startPosition.y); 
    carController.setSpeed(t_speed); 
}

void newCar::setPosition(sf::Vector2f t_position)
{
	m_body.setPosition(t_position); 
}


void newCar::findNextCheckpoint()
{
    float tx = points[checkpoint][0];
    float ty = points[checkpoint][1];
   
    if (carController.foundTarget(tx,ty))
    {
        checkpoint = (checkpoint + 1) % num;
        
    }
}

sf::Vector2f newCar::getPosition()
{
    return { carController.getX(),carController.getY() };
}

int& newCar::getCurrentCheckpoint()
{
    return carController.getCurrentCHeckPoint(); 
}

int& newCar::getCurrentLap()
{
    return carController.getCurrentLap();
}

void newCar::setRotation()
{
    m_body.setRotation(carController.getAngle());
}

void newCar::updatePosition()
{
   
    m_body.setPosition({ carController.getUpdatedX(),carController.getUpdatedY() });
}

void newCar::draw(sf::RenderWindow &t_window)
{
    t_window.draw(m_body); 
}

void newCar::steer(bool t_onTrack)
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

    carController.inputHandler(Up, Down, Right, Left, t_onTrack); 
}

void newCar::checkForCollisionAgainst(sf::Vector2f t_otherCarPosition)
{
    carController.collisionHandler(t_otherCarPosition.x, t_otherCarPosition.y); 
}

sf::Sprite newCar::getSprite()
{
    return m_body;
}

void newCar::nitroBoost()
{
    carController.activateNitroBoost();
}

void newCar::slowDown()
{
    carController.activateSlowDown();
}

float newCar::getSpeed()
{
    return carController.getSpeed();
}

void newCar::resetSpeed(float t_speed)
{
    carController.setSpeed(t_speed);
}



