#include "pch.h"
#include "../carController.h"
#include "../carController.cpp"
TEST(CarController, moveCarForward) 
{
	carController car;

	car.setPosition({0, 0});
	car.setSpeed(1); 
	car.setAngle(0.5); 
	car.inputHandler(true, false, false, false,true); 

	int result = static_cast<int>(car.getUpdatedPositioning().y);

	EXPECT_EQ(result, -1);
}

TEST(CarController, moveCarBackwards) 
{
	carController car;

	car.setPosition({ 0, 0 });
	car.setSpeed(-1);
	car.setAngle(0.5);
	car.inputHandler(false, true, false, false,true);

	int result = static_cast<int>(car.getUpdatedPositioning().y);

	EXPECT_EQ(result, 1);
}

// test to see once the car has done half a full rotation that it reaches the same Y axi position it started in 
TEST(CarController, rotateCar) {


	carController car;
	float startingXpos = 100; 

	car.setPosition({startingXpos,0 });
	car.setSpeed(9);
	car.setAngle(0);

	int times = 0; 
	
	for (int i = 0; i < 80; i++)
	{
		car.inputHandler(true, false, true, false,true);
		car.getUpdatedPositioning();
	}
	
	int result = static_cast<int>(car.getUpdatedPositioning().x);
	EXPECT_EQ(startingXpos, result);

}

TEST(CarController, findTarget)
{
	carController car;

	car.setPosition({ 300, 634 });
	car.setSpeed(1);
	car.inputHandler(true, false, false, false,true); 

	EXPECT_TRUE(car.foundTarget({ 300,610 })); 
}

TEST(CarController, carOnTrack)
{
	carController car;

	car.setPosition({ 300, 500 });
	car.inputHandler(false, false, false, false, true);

	EXPECT_EQ(car.getMaxSpeed(),12.0);
}

TEST(CarController, carOffTrack)
{
	carController car;

	car.setPosition({ 300, 500 });
	car.inputHandler(false, false, false, false, false);

	EXPECT_EQ(car.getMaxSpeed(), 6.0);
}