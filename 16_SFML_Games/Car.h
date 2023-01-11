#pragma once
#include <SFML/Graphics.hpp>
#include "carController.h"

class newCar
{
public:
    newCar(sf::Vector2f t_startPosition, float t_speed);

    /// <summary>
    /// sets up cars, texture, starting position, spped and what color car will be
    /// </summary>
    /// <param name="t_carTexture"> desired texture</param>
    /// <param name="t_startPosition"> desired starting point </param>
    /// <param name="t_speed"> desired speed, all cars have a different one</param>
    /// <param name="t_carColor"> color applied to car texture</param>
    newCar(sf::Texture &t_carTexture, sf::Vector2f t_startPosition, float t_speed, sf::Color t_carColor);

    /// <summary>
    /// sets position of car, effected by offset in the racing cpp
    /// </summary>
    void setPosition(sf::Vector2f t_position); 

    /// <summary>
    /// for npc cars, finds the next next target for them to go to
    /// </summary>
    void findNextCheckpoint(); 

    /// <summary>
    /// gets the current position of the car, uneffected by the current angle of the car
    /// </summary>
    sf::Vector2f getPosition(); 

    /// <summary>
    /// gets reference to the current checkpoint the car has passed
    /// </summary>
    /// <returns></returns>
    int& getCurrentCheckpoint();

    /// <summary>
   /// gets reference to the current lap of the car
   /// </summary>
   /// <returns></returns>
    int& getCurrentLap(); 

    /// <summary>
    /// sets rotation of the car
    /// </summary>
    void setRotation(); 

    /// <summary>
    /// updates the car position with effects of angling of the car
    /// </summary>
    void updatePosition(); 

    /// <summary>
    /// draws the car with a reference to the game windoe
    /// </summary>
    /// <param name="t_window"> game window</param>
    void draw(sf::RenderWindow &t_window); 


    void steer(bool t_onTrack); 

    /// <summary>
    /// passes other car location to controler to check for collision
    /// </summary>
    /// <param name="t_otherCarPosition"> other car position</param>
    void checkForCollisionAgainst(sf::Vector2f t_otherCarPosition); 
   
    sf::Sprite getSprite();

    void nitroBoost();
    void slowDown();

    float getSpeed();

    void resetSpeed(float t_speed);
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

