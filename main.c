/*
 * RobotRace.c
 *
 * Created: 2024-02-26 21:02:56
 * Author : ARAL0011
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#include "definitions.h"
#include "adc.h"
#include "usart.h"


int main(void)
{
    
	init_ADC();
	init_USART(MYUBRR);
	init_servo_PWM()
	//initCollision();
	//initMovement();
	sei();
	servo_set_angle(0,180);
	int16_t i = 0;
    while (1) 
    {
		int sensorLeft = readADC(SENSOR_LEFT_CHANNEL);
		int lineTrackingSensorLeft = readADC(LINE_TRACKING_SENSOR_LEFT_CHANNEL);
		int lineTrackingSensorMiddle = readADC(LINE_TRACKING_SENSOR_MIDDLE_CHANNEL);
		int lineTrackingSensorRight = readADC(LINE_TRACKING_SENSOR_RIGHT_CHANNEL);
		int sensorRight = readADC(SENSOR_RIGHT_CHANNEL);
		
		// Convert distance to string
		char buffer[80];
		snprintf(buffer, sizeof(buffer), "%d %d %d %d %d \n", sensorLeft, lineTrackingSensorLeft, lineTrackingSensorMiddle, lineTrackingSensorRight, sensorRight);
		
		// Transmit distance over UART
		for (int i = 0; buffer[i] != '\0'; i++) {
			transferMessage(buffer[i]);
		}

		// Delay before next measurement
		_delay_ms(10000);
		//Servo move angle(subject to change)
		for(i = 0; i<=180;i++){
			servo_set_angle(i,180);
			_delay_ms(40);
		}
		for (i=180;i>=0;i--){
			servo_set_angle(i,180);
			_delay_ms(40);
		}
    }
}

