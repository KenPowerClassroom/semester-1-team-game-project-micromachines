
#include <iostream>
#include "Car.h"
using namespace sf;

//void test(Car car)
//{
//    if (car.speed < maxSpeed)
//    {
//        car.speed += acceleration;
//    }
//    car.angle += turnSpeed * car.speed;
//    car.move();
//
//    if (car.angle >= 3.141592653f)
//    {
//        std::cout << "speed : " << car.speed << "\n";
//        std::cout << "angle : " << car.angle << "\n";
//    }
//    else
//    {
//        std::cout << "test passed!\n";
//    }
//}

int racing()
{
    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile("images/racing/background.png");
    t2.loadFromFile("images/racing/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite sBackground(t1), sCar(t2);
    sBackground.scale(2,2);

    sCar.setOrigin(22, 22);
    float carRadius=22;

    const int numOfCars=5;
    Car car[numOfCars];

    for(int i=0;i<numOfCars;i++)
    {
      car[i].x=300+i*50;
      car[i].y=1700+i*80;
      car[i].speed=7+i;
    }

   float speed=0,angle=0;
   float maxSpeed=12.0;
   float acceleration=0.2, deceleration=0.3;
   float turnSpeed=0.08;

   int offsetX=0,offsetY=0;

   float minScreenWidth = 320;
   float minScreenHeight = 240;
   float maxScreenWidth = 2500;
   float maxScreenHeight = 3400;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    bool Up=0,Right=0,Down=0,Left=0;
    if (Keyboard::isKeyPressed(Keyboard::Up)) Up=1;
    if (Keyboard::isKeyPressed(Keyboard::Right)) Right=1;
    if (Keyboard::isKeyPressed(Keyboard::Down)) Down=1;
    if (Keyboard::isKeyPressed(Keyboard::Left)) Left=1;

    //test(car[0]);

    if (car[0].angle <= 3.141592653f)
    {
        /*std::cout << "speed : " << car[0].speed << "\n";
        std::cout << "angle : " << car[0].angle << "\n";*/
    }
    else
    {
        std::cout << "test passed!\n";
        car[0].angle = 0;
    }

    //car movement
    if (Up && speed < maxSpeed)
    {
        if (speed < 0)
        {
            speed += deceleration;
        }
        else
        {
            speed += acceleration;
        }
    }
        

    if (Down && speed > -maxSpeed)
    {
        if (speed > 0)
        {
            speed -= deceleration;
        }
        else
        {
            speed -= acceleration;
        }
    }
        

    if (!Up && !Down)
    {
        if (speed - deceleration > 0)
        {
            speed -= deceleration;
        }
        else if (speed + deceleration < 0)
        {
            speed += deceleration;
        }
        else
        {
            speed = 0;
        }
    }
        

    if (Right && speed != 0)
    {
        angle += turnSpeed * speed / maxSpeed;
    }
    if (Left && speed != 0)
    {
        angle -= turnSpeed * speed / maxSpeed;
    }

    car[0].speed = speed;
    car[0].angle = angle;

    for (int i = 0; i < numOfCars; i++)
    {
        car[i].move();
    }

    for (int i = 1; i < numOfCars; i++)
    {
        car[i].findTarget();
    }
    //collision
    for(int collisionCheck=0;collisionCheck<numOfCars;collisionCheck++)
    { 
        for(int checkAgainst=0;checkAgainst<numOfCars;checkAgainst++)
        {      
            const int CAR_HITBOX = 4 * carRadius * carRadius;
            int distanceBetweenX=0, distanceBetweenY=0;

            // if the distance between the cars is lesser than the radisu 
            while (distanceBetweenX * distanceBetweenX + distanceBetweenY * distanceBetweenY < CAR_HITBOX )
            {
                // pushes car to the side by a tenth of the distance between the cars 
               car[collisionCheck].x+=distanceBetweenX/10.0;
               car[collisionCheck].x+=distanceBetweenY/10.0;
               car[checkAgainst].x-=distanceBetweenX/10.0;
               car[checkAgainst].y-=distanceBetweenY/10.0;
           
               distanceBetweenX = car[collisionCheck].x - car[checkAgainst].x;
               distanceBetweenY = car[collisionCheck].y - car[checkAgainst].y;
                
    
               // if the cars are touching 
               if(distanceBetweenX == 0 && distanceBetweenY == 0)
               {
                    break;
               }
               
            }
        }
    }

    app.clear(Color::Black);

    // Border locking X
    if (car[0].x > minScreenWidth && car[0].x < maxScreenWidth)
    {
        offsetX = car[0].x - minScreenWidth;
    }

    // Border locking Y
    if (car[0].y > minScreenHeight && car[0].y < maxScreenHeight)
    {
        offsetY = car[0].y - minScreenHeight;
    }

    std::cout << "x: " << car[0].x << " y: " << car[0].y << "\n";
    sBackground.setPosition(-offsetX, -offsetY);

    app.draw(sBackground);

    Color colors[10] = {Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White};

    for(int i=0;i<numOfCars;i++)
    {
      sCar.setPosition(car[i].x-offsetX,car[i].y-offsetY);
      sCar.setRotation(car[i].angle*180/3.141593);
      sCar.setColor(colors[i]);
      app.draw(sCar);
    }

    app.display();
    }

    return 0;
}
