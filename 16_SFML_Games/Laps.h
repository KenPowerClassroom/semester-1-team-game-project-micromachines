#pragma once
#include <SFML/Graphics.hpp>
#include "lap_logic.h"

class Laps
{

public:
    Laps(); 
    void draw(sf::RenderWindow & t_window); 
    void updatePosition(int t_offsetX, int t_offsetY); 
    void checkForCollision(sf::Sprite t_playerCar, sf::Vector2f t_carPosition); 
    void checkForCheckpointReset();

    // soley for purpose of test 
    bool getColorOfFirstCheckpoint(int t_checkpoint); 

private:
    LapsLogic elLapo; 

    sf::CircleShape m_checpointCircle[8]; 
    sf::Color Green = sf::Color::Green;
    sf::Color Red =  sf::Color::Red;
   
    // humble 
    int checkpoint;
    int num = 8;
    sf::Vector2f points[8] = { 
        {300 -75, 610},
        {1270,430},
        {1380,2380+75},
        {1900-115,2460},
        {1970 - 145,1700},
        {2550 - 80,1680},
        {2560 - 290,3150},
        {500, 3300- 100} };
};