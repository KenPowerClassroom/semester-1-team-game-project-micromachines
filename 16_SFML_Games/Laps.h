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
    void checkForCollision( sf::Vector2f t_carPosition, int& t_currentCheckpoint, int t_playerCar);

    /// <summary>
    /// checks whether a full lap has been done on the checkpoints and whether to change back there color
    /// </summary>
    void checkForCheckpointReset(int& t_currentCheckpoint, int& t_lapsCompleted,  int t_playerCar);

    /// <summary>
    /// initial set up of text 
    /// </summary>
    void textSetUp(); 

    /// <summary>
    /// updates the laps text to display amount of laps completed
    /// </summary>
    /// <param name="t_laps"> desired players laps</param>
    void updateText(int t_laps, int t_checkpoints);
private:
    // stores positions and takes care of collision
    LapsLogicController lap; 

    // array of circle shapes that makes up the chekpoints 
    int NUM_OF_CHECKPOINTS = 8;
    sf::CircleShape m_checpointCircle[8]; 

    // custom colors, which opacity will be changed in contrstuctor
    sf::Color Green = sf::Color::Green;
    sf::Color Red =  sf::Color::Red;
    sf::Color Blue = sf::Color::Blue;

    sf::Text m_lapsText; 
    sf::Font m_font;
};