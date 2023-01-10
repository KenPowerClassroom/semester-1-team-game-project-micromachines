
#include <iostream>
#include "Car.h"
#include "Laps.h"
#include "LeaderBoard.h"

using namespace sf;

enum GAMESTATE { Gampeplay, ScoreBoard };
int racing()
{

    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
    app.setFramerateLimit(60);
 

    // visual set up for cars 
    Texture t1, t2, t3;
    Color colors[10] = { Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White };
    t1.loadFromFile("images/racing/background.png");
    t2.loadFromFile("images/racing/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite sBackground(t1);
    sBackground.scale(2, 2);
    

    const int NUM_OF_CARS = 5;
    std::vector<newCar>cars; 
    Laps lap;
    LeaderBoard leaderBoard; 
    GAMESTATE currentGamestate = Gampeplay;
    int carsFinished = 0; 

    for (int i = 0; i < NUM_OF_CARS; i++)
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

        if (currentGamestate == Gampeplay)
        {
            // movememnt 
            cars[0].steer();
            for (int i = 0; i < NUM_OF_CARS; i++)
            {
                cars[i].updatePosition();
            }
            // speed management  

            for (int i = 1; i < NUM_OF_CARS; i++)
            {
                cars[i].findNextCheckpoint();
            }

            for (int collisionCheck = 0; collisionCheck < NUM_OF_CARS; collisionCheck++)
            {
                for (int checkAgainst = 0; checkAgainst < NUM_OF_CARS; checkAgainst++)
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
            // laps
            lap.draw(app);
            lap.updatePosition(offsetX, offsetY);
            for (int i = 0; i < NUM_OF_CARS; i++)
            {
                lap.checkForCollision(cars[i].getPosition(), cars[i].getCurrentCheckpoint(), i);
            }
            for (int i = 0; i < NUM_OF_CARS; i++)
            {
                lap.checkForCheckpointReset(cars[i].getCurrentCheckpoint(), cars[i].getCurrentLap(), i);
            }
            lap.updateText(cars[0].getCurrentLap(), cars[0].getCurrentCheckpoint());
            // laps

            
            // screen 
            for (int i = 0; i < NUM_OF_CARS; i++)
            {
                cars[i].setPosition({ cars[i].getPosition().x - offsetX, cars[i].getPosition().y - offsetY });
                cars[i].setRotation();
                cars[i].draw(app);

            }
            
            for (int i = 0; i < NUM_OF_CARS; i++)
            {
                if (cars[i].getCurrentLap() == 3)
                {
                    carsFinished++;
                    leaderBoard.placeCarOnScoreBoard(i);
                }
            }

            if (carsFinished == NUM_OF_CARS)
            {
                currentGamestate = ScoreBoard;
            }
            else
            {
                carsFinished = 0;
            }
        }

        if (currentGamestate == ScoreBoard)
        {
            leaderBoard.setUpFinalScoreBoards();
            leaderBoard.draw(app);
        }
        
        // screen 
        app.display();
    }

    return 0;
}

