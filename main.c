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
#include "movement.h"

int main(void)
{
    
	init_ADC();
	init_USART(MYUBRR);
	init_driving_PWM();
	init_servo_PWM();
	
	DDRB |= (1 << 2);
	
	sei();
	servo_set_angle(0,180);
	int16_t i = 0;
	DDRD |= (1 << A_DIRECTION_PIN) | (1 << B_DIRECTION_PIN); //set direction pins as output
  while (1) 
    {
		
		int sensorLeft = readADC(SENSOR_LEFT_CHANNEL);
		int lineTrackingSensorLeft = readADC(LINE_TRACKING_SENSOR_LEFT_CHANNEL);
		int lineTrackingSensorMiddle = readADC(LINE_TRACKING_SENSOR_MIDDLE_CHANNEL);
		int lineTrackingSensorRight = readADC(LINE_TRACKING_SENSOR_RIGHT_CHANNEL);
		int sensorRight = readADC(SENSOR_RIGHT_CHANNEL);
		
		// Convert distance to string
// 		char buffer[80];
// 		snprintf(buffer, sizeof(buffer), "%d %d %d %d %d \n", sensorLeft, lineTrackingSensorLeft, lineTrackingSensorMiddle, lineTrackingSensorRight, sensorRight);
// 		
// 		// Transmit distance over UART
// 		for (int i = 0; buffer[i] != '\0'; i++) {
// 			transferMessage(buffer[i]);
// 		}

		// Delay before next measurement
		
		char receivedMessage = receiveMessage();
		
		_delay_ms(100);
		if(receivedMessage == 'A'){
			PORTB |= (1 << 2);
			receivedMessage = '\n';
		}else if(receivedMessage == 'B'){
			PORTB &= ~(1 << 2);
			custom_delay_ms(5000);
			PORTB |= (1 << 2);
			receivedMessage = '\n';
		}else if(receivedMessage == 'C'){
			PORTB &= ~(1 << 2);
			receivedMessage = '\n';
		}else if(receivedMessage == '\0'){
// 			transferMessage('I');
// 			transferMessage(' ');
// 			transferMessage('A');
// 			transferMessage('M');
// 			transferMessage(' ');
// 			transferMessage('R');
// 			transferMessage('E');
// 			transferMessage('A');
// 			transferMessage('D');
// 			transferMessage('Y');
		}else{
			transferMessage('E');
			transferMessage('R');
			transferMessage('R');
			transferMessage('O');
			transferMessage('R');
		}

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
		//example driving, subject to change
		setMotorADirection(1);
		setMotorASpeed(90);
		setMotorBDirection(1);
		setMotorBSpeed(90);
		_delay_ms(2000);
		setMotorASpeed(0);
		setMotorBSpeed(0);
		_delay_ms(2000);
    }
}

