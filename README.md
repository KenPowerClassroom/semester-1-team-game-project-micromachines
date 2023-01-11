# semester-1-team-game-project-micromachines
semester-1-team-game-project-micromachines created by GitHub Classroom


Joshua Boyce Hyland

-Feature description :
1. Visual checkpoints
    1. change color when you collide with them and stay that color until the end of the lap
    2. can only be activated in the correct order
    3.  colision detection with checkpoints
2. Laps system
    1. when all checkpoints have be passed through in the correct order a lap has been completed
    2. after completing the third lap the laps will stopped being tracker
3. Leaderboard
    1. as every car finishes its thrid lap it will be place on the leaderboard
    2. once all the cars have finished their third lap, the game will end and the leaderboard will be displayed 
 - My test.cpp
 https://github.com/KenPowerClassroom/semester-1-team-game-project-micromachines/blob/master/16_SFML_Games/CarTests/Joshua_Boyce_Hyland.cpp
 - My Refactoring 
    1. Change from car Struct to car Class
    - Car.h
    https://github.com/KenPowerClassroom/semester-1-team-game-project-micromachines/commit/02b809ce5eed4d7f968cd7ce505a35714bbc317e#diff-be020a7b1b7e48da8af55d79eadb2af1288404a14cefe06e9f96c87afec6562a
    - Car.cpp
     https://github.com/KenPowerClassroom/semester-1-team-game-project-micromachines/commit/02b809ce5eed4d7f968cd7ce505a35714bbc317e#diff-d478ec98593051e51b5212366ce6b89e8bb3f5d9484247b19088105292314839
    2 taking car struct from racing.cpp to be converted into car class
     - racing.cpp
     https://github.com/KenPowerClassroom/semester-1-team-game-project-micromachines/commit/02b809ce5eed4d7f968cd7ce505a35714bbc317e#diff-8141c34e21df26242a1d2dc374a191f5c0441672cf69c1850d36206623a82469
   
    3. Class to humble Object 
    
    3. 

Darragh McKernan
Feature description: 
- Traction
    1. Cars maximum speed is 12 while on the track
    2. Cars maximum speed decreases to 6 while off the track
    3. Uses an array of positions and an array of sizes for the rectangles
       that outline the track
    4. Uses 1 rectangle shape and gives it several coordinate 
    inputs to check collisions off of it


Contributions :

- Team
    1. intial refactoring of code ( variable names changes etc)
    2. intial testing (test concepts)
    3. feature ideas

- Joshua Boyce Hyland
    1. car struct to car class
    2. humble object
    3. adapt test to fit humble object 

    


