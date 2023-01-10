
#include <iostream>
#include "Car.h"
#include "Laps.h"
#include "LeaderBoard.h"

using namespace sf;


enum GAMESTATE { Gampeplay, ScoreBoard };

void checkIfOnTrack(int t_offsetX,int t_offsetY);
sf::RectangleShape trackOutline;//rectangle used to check if the car is "on" the track
sf::CircleShape playerTracker;//used so global bounds will function
bool playerOnTrack = false;


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


    trackOutline.setSize(sf::Vector2f(200, 5480));
    trackOutline.setOutlineColor(sf::Color::Green);
    trackOutline.setOutlineThickness(5);
    trackOutline.setFillColor(sf::Color::Color(0, 0, 0, 0));

    playerTracker.setRadius(1);


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
            checkIfOnTrack(offsetX, offsetY);
            // movememnt 
            cars[0].steer(playerOnTrack);
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
           // screen

            playerTracker.setPosition(cars[0].getPosition().x - 2, cars[0].getPosition().y - 2);//sets the tracker to the car and centers it
            

            // screen 
            for (int i = 0; i < NUM_OF_CARS; i++)
            {
                cars[i].setPosition({ cars[i].getPosition().x - offsetX, cars[i].getPosition().y - offsetY });
                cars[i].setRotation();
                cars[i].draw(app); 

            }

            // checking for amount of cars that have finished
            for (int i = 0; i < NUM_OF_CARS; i++)
            {
                if (cars[i].getCurrentLap() > 2)
                {
                    carsFinished++;
                    leaderBoard.placeCarOnScoreBoard(i);
                }
            }


            if (carsFinished == NUM_OF_CARS )
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
            app.clear();
            app.draw(sBackground);
            sBackground.setPosition(-offsetX, -offsetY);
            leaderBoard.draw(app);
        }
        // screen 
        app.display();
    }

    return 0;
}

void checkIfOnTrack(int t_offsetX,int t_offsetY)
{
    int trackPieceSize[32] = { 300,5480,  1840,500,  400,500,  650,400,  450,4000,  900,450,  800,800, 800,800,  400,1700,  900,400,  200,3200,  4000,500,  600,500,  500,500,  500,300,  500,400 };
    int trackPiecePositions[32] = { 220,480,  380,330,  390,320,  1950,500,  2200,750,  2600,4700,  2400,2600,  3000,4600,  3300,2900,  3700,2700,  4600,2900,  350,6100,  3700,2700,  4500,3000,  4300,5900, 270,5900 };

    for (int index = 0; index <= 15; index++)
    {

        if (index == 0)//left straight
        {
            trackOutline.setSize(sf::Vector2f(trackPieceSize[index], trackPieceSize[index + 1]));
            trackOutline.setPosition(-t_offsetX + trackPiecePositions[index], -t_offsetY + trackPiecePositions[index + 1]);//holds the track in place using the backgrouds coordinates and offsets it so it matches the track
        }
        if (index > 0)
        {
            trackOutline.setSize(sf::Vector2f(trackPieceSize[index * 2], trackPieceSize[index * 2 + 1]));
            trackOutline.setPosition(sf::Vector2f(-t_offsetX + trackPiecePositions[index * 2], -t_offsetY + trackPiecePositions[index * 2 + 1]));

            if (index == 2 || index == 3 || index == 6 || index == 12 || index == 14)
            {
                trackOutline.setRotation(45);
            }
            if (index == 7 || index == 13 || index == 15)
            {
                trackOutline.setRotation(-45);
            }
        }
        trackOutline.setRotation(0);

        if (trackOutline.getGlobalBounds().intersects(playerTracker.getGlobalBounds()))//used to check if the player is still on the track
        {
            playerOnTrack = true;
            std::cout << "Player is on track\n";
            break;
        }
        else playerOnTrack = false;
    }
}
