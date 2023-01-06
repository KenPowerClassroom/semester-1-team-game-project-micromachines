
#include <iostream>
#include "Car.h"
using namespace sf;



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
   
    int i = 0;
    
    sBackground.scale(2, 2);
    
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

    sf::RectangleShape trackOutline;//rectangle used to check if the car is "on" the track
    trackOutline.setSize(sf::Vector2f(200, 5480));
    trackOutline.setOutlineColor(sf::Color::Green);
    trackOutline.setOutlineThickness(5);
    trackOutline.setFillColor(sf::Color::Color(0, 0, 0, 0));

    sf::CircleShape playerTracker;//used so global bounds will function
    playerTracker.setRadius(1);

    bool playerOnTrack = false;

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
        cars[0].steer(playerOnTrack);//now sends over if the car is on the track
       

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

        playerTracker.setPosition(cars[0].getPosition().x + 22, cars[0].getPosition().y + 22);//sets the tracker to the car and centers it


        if (trackOutline.getGlobalBounds().intersects(playerTracker.getGlobalBounds()))//used to check if the player is still on the track
        {
            playerOnTrack = true;
            std::cout << "Player is on track\n";
        }
        else playerOnTrack = false;

        //std::cout << "x: " << cars[0].getPosition().x << " y: " << cars[0].getPosition().y << "\n";
        sBackground.setPosition(-offsetX, -offsetY);
        trackOutline.setPosition(-offsetX + 220, -offsetY + 480);//holds the track in place using the backgrouds coordinates and offsets it so it matches the track

        app.draw(sBackground);
        app.draw(trackOutline);

        Color colors[10] = { Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White };

        // screen 
        for (int i = 0; i < numOfCars; i++)
        {
            cars[i].setPosition({ cars[i].getPosition().x - offsetX, cars[i].getPosition().y - offsetY });
            cars[i].setRotation();
            cars[i].draw(app); 

        }

        if (cars[0].getPosition().x <290)
        {
            i;
            //break;
        }
        else
        {
            i++;
        }
        // screen 
        app.display();
    }

    return 0;












   // RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
   // app.setFramerateLimit(60);


   // // visual set up for cars 
   // Texture t1,t2,t3;
   // t1.loadFromFile("images/racing/background.png");
   // t2.loadFromFile("images/racing/car.png");
   // t1.setSmooth(true);
   // t2.setSmooth(true);

   // Sprite sBackground(t1), sCar(t2);
   // sBackground.scale(2,2);
   // sCar.setOrigin(22, 22);
   // // visual set up for cars 




   // float carRadius=22;
   // const int numOfCars=5;
   // Car car[numOfCars];


   // // car startPositioning 
   // for(int i=0;i<numOfCars;i++)
   // {
   //   car[i].x=300+i*50;
   //   car[i].y=1700+i*80;
   //   car[i].speed=7+i;
   // }
   // // car startPositioning 


   //// variables for movement 
   //float speed=0,angle=0;
   //float maxSpeed=12.0;
   //float acceleration=0.2, deceleration=0.3;
   //float turnSpeed=0.08;
   //// variables for movement 
  

   //// screen 
   //int offsetX=0,offsetY=0;
   //float minScreenWidth = 320;
   //float minScreenHeight = 240;
   //float maxScreenWidth = 2500;
   //float maxScreenHeight = 3400;
   //// screen 



   //// game loop 
   // while (app.isOpen())
   // {
   //     Event e;
   //     while (app.pollEvent(e))
   //     {
   //         if (e.type == Event::Closed)
   //             app.close();
   //     }

   // // movememnt 
   // bool Up=0,Right=0,Down=0,Left=0;
   // if (Keyboard::isKeyPressed(Keyboard::Up)) Up=1;
   // if (Keyboard::isKeyPressed(Keyboard::Right)) Right=1;
   // if (Keyboard::isKeyPressed(Keyboard::Down)) Down=1;
   // if (Keyboard::isKeyPressed(Keyboard::Left)) Left=1;
   // // movement 

   //

   // // speed management  
   // if (Up && speed < maxSpeed)
   // {
   //     if (speed < 0)
   //     {
   //         speed += deceleration;
   //     }
   //     else
   //     {
   //         speed += acceleration;
   //     }
   // }
 

   // if (Down && speed > -maxSpeed)
   // {
   //     if (speed > 0)
   //     {
   //         speed -= deceleration;
   //     }
   //     else
   //     {
   //         speed -= acceleration;
   //     }
   // }
   //     

   // if (!Up && !Down)
   // {
   //     if (speed - deceleration > 0)
   //     {
   //         speed -= deceleration;
   //     }
   //     else if (speed + deceleration < 0)
   //     {
   //         speed += deceleration;
   //     }
   //     else
   //     {
   //         speed = 0;
   //     }
   // }
   // if (Right && speed != 0)
   // {
   //     angle += turnSpeed * speed / maxSpeed;
   // }
   // if (Left && speed != 0)
   // {
   //     angle -= turnSpeed * speed / maxSpeed;
   // }

   // car[0].speed = speed;
   // car[0].angle = angle;

   // for (int i = 0; i < numOfCars; i++)
   // {
   //     car[i].move();
   // }
   // // speed management  

   // for (int i = 1; i < numOfCars; i++)
   // {
   //     car[i].findTarget();
   // }


   // //collision
   // for(int collisionCheck=0;collisionCheck<numOfCars;collisionCheck++)
   // { 
   //     for(int checkAgainst=0;checkAgainst<numOfCars;checkAgainst++)
   //     {      
   //         const int CAR_HITBOX = 4 * carRadius * carRadius;
   //         int distanceBetweenX=0, distanceBetweenY=0;

   //         // if the distance between the cars is lesser than the radisu 
   //         while (distanceBetweenX * distanceBetweenX + distanceBetweenY * distanceBetweenY < CAR_HITBOX )
   //         {
   //             // pushes car to the side by a tenth of the distance between the cars 
   //            car[collisionCheck].x+=distanceBetweenX/10.0;
   //            car[collisionCheck].x+=distanceBetweenY/10.0;
   //            car[checkAgainst].x-=distanceBetweenX/10.0;
   //            car[checkAgainst].y-=distanceBetweenY/10.0;
   //        
   //            distanceBetweenX = car[collisionCheck].x - car[checkAgainst].x;
   //            distanceBetweenY = car[collisionCheck].y - car[checkAgainst].y;
   //             
   // 
   //            // if the cars are touching 
   //            if(distanceBetweenX == 0 && distanceBetweenY == 0)
   //            {
   //                 break;
   //            }
   //            
   //         }
   //     }
   // }
   // //collision


   // app.clear(Color::Black);

   // // Border locking X
   // if (car[0].x > minScreenWidth && car[0].x < maxScreenWidth)
   // {
   //     offsetX = car[0].x - minScreenWidth;
   // }

   // // Border locking Y
   // if (car[0].y > minScreenHeight && car[0].y < maxScreenHeight)
   // {
   //     offsetY = car[0].y - minScreenHeight;
   // }

   // std::cout << "x: " << car[0].x << " y: " << car[0].y << "\n";
   // sBackground.setPosition(-offsetX, -offsetY);

   // app.draw(sBackground);

   // Color colors[10] = {Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White};

   // // screen 
   // for(int i=0;i<numOfCars;i++)
   // {
   //   sCar.setPosition(car[i].x-offsetX,car[i].y-offsetY);
   //   sCar.setRotation(car[i].angle*180/3.141593);
   //   sCar.setColor(colors[i]);
   //   app.draw(sCar);
   // }
   // // screen 
   // app.display();
   // }

   // return 0;
}
