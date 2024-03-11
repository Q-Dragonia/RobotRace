/*
 * servo.h
 *
 * Created: 26.02.2024 23:47:15
 *  Author: quinh
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "definitions.h"

void pwm_init() {
	DDRB |= (1 << SERVO_PIN); // Set as output

	TCCR1A = (0b10 << COM1A0) | (0b00 << COM1B0) | (0b10 << WGM10); // Configure Timer1 for Fast PWM mode, non-inverted output
	TCCR1B = (0b11 << WGM12) | (0b010 << CS10); // Prescaler 8

	ICR1 = PWM_TOP; // Set TOP value for Timer1
}

void update_pwm(uint16_t i) {
	OCR1A = i; // Set PWM duty cycle
}
// Function to set servo angle
void servo_set_angle(uint16_t angle, uint16_t max_angle) {
	// Calculate pulse width
	float set = (float)angle / (float)max_angle; // Ratio of degrees
	set = (((float)SERVO_MAX - (float)SERVO_MIN) * set) + (float)SERVO_MIN; // Find the value for PWM
	uint16_t point = (uint16_t)set;
	update_pwm(point);
}




#endif /* SERVO_H_ */