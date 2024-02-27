/*
 * movement.h
 *
 * Created: 26.02.2024 23:47:46
 *  Author: quinh
 */ 


#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "definitions.h"

void init_driving_PWM() {
	// Set OC0A (PD6) and OC0B (PD5) as output pins, motor speed pins
	DDRD |= (1 << DDD6) | (1 << DDD5);
	// Configure Timer0 for Fast PWM mode, non-inverted output (WGM02:0 = 3)
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	//TCCR0B |= (1 << WGM02);

	// Set prescaler to 64
	TCCR0B |= (1 << CS01) | (1 << CS00);
}

// Function to set speed of motor A
void setMotorASpeed(uint8_t speed) {
	if (speed == 0) {
		OCR0B = 0; // Turn off PWM output
		} else {
		OCR0B = speed; // Set PWM duty cycle
	}
}

// Function to set speed of motor B
void setMotorBSpeed(uint8_t speed) {
	if (speed == 0) {
		OCR0A = 0; // Turn off PWM output
		} else {
		OCR0A = speed; // Set PWM duty cycle
	}
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