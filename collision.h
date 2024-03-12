/*
 * collision.h
 *
 * Created: 26.02.2024 23:48:06
 *  Author: quinh
 */ 


#ifndef COLLISION_H_
#define COLLISION_H_

#include "servo.h"
#include "usart.h"

void ultrasonic_init() {
	// Set trigger pin as output and echo pin as input for ultrasonic sensor
	DDRB |= (1 << TRIG_PIN); // Trigger pin as output
	DDRB &= ~(1 << ECHO_PIN); // Echo pin as input
}
void timer1_init(){
	TCCR1A = 0;
	TCCR1B |= (0b010<<CS10);
	
}
int measure_distance() {
	// Send a 10us pulse to the ultrasonic sensor
	PORTB |= (1 << TRIG_PIN);
	_delay_us(10);
	PORTB &= ~(1 << TRIG_PIN);

	// Measure pulse duration
	while (!(PINB & (1 << ECHO_PIN))); // Wait for echo pin to go high
	TCNT1 = 0; // Record start time
	while (PINB & (1 << ECHO_PIN)); // Wait for echo pin to go low
	int time = TCNT1/2;

	// Calculate distance in cm
	int distance = (int)(time / 29);

	return distance;
}



#endif /* COLLISION_H_ */