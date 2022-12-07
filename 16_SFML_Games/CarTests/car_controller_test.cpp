#include "pch.h"
#include "../Car.h"

TEST(CarController, moveCarForward) {
	Car car;
	
	car.x = 1; 
	car.y = 1;

	car.speed = 1;
	car.angle = 0;
	
	car.move();
	
	EXPECT_EQ(1, car.x);
	EXPECT_EQ(0, car.y);
}

TEST(CarController, moveCarBackwards) {
	Car car;

	car.x = 0;
	car.y = 1;

	car.speed = -1;
	car.angle = 0;

	car.move();

	EXPECT_EQ(0, car.x);
	EXPECT_EQ(2, car.y);
}

TEST(CarController, rotateCar) {
	Car car;

	car.x = 0;
	car.y = 1;

	float oldX = car.x;
	float oldY = car.y;

	car.speed = 10;
	car.angle = 0;

	float turnSpeed = 0.08;

	while (car.angle < 3.141592653*2)
	{
		car.angle += turnSpeed * car.speed;
		car.move();
	}

	EXPECT_EQ(oldY, car.y);
	EXPECT_EQ(oldX, car.x);
}

