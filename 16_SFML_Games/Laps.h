#pragma once
#include <SFML/Graphics.hpp>
#include "lap_logic.h"

class Laps
{

public:
    Laps(); 
    void draw(sf::RenderWindow & t_window); 

    /// <summary>
    /// changes the position of the circle shapes depending on the offset of the screen
    /// </summary>
    /// <param name="t_offsetX"> x axis offset of screen </param>
    /// <param name="t_offsetY"> y axis offset of the screen </param>
    void updatePosition(int t_offsetX, int t_offsetY); 

    /// <summary>
    /// checks whether a checkpoints color should be changed 
    /// </summary>
    /// <param name="t_carPosition"> position of player car which will be only car to effect the checpoints color</param>
    void checkForCollision( sf::Vector2f t_carPosition); 

    /// <summary>
    /// checks whether a full lap has been done on the checkpoints and whether to change back there color
    /// </summary>
    void checkForCheckpointReset();
private:
    // stores positions and takes care of collision
    LapsLogicController elLapo; 

    // array of circle shapes that makes up the chekpoints 
    int NUM_OF_CHECKPOINTS = 8;
    sf::CircleShape m_checpointCircle[8]; 

    // custom colors, which opacity will be changed in contrstuctor

    sf::Color Green = sf::Color::Green;
    sf::Color Red =  sf::Color::Red;

    
};