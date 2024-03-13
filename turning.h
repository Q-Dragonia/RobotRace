/*
 * turning.h
 *
 * Created: 2024-03-08 11:38:46
 *  Author: ARAL0011
 */ 

#ifndef TURNING_H_
#define TURNING_H_

#include "definitions.h"
#include "movement.h"

void move(int averageValue){
	
	if(averageValue < whiteOuterLimit){
		turnHardRight();
	}else if(averageValue < white_limit){
		turnRighty();
	}else if(averageValue < whiteInnerLimit){
		turnRight();
	}else if(averageValue > blackOuterLimit){
		turnHardLeft();
	}else if(averageValue > black_limit){
		turnLefty();
	}else if(averageValue > blackInnerLimit){
		turnLeft();
	}else{Forward();}
	custom_delay_ms(10);
 }

void Forward(){
	setMotorASpeed(driveSpeedFull); // RIGHT
	setMotorBSpeed(driveSpeedFull); // LEFT
}

void turnRight(){
	setMotorASpeed(turningSpeed); // RIGHT
	setMotorBSpeed(regularTruningSpeed); // LEFT
}

void turnRighty(){
	setMotorASpeed(Turn); // RIGHT
	setMotorBSpeed(Drive); // LEFT
}

void turnHardRight(){
	setMotorASpeed(hardTurningSPeed); // RIGHT
	setMotorBSpeed(driveSpeedTruning); // LEFT
}

void turnLeft(){
	setMotorASpeed(regularTruningSpeed); // RIGHT
	setMotorBSpeed(turningSpeed); // LEFT
}

void turnLefty(){
	setMotorASpeed(Drive); // RIGHT
	setMotorBSpeed(Turn); // LEFT
}

void turnHardLeft(){
	setMotorASpeed(driveSpeedTruning); // RIGHT
	setMotorBSpeed(hardTurningSPeed); // LEFT
}

#endif /* TURNING_H_ */