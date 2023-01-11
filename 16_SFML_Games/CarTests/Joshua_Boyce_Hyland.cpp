#include "pch.h"

#include "../carController.h"
#include "../carController.cpp"

#include"../lap_logic.h"
#include"../lap_logic.cpp"

 //test to see once the car has done half a full rotation that it reaches the same Y axi position it started in 
TEST(CarController, Team_Josh_rotateCar) {


	carController car;
	float startingXpos = 100; 

	car.setPosition({startingXpos,0 });
	car.setSpeed(9);
	car.setAngle(0);

	int times = 0; 
	
	for (int i = 0; i < 80; i++)
	{
		car.inputHandler(true, false, true, false, true);
		car.getUpdatedPositioning();
	}
	
	int result = static_cast<int>(car.getUpdatedPositioning().x);
	EXPECT_EQ(startingXpos, result);

}

TEST(CarController, Josh_findTarget)
{
	carController car;

	car.setPosition({ 300, 634 });
	car.setSpeed(1);
	car.inputHandler(true, false, false, false, true);

	EXPECT_TRUE(car.foundTarget({ 300,610 })); 
}

TEST(LapsLogicController, Josh_lcarActivatesCheckpoints)
{
	LapsLogicController lap;
	carController car;
	int checkPoint = 0;

	// setting car position just before checkpoint
	car.setPosition({ 338, 836 });
	car.setSpeed(7);
	car.inputHandler(true, false, false, false, true);
	car.getUpdatedPositioning();
	
	
	EXPECT_TRUE(lap.collisionCheck(car.getPosition().x, car.getPosition().y, checkPoint, car.getCurrentCHeckPoint()));
}


TEST(LapsLogicController, Josh_lcarCantSkipCheckPoint)
{
	LapsLogicController lap;
	carController car;

	int validNextChecpoint = 0; 
	int inavlidNextCheckpoint = 1;
	

	// just before second checkpoint
	car.setPosition({ 1370,658 });
	car.setSpeed(7);
	car.inputHandler(true, false, false, false, true);
	car.getUpdatedPositioning();

	EXPECT_FALSE(lap.collisionCheck(car.getPosition().x, car.getPosition().y, inavlidNextCheckpoint, car.getCurrentCHeckPoint()));
	
	// just before first checkpoint
	car.setPosition({ 338, 836 });
	car.setSpeed(7);
	car.inputHandler(true, false, false, false, true);
	car.getUpdatedPositioning();

	EXPECT_TRUE(lap.collisionCheck(car.getPosition().x, car.getPosition().y, validNextChecpoint, car.getCurrentCHeckPoint()));
}

TEST(LapsLogicController, Josh_lapsCompleteWhenLastCheckpointIsPassed)
{
	LapsLogicController lap; 
	carController car; 
	int NUM_OF_CHECKPOINTS = 8;
	car.setSpeed(1);
	
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		// + 10 to ensure they are in the circle
		car.setPosition({ lap.getCheckpointX(i) + 50, lap.getCheckPointY(i) +50 });
		car.inputHandler(true, false, false, false, true);
		car.getUpdatedPositioning();
		lap.collisionCheck(car.getPosition().x, car.getPosition().y, i, car.getCurrentCHeckPoint());
	}
	lap.allcheckPointsPassed(car.getCurrentCHeckPoint(), car.getCurrentLap());

	EXPECT_EQ(car.getCurrentLap(), 1); 
}
