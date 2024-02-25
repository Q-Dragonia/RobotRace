/*
 * movement.h
 *
 * Created: 22.02.2024 18:39:29
 *  Author: quinh
 */ 


#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include <avr/io.h>
#include "init_header.h"
#include "deffinition_header.h"

// Function to set speed of a motor
void setMotorASpeed(uint8_t speed) {
	OCR0B = speed; // Set PWM duty cycle
}

// Function to set speed of motor B
void setMotorBSpeed(uint8_t speed) {
	OCR0A = speed; // Set PWM duty cycle
}

// Function to control direction of motor A
void setMotorADirection(uint8_t direction) {
	if (direction == 1) { // Forward
		PORTD |= (1 << A_DIRECTION_PIN); // Set A_DIRECTION_PIN
		} else { // Reverse
		PORTD &= ~(1 << A_DIRECTION_PIN); // Clear A_DIRECTION_PIN
	}
}

// Function to control direction of motor B
void setMotorBDirection(uint8_t direction) {
	if (direction == 1) { // Forward
		PORTD |= (1 << B_DIRECTION_PIN); // Set B_DIRECTION_PIN
		} else { // Reverse
		PORTD &= ~(1 << B_DIRECTION_PIN); // Clear B_DIRECTION_PIN
	}
}




#endif /* MOVEMENT_H_ */