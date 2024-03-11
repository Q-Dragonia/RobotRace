/*
 * RobotRace.c
 *
 * Created: 2024-02-26 21:02:56
 * Author : ARAL0011
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "definitions.h"
#include "adc.h"
#include "usart.h"
#include "turning.h"

int main(void)
{
    
	init_ADC();
	init_USART(MYUBRR);
 	init_driving_PWM();
	ultrasonic_init();
	pwm_init();
	
	char var;
	
	setMotorADirection(1);
	setMotorBDirection(1);
	setMotorASpeed(0);
	setMotorBSpeed(0);
	
	sei();
	int16_t i = 0;
  while (1) 
    {
		for (i = 45; i <= 135; i++) {
			servo_set_angle(i, 180);
			_delay_ms(100);
			

			// Measure distance
			int distance = measure_distance();

			// Convert distance to string
			char arr[20];
			snprintf(arr, sizeof(arr), "%d \n", distance);

			// Transmit distance over UART
			for (int i = 0; arr[i] != '\0'; i++) {
				USART_Transmit(arr[i]);
			}

			// Delay to control the update rate
			_delay_ms(100);
		}
		for (i = 135; i >= 45; i--) {
			servo_set_angle(i, 180);
			_delay_ms(100);
			

			// Measure distance
			int distance = measure_distance();

			// Convert distance to string
			char arr[20];
			snprintf(arr, sizeof(arr), "%d \n", distance);

			// Transmit distance over UART
			for (int i = 0; arr[i] != '\0'; i++) {
				USART_Transmit(arr[i]);
			}

			// Delay to control the update rate
			_delay_ms(100);
		}
		
		int sensorLeft = (int)(readADC(SENSOR_LEFT_CHANNEL) - 30);
		int lineTrackingSensorLeft = (int)readADC(LINE_TRACKING_SENSOR_LEFT_CHANNEL);
		int lineTrackingSensorMiddle = (int)readADC(LINE_TRACKING_SENSOR_MIDDLE_CHANNEL);
		int lineTrackingSensorRight = (int)(readADC(LINE_TRACKING_SENSOR_RIGHT_CHANNEL) - 30);
		int sensorRight = (int)(readADC(SENSOR_RIGHT_CHANNEL) - 20);
		
		int averageValue = (sensorLeft + lineTrackingSensorLeft + lineTrackingSensorMiddle + lineTrackingSensorRight +sensorRight) / 5;
		
		custom_delay_ms(20);
		
		move(averageValue);
		
		// Convert distance to string
// 		char buffer[80];
// 		snprintf(buffer, sizeof(buffer), "%d %d %d %d %d \n", sensorLeft, lineTrackingSensorLeft, lineTrackingSensorMiddle, lineTrackingSensorRight, sensorRight);
// 				
// 		// Transmit distance over UART
// 		for (int i = 0; buffer[i] != '\0'; i++) {
// 			transferMessage(buffer[i]);
// 		}
// 		_delay_ms(20);
		// Delay before next measurement
		var = receiveMessage();
		if(var != '\0'){receivedMessage = var;}
		
		_delay_ms(20);
		if(receivedMessage == 'A'){
			transferMessage(receivedMessage);
		}else if(receivedMessage == 'B'){
			setMotorASpeed(0);
			setMotorBSpeed(0);
			custom_delay_ms(5000);
			receivedMessage = 'A';
		}else if(receivedMessage == 'C'){
			setMotorASpeed(0);
			setMotorBSpeed(0);
		}//else{transferMessage('D');}
		//example driving, subject to change
    }
}
