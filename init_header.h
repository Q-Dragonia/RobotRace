/*
 * init_header.h
 *
 * Created: 22.02.2024 03:10:12
 *  Author: quinh
 */ 


#ifndef INIT_HEADER_H_
#define INIT_HEADER_H_

#include <avr/io.h>
#include "deffinition_header.h"

void initMiddleBottomSensor(){
	//Set bottom line tracking sensor as Input
	DDRD &= ~(1 << LEFT_MIDDLE_SENSOR);		// Set Pin for bottom line tracking sensor left part
	DDRD &= ~(1 << MIDDLE_MIDDLE_SENSOR);	// Set Pin for bottom line tracking sensor middle part
	DDRD &= ~(1 << RIGHT_MIDDLE_SENSOR);	// Set Pin for bottom line tracking sensor right part
	
	//Enable internal pull-up resistors for bottom line tracking sensor
	PORTD |= (1 << LEFT_MIDDLE_SENSOR);		//Enable internal pull-up resistor for bottom line tracking sensor left part
	PORTD |= (1 << MIDDLE_MIDDLE_SENSOR);	//Enable internal pull-up resistor for bottom line tracking sensor middle part
	PORTD |= (1 << RIGHT_MIDDLE_SENSOR);	//Enable internal pull-up resistor for bottom line tracking sensor right part
}

void initSideBottomSensor(){
	DDRD &= ~(1 << RIGHT_BOTTOM_SENSOR);	// Set Pin for bottom IR sensor Right
	DDRD &= ~(1 << LEFT_BOTTOM_SENSOR);		// Set Pin for bottom IR sensor Left
	PORTD |= (1 << RIGHT_BOTTOM_SENSOR);	// Enable internal pull-up resistor for bottom IR sensor Right
	PORTD |= (1 << LEFT_BOTTOM_SENSOR);		//Enable internal pull-up resistor for bottom IR sensor Left
}

void initMovementMotors(){
	//Init is here
}

void initCollisionSensor(){
	//Init is here
}


#endif /* INIT_HEADER_H_ */