
#include "pch.h"

#include "../carController.h"
//#include "../carController.cpp"

#include"../lap_logic.h"
//#include"../lap_logic.cpp"

TEST(CarController, Anass_moveCarForward) 
{
	carController car;

	car.setPosition(0, 0);
	car.setSpeed(1); 
	car.setAngle(0.5); 
	car.inputHandler(true, false, false, false, true);

	int result = static_cast<int>(car.getUpdatedY());

	EXPECT_EQ(result, -1);
}

 //test to see once the car has done half a full rotation that it reaches the same Y axi position it started in 
TEST(CarController, Team_Anass_rotateCar) {


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

TEST(PowerUps, Anass_NitroBoost)
{
	carController car;
	float initialSpeed = 12.0f;
	car.setPosition( 0,0 );

	car.activateNitroBoost();

	EXPECT_EQ(car.getSpeed(), 20.0f);
}

TEST(PowerUps, Anass_SlowDownNPC)
{
	carController car;
	float initialSpeed = 12.0f;
	car.setPosition( 0,0 );

	car.activateSlowDown();
	
	EXPECT_TRUE(car.getSpeed() < initialSpeed);
}
