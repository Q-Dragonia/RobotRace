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
 }

void Forward(){
	_delay_ms(10);
	setMotorASpeed(driveSpeedFull + 20); // RIGHT
	setMotorBSpeed(driveSpeedFull + 20); // LEFT
	_delay_ms(10);
}

void turnRight(){
	_delay_ms(10);
	setMotorASpeed(turningSpeed); // RIGHT
	setMotorBSpeed(driveSpeedFull); // LEFT
	_delay_ms(10);
}

void turnRighty(){
	_delay_ms(10);
	setMotorASpeed(Turn); // RIGHT
	setMotorBSpeed(Drive); // LEFT
	_delay_ms(10);
}

void turnHardRight(){
	_delay_ms(10);
	setMotorASpeed(hardTurningSPeed); // RIGHT
	setMotorBSpeed(driveSpeedTruning); // LEFT
	_delay_ms(10);
}

void turnLeft(){
	_delay_ms(10);
	setMotorASpeed(driveSpeedFull); // RIGHT
	setMotorBSpeed(turningSpeed); // LEFT
	_delay_ms(10);
}

void turnLefty(){
	_delay_ms(10);
	setMotorASpeed(Drive); // RIGHT
	setMotorBSpeed(Turn); // LEFT
	_delay_ms(10);
}

void turnHardLeft(){
	_delay_ms(10);
	setMotorASpeed(driveSpeedTruning); // RIGHT
	setMotorBSpeed(hardTurningSPeed); // LEFT
	_delay_ms(10);
}

#endif /* TURNING_H_ */