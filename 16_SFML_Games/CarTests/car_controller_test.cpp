#include "pch.h"

#include <SFML/Graphics.hpp>

#include "../Car.h"

#include "../carController.cpp"

#include "../Laps.h"




TEST(CarController, moveCarForward) 
{
	carController car;

	car.setPosition({0, 0});
	car.setSpeed(1); 
	car.setAngle(0.5); 
	car.inputHandler(true, false, false, false); 

	int result = static_cast<int>(car.getUpdatedPositioning().y);

	EXPECT_EQ(result, -1);
}

TEST(CarController, moveCarBackwards) 
{
	carController car;

	car.setPosition({ 0, 0 });
	car.setSpeed(-1);
	car.setAngle(0.5);
	car.inputHandler(false, true, false, false);

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
		car.inputHandler(true, false, true, false);
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
	car.inputHandler(true, false, false, false); 

	EXPECT_TRUE(car.foundTarget({ 300,610 })); 
}

//TEST(Laps, checkPointColorChange)
//{
//	
//	bool testPassed{ false }; 
//	
//	Laps lap;
//	/*newCar car({2,2},2);*/
//
//	EXPECT_TRUE(testPassed); 
//
//	
//}
