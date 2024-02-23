/*
 * RobotRace.c
 *
 * Created: 22.02.2024 02:41:31
 * Author : quinh
 */ 

#include <avr/io.h>
#include "bottom_sensor_header.h"


int main(void)
{
	initAll();
	
    /* Replace with your application code */
    while (1) 
    {
		if(LEFT_BOTTOM_SENSOR == 1){
			//Code here
		}
		if(RIGHT_BOTTOM_SENSOR == 1){
			//Code here
		}
    }
}

