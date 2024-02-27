/*
 * servo.h
 *
 * Created: 26.02.2024 23:47:15
 *  Author: quinh
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "definitions.h"

void init_servo_PWM() {
	// Set servo pin (OC1A) as output
	DDRB |= (1 << SERVO_PIN);

	// Fast PWM, 8-bit, non-inverted mode
	TCCR1A = (1 << WGM11) | (1 << COM1A1);

	// Fast PWM, prescaler 64
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS11) | (1 << CS10);

	// Set TOP value for 50Hz (20ms) PWM signal
	ICR1 = 2499;  // (F_CPU / (64 * frequency)) - 1

	// Set initial servo position to SERVO_MIN
	OCR1A = SERVO_MIN;

}
static void update_pwm(uint16_t i){
	update_pwm_ready = 1;
	while (update_pwm_ready !=0);
	OCR1AH = (i & 0xFF00)>>8;//set high bits
	OCR1AL = (i & 0x00FF);//set low bits
}

// Function to set servo angle
void servo_set_angle(uint16_t angle,uint16_t max_angle) {
	 // Calculate pulse width
	 float pulse_ms = ((float)angle / (float)max_angle) * (SERVO_MAX_PULSE - SERVO_MIN_PULSE) + SERVO_MIN_PULSE;
	 uint16_t compare_value = (uint16_t)(pulse_ms / 1000.0 * F_CPU / 64);

	 // Limit the compare value to the range of SERVO_MIN to SERVO_MAX
	 if (compare_value < SERVO_MIN) {
		 compare_value = SERVO_MIN;
		 } else if (compare_value > SERVO_MAX) {
		 compare_value = SERVO_MAX;
	 }

	 // Update OCR1A with the calculated compare value
	 OCR1A = compare_value;
}




#endif /* SERVO_H_ */