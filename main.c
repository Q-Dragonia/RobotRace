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
	//initCollision();
	//initMovement();
	//initServo();
	
	DDRB |= (1 << 2);
	
	sei();
	
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
			
    }
}

