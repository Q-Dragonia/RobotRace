/*
 * servo.h
 *
 * Created: 26.02.2024 23:47:15
 *  Author: quinh
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "definitions.h"

volatile static uint8_t update_pwm_ready = 0;
void init_servo_PWM() {
	DDRB |= (1 << SERVO_PIN);//set as output
	
	TCCR1A = (0b10 << COM1A0)|(0b00 << COM1B0)|(0b10 << WGM10);//Configure Timer1 for Fast PWM mode, non-inverted output
	
	TIMSK1 = (1 << TOIE1)|(1<<OCIE1A); //set timer1, interrupt on overflow and output compare A
	
	OCR1AH = (SERVO_MIN & 0xFF00)>>8;//higher bits
	OCR1AL = (SERVO_MIN & 0x00FF);//lower bits
	
	ICR1H = (SERVO_PWM_TOP & 0xFF00)>>8;//higher bits
	ICR1L = (SERVO_PWM_TOP & 0x00FF);//lower bits
	
	TCCR1B = (0b11 << WGM12)|(0b010 << CS10);//Prescaler 8
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
	float set = (float) angle/(float) max_angle;//ratio of degrees
	
	set = (((float)SERVO_MAX-(float)SERVO_MIN)*set)+(float)SERVO_MIN;//finds the value for pwm
	
	uint16_t point = (uint16_t) set;
	
	update_pwm(point);
}




#endif /* SERVO_H_ */