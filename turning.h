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
	setMotorBSpeed(driveSpeedFull * multi); // LEFT
	custom_delay_ms(10);
}

void turnRight(){
	setMotorASpeed(turningSpeed); // RIGHT
	setMotorBSpeed(regularTruningSpeed * multi); // LEFT
	custom_delay_ms(10);
}

void turnRighty(){
	setMotorASpeed(Turn); // RIGHT
	setMotorBSpeed(Drive * multi); // LEFT
	custom_delay_ms(10);
}

void turnHardRight(){
	setMotorASpeed(hardTurningSPeed); // RIGHT
	setMotorBSpeed(driveSpeedTruning * multi); // LEFT
	custom_delay_ms(10);
}

void turnLeft(){
	setMotorASpeed(regularTruningSpeed); // RIGHT
	setMotorBSpeed(turningSpeed * multi); // LEFT
	custom_delay_ms(10);
}

void turnLefty(){
	setMotorASpeed(Drive * multi); // RIGHT
	setMotorBSpeed(Turn * multi); // LEFT
	custom_delay_ms(10);
}

void turnHardLeft(){
	setMotorASpeed(driveSpeedTruning * multi); // RIGHT
	setMotorBSpeed(hardTurningSPeed * multi); // LEFT
	custom_delay_ms(10);
}

#endif /* TURNING_H_ */