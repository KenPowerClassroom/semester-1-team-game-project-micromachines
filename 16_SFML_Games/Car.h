#pragma once
#include <SFML/Graphics.hpp>
//const int num = 8; //checkpoints
//int point[num][2] = { 300, 610,
//                      1270,430,
//                      1380,2380,
//                      1900,2460,
//                      1970,1700,
//                      2550,1680,
//                      2560,3150,
//                      500, 3300 };

//struct Car
//{
//    float x, y, speed, angle; int checkpoint;
//
//    // Constructor
//    Car() { speed = 2; angle = 0; checkpoint = 0; }
//
//    void move()
//    {
//        x += sin(angle) * speed;
//        y -= cos(angle) * speed;
//    }
//
//    void findTarget()
//    {
//        float tx = point[checkpoint][0];
//        float ty = point[checkpoint][1];
//        // Atan2 converts an angle in degrees to a vector
//        float beta = angle - atan2(tx - x, -ty + y);
//        if (sin(beta) < 0) angle += 0.005 * speed; else angle -= 0.005 * speed;
//
//        if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25) /*When close to checkpoint*/ checkpoint = (checkpoint + 1) % num; //Goes from 0 to 8 and wraps around
//    }   
//};

class carController
{
public:
    carController();
    void inputHandler(bool Up, bool Down, bool Right, bool Left); 
    float getSpeed(); 
    float getAngle(); 
private:
    float speed = 0, angle = 0;
    float maxSpeed = 12.0;
    float acceleration = 0.2, deceleration = 0.3;
    float turnSpeed = 0.08;

};

class newCar
{
public:
    // origin need to be 22
    newCar(); 
    newCar(sf::Texture &t_carTexture, sf::Vector2f t_startPosition, float t_speed, sf::Color t_carColor);

    void setPosition(sf::Vector2f t_position); 

    void findTarget(); 

    sf::Vector2f getPosition(); 

    void setRotation(); 

    void updatePosition(); 

    void draw(sf::RenderWindow &t_window); 

    void steer(); ;

    float m_speed;
    float m_angle; 
private:

    sf::Sprite m_body; 
    sf::Vector2f m_position; 
    carController carController; 
    float carRadius{ 22 };


};

