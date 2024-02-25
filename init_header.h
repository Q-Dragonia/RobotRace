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

void initAll(){
	initMiddleBottomSensor();

	//initSideBottomSensor();
	initPwmDriving();
}
void initPwmDriving() {
	// Set OC0A (PD6) and OC0B (PD5) as output pins, motor speed pins
	DDRD |= (1 << DDD6) | (1 << DDD5);
	
	// Configure Timer0 for Fast PWM mode, non-inverted output
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	
	// Set prescaler to 64
	TCCR0B |= (1 << CS01)|(1<<CS00);
	
	// Set direction control pins as output
	DDRD |= (1 << A_DIRECTION_PIN) | (1 << B_DIRECTION_PIN);
	
	// Set all direction pins to low initially
	PORTD &= ~((1 << A_DIRECTION_PIN) | (1 << B_DIRECTION_PIN));
	

}
void initMiddleBottomSensor(){
	//Set bottom line tracking sensor as Input
	DDRB &= ~(1 << LEFT_MIDDLE_SENSOR);		// Set Pin for bottom line tracking sensor left part
	DDRD &= ~(1 << MIDDLE_MIDDLE_SENSOR);	// Set Pin for bottom line tracking sensor middle part
	DDRB &= ~(1 << RIGHT_MIDDLE_SENSOR);	// Set Pin for bottom line tracking sensor right part
	
	//Enable internal pull-up resistors for bottom line tracking sensor
	PORTB |= (1 << LEFT_MIDDLE_SENSOR);		//Enable internal pull-up resistor for bottom line tracking sensor left part
	PORTD |= (1 << MIDDLE_MIDDLE_SENSOR);	//Enable internal pull-up resistor for bottom line tracking sensor middle part
	PORTB |= (1 << RIGHT_MIDDLE_SENSOR);	//Enable internal pull-up resistor for bottom line tracking sensor right part
}

void initSideBottomSensor(){
	DDRC &= ~(1 << RIGHT_BOTTOM_SENSOR);	// Set Pin for bottom IR sensor Right
	DDRC &= ~(1 << LEFT_BOTTOM_SENSOR);		// Set Pin for bottom IR sensor Left
	PORTC |= (1 << RIGHT_BOTTOM_SENSOR);	// Enable internal pull-up resistor for bottom IR sensor Right
	PORTC |= (1 << LEFT_BOTTOM_SENSOR);		//Enable internal pull-up resistor for bottom IR sensor Left
}

void LED(){
	DDRB |= (1 << RED);
}

void initCollisionSensor(){
	//Init is here
}


#endif /* INIT_HEADER_H_ */