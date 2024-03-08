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
	}else if(averageValue < whiteInnerLimit){
		turnRight();
	}else if(averageValue > blackInnerLimit){
		turnLeft();
	}else if(averageValue > blackOuterLimit){
		turnHardRight();
	}else{Forward();}
}

void Forward(){
	_delay_ms(10);
	setMotorASpeed(driveSpeedFull); // RIGHT
	setMotorBSpeed(driveSpeedFull); // LEFT
	_delay_ms(10);
}

void turnRight(){
	_delay_ms(10);
	setMotorASpeed(turningSpeed); // RIGHT
	setMotorBSpeed(driveSpeedFull); // LEFT
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
	setMotorASpeed(driveSpeedTruning); // RIGHT
	setMotorBSpeed(hardTurningSPeed); // LEFT
	_delay_ms(10);
}

void turnHardLeft(){
	_delay_ms(10);
	setMotorASpeed(driveSpeedTruning); // RIGHT
	setMotorBSpeed(hardTurningSPeed); // LEFT
	_delay_ms(10);
}

#endif /* TURNING_H_ */