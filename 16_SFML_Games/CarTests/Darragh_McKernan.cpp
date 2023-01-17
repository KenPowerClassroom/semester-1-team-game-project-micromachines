#include "pch.h"

#include "../carController.h"
//#include "../carController.cpp"

#include"../lap_logic.h"
//#include"../lap_logic.cpp"

TEST(CarController, Darragh_moveCarBackwards) 
{
	carController car;

	car.setPosition( 0, 0 );
	car.setSpeed(-1);
	car.setAngle(0.5);
	car.inputHandler(false, true, false, false, true);

	int result = static_cast<int>(car.getUpdatedY());

	EXPECT_EQ(result, 1);
}

// test to see once the car has done half a full rotation that it reaches the same Y axi position it started in 
TEST(CarController, Team_Darragh_rotateCar) {


	carController car;
	float startingXpos = 100; 

	car.setPosition(startingXpos,0 );
	car.setSpeed(9);
	car.setAngle(0);

	int times = 0; 
	
	for (int i = 0; i < 80; i++)
	{
		car.inputHandler(true, false, true, false, true);
		car.getUpdatedX();
		car.getUpdatedY();
	}
	
	int result = static_cast<int>(car.getUpdatedX());
	EXPECT_EQ(startingXpos, result);

}

TEST(Traction, Darragh_carOnTrack)
{
	carController car;

	car.setPosition( 300, 500 );
	car.inputHandler(false, false, false, false, true);

	EXPECT_EQ(car.getMaxSpeed(), 12.0);
}

TEST(Traction, Darragh_carOffTrack)
{
	carController car;

	car.setPosition( 300, 500 );
	car.inputHandler(false, false, false, false, false);

	EXPECT_EQ(car.getMaxSpeed(), 6.0);
}
