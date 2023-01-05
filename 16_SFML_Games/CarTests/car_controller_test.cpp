#include "pch.h"
#include "../carController.h"

TEST(CarController, moveCarForward) 
{
	carController car;

	car.setPosition({0, 0});
	car.setSpeed(1); 
	car.inputHandler(true, false, false, false); 

	EXPECT_EQ(car.getPosition().y, -1);
}

TEST(CarController, moveCarBackwards) 
{
	carController car;

	car.setPosition({ 0, 0 });
	car.setSpeed(1);
	car.inputHandler(true, false, false, false);

	EXPECT_EQ(car.getPosition().y, -1);
}

//TEST(CarController, rotateCar) {
//	Car car;
//
//	car.x = 0;
//	car.y = 0;
//
//	car.speed = 0;
//	car.angle = 0;
//
//	float expectedAngle = 3.14;
//
//	float turnSpeed = 0.08;
//	float maxSpeed = 12.0;
//	float acceleration = 0.2;
//
//	for (double i=0; i<std::numeric_limits<double>::max(); i++)
//	{
//		if (car.speed < maxSpeed)
//		{
//			car.speed += acceleration;
//		}
//		car.angle += turnSpeed * car.speed;
//		car.move();
//
//		if (car.angle >= expectedAngle)
//		{
//			break;
//		}
//	}
//
//	EXPECT_TRUE(car.angle >= expectedAngle);
//}

//TEST(CarController, rotateCar) {
//		/*Car car;
//	
//		car.x = 0;
//		car.y = 0;
//	
//		car.speed = 0;
//		car.angle = 0;
//	
//		float expectedAngle = 3.14;
//	
//		float turnSpeed = 0.08;
//		float maxSpeed = 12.0;
//		float acceleration = 0.2;
//	
//		for (double i=0; i<std::numeric_limits<double>::max(); i++)
//		{
//			if (car.speed < maxSpeed)
//			{
//				car.speed += acceleration;
//			}
//			car.angle += turnSpeed * car.speed;
//			car.move();
//	
//			if (car.angle >= expectedAngle)
//			{
//				break;
//			}
//		}
//	
//		EXPECT_TRUE(car.angle >= expectedAngle);*/
//
//		carController car; 
//
//		car.
//	}

TEST(CarController, findTarget)
{
	carController car;

	car.setPosition({ 300, 616 });
	car.setSpeed(1);
	car.inputHandler(true, false, false, false); 

	EXPECT_TRUE(car.foundTarget({ 300,610 })); 
}
