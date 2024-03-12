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
	
	char var;
	
	setMotorADirection(1);
	setMotorBDirection(1);
	setMotorASpeed(0);
	setMotorBSpeed(0);
	
	sei();
	
  while (1) 
    {
		var = receiveMessage();
		if(var == 'A' || var == 'B' || var == 'C'){receivedMessage = var;}
		
		while(receivedMessage == 'A'){
			int sensorLeft = (int)(readADC(SENSOR_LEFT_CHANNEL) - 30);
			int lineTrackingSensorLeft = (int)readADC(LINE_TRACKING_SENSOR_LEFT_CHANNEL);
			int lineTrackingSensorMiddle = (int)readADC(LINE_TRACKING_SENSOR_MIDDLE_CHANNEL);
			int lineTrackingSensorRight = (int)(readADC(LINE_TRACKING_SENSOR_RIGHT_CHANNEL) - 30);
			int sensorRight = (int)(readADC(SENSOR_RIGHT_CHANNEL) - 20);
			
			int averageValue = (int)((sensorLeft + lineTrackingSensorLeft + lineTrackingSensorMiddle + lineTrackingSensorRight +sensorRight) / 5);
			
			move(averageValue);
			var = receiveMessage();
			if(var == 'B' || var == 'C'){receivedMessage = var;}
		}
		setMotorASpeed(0);
		setMotorBSpeed(0);
		if(receivedMessage == 'B'){
			custom_delay_ms(5000);
			receivedMessage = 'A';
		}
		while(receivedMessage == 'C'){
			var = receiveMessage();
			if(var == 'A' || var == 'B'){receivedMessage =var;}
		}
	}
}
