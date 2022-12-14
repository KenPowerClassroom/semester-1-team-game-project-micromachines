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

		if (car.angle >= expectedAngle)
		{
			break;
		}
	}

	EXPECT_TRUE(car.angle >= expectedAngle);
}

TEST(CarController, findTarget)
{
	Car ai;

	ai.x = 0;
	ai.y = 0;

	const int num = 8; //checkpoints

	bool reachedTarget = false;

	int points[num][2] = { 300, 610,
						  1270,430,
						  1380,2380,
						  1900,2460,
						  1970,1700,
						  2550,1680,
						  2560,3150,
						  500, 3300 };

	for (double i = 0; i < std::numeric_limits<double>::max(); i++)
	{
		ai.move();

		ai.findTarget();

		float tx = points[0][0];
		float ty = points[0][1];

		if ((ai.x - tx) * (ai.x - tx) + (ai.y - ty) * (ai.y - ty) < 25 * 25)
		{
			reachedTarget = true;
			break;
		}
	}

	EXPECT_TRUE(reachedTarget);
}
