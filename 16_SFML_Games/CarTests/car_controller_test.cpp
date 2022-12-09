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
	car.y = 0;

	car.speed = 0;
	car.angle = 0;

	float expectedAngle = 3.14;

	float turnSpeed = 0.08;
	float maxSpeed = 12.0;
	float acceleration = 0.2;

	for (double i=0; i<std::numeric_limits<double>::max(); i++)
	{
		if (car.speed < maxSpeed)
		{
			car.speed += acceleration;
		}
		car.angle += turnSpeed * car.speed;
		car.move();

		if (car.angle >= 3.14)
		{
			break;
		}
	}

	EXPECT_TRUE(car.angle >= expectedAngle);
}

