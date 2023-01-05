#pragma once
#include <SFML/Graphics.hpp>
#include "carController.h"

class newCar
{
public:
    newCar(sf::Texture &t_carTexture, sf::Vector2f t_startPosition, float t_speed, sf::Color t_carColor);

    void setPosition(sf::Vector2f t_position); 

    void findNextCheckpoint(); 

    sf::Vector2f getPosition(); 

    void setRotation(); 

    void updatePosition(); 

    void draw(sf::RenderWindow &t_window); 

    void steer(); 

    void checkForCollisionAgainst(sf::Vector2f t_otherCarPosition); 

   
private:

    sf::Sprite m_body; 
    carController carController; 

    int checkpoint; 
    int num = 8; 
    int points[8][2] = { 300, 610,
                      1270,430,
                      1380,2380,
                      1900,2460,
                      1970,1700,
                      2550,1680,
                      2560,3150,
                      500, 3300 };
};

