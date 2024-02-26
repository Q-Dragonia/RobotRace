/*
 * RobotRace.c
 *
 * Created: 22.02.2024 02:41:31
 * Author : quinh
 */ 

#include <avr/io.h>
#include "bottom_sensor_header.h"
#include "init_header.h"
#include "movement.h"


int main(void)
{
	initAll();
	
    /* Replace with your application code */
    while (1) 
    {
		if(readLeftMiddleSensor() == 1 && readMiddleMiddleSensor()== 1 && readRightMiddleSensor() == 1 && readLeftBottomSensor() == 1 && readRightBottomSensor() == 1){ // 1 is black
			PINB |= (1 << RED);
			//setMotorASpeed(255);
			//setMotorBSpeed(255);
			//setMotorADirection(1);
			//setMotorBDirection(1);
		}
		if(readRightBottomSensor() == 0){
			if(readRightMiddleSensor() == 0){
				//Only one of these two
				//setMotorASpeed(150);
				//setMotorBSpeed(150);
			}else{
				//Only one of these two
				//setMotorASpeed(200);
				//setMotorBSpeed(200);
			}
		}
		if(readLeftBottomSensor() == 0){
			if(readLeftMiddleSensor() == 0){
				//Only one of these two
				//setMotorASpeed(150);
				//setMotorBSpeed(150);
				}else{
				//Only one of these two
				//setMotorASpeed(200);
				//setMotorBSpeed(200);
			}
		}
		//Collision Sensor Part
    }
}
