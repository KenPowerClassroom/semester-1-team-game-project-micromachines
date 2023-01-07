
#include <iostream>
#include "Car.h"
#include "Laps.h"
using namespace sf;



int racing()
{

    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
    app.setFramerateLimit(60);
    sf::CircleShape m_checpointCircle; 
    sf::View m_camera;
    sf::Vector2f lastLocation; 

    m_checpointCircle.setFillColor(sf::Color::Red);
    m_checpointCircle.setRadius(50);
     m_checpointCircle.setPosition({ 360, 700 });

    // visual set up for cars 
    Texture t1, t2, t3;
    Color colors[10] = { Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White };
    t1.loadFromFile("images/racing/background.png");
    t2.loadFromFile("images/racing/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite sBackground(t1);
   
    int i = 0;
    
    sBackground.scale(2, 2);
    Laps lap; 
    const int numOfCars = 5;
    std::vector<newCar>cars; 
    
    for (int i = 0; i < numOfCars; i++)
    {
        float x = 300 + i * 50;
        float y = 1700 + i * 80;
        float speed = 7 + i;
       
        newCar car(t2,{x,y},speed, colors[i]);
        cars.push_back(car); 
    }

   
    // screen 
    int offsetX = 0, offsetY = 0;
    float minScreenWidth = 320;
    float minScreenHeight = 240;
    float maxScreenWidth = 2500;
    float maxScreenHeight = 3400;
    // screen 



    // game loop 
    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        // movememnt 
        cars[0].steer(); 
        lap.checkForCollision(cars[0].getSprite()); 

        for (int i = 0; i < numOfCars; i++)
        {
            cars[i].updatePosition();
        }
        // speed management  

        for (int  i = 1; i < numOfCars; i++)
        {
            cars[i].findNextCheckpoint(); 
        }
       
        for (int collisionCheck = 0; collisionCheck < numOfCars; collisionCheck++)
        {
            for (int checkAgainst = 0; checkAgainst < numOfCars; checkAgainst++)
            {
                cars[collisionCheck].checkForCollisionAgainst(cars[checkAgainst].getPosition()); 
            }
        }

     


        app.clear(Color::Black);

        // Border locking X
        if (cars[0].getPosition().x > minScreenWidth && cars[0].getPosition().x < maxScreenWidth)
        {
            offsetX = cars[0].getPosition().x - minScreenWidth;
        }

        // Border locking Y
        if (cars[0].getPosition().y > minScreenHeight && cars[0].getPosition().y < maxScreenHeight)
        {
            offsetY = cars[0].getPosition().y - minScreenHeight;
        }

        std::cout << "x: " << cars[0].getPosition().x << " y: " << cars[0].getPosition().y << "\n";
        sBackground.setPosition(-offsetX, -offsetY);
        
        
        app.draw(sBackground);
        lap.draw(app); 
        //app.draw(m_checpointCircle); 
    
        // screen 
        lap.updatePosition(offsetX, offsetY ); 
        for (int i = 0; i < numOfCars; i++)
        {
            cars[i].setPosition({ cars[i].getPosition().x - offsetX, cars[i].getPosition().y - offsetY });
            cars[i].setRotation();
            cars[i].draw(app); 

        }
        // screen 
        app.display();
    }

    return 0;
}
