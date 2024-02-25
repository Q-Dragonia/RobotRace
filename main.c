/*
 * RobotRace.c
 *
 * Created: 22.02.2024 02:41:31
 * Author : quinh
 */ 

#include <avr/io.h>
#include "bottom_sensor_header.h"
#include "init_header.h"
#include "app.h"


int main(void)
{
	initAll();
	
    /* Replace with your application code */
    while (1) 
    {
		unsigned char received_byte = USART_Receive();
		
		//stay in the loop until start
		while(received_byte == 'C'){
			received_byte = USART_Receive(); //Get next byte to escape the loop
		}
		if(received_byte == 'B'){_delay_ms(5000);}
			
		if(readLeftMiddleSensor() == 1 && readMiddleMiddleSensor()== 1 && readRightMiddleSensor() == 1){ // 1 is black
			PINB |= (1 << RED);
		}else {
			PORTB &= ~(1 << RED);
		}
    }
}