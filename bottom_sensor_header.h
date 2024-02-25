/*
 * bottom_sensor_header.h
 *
 * Created: 22.02.2024 02:49:30
 *  Author: quinh
 */ 


#ifndef BOTTOM_SENSOR_HEADER_H_
#define BOTTOM_SENSOR_HEADER_H_

#include <avr/io.h>
#include "deffinition_header.h"

uint8_t readLeftMiddleSensor(){
	return (PINB & (1 << LEFT_MIDDLE_SENSOR)) ? 1 : 0;
}
uint8_t readMiddleMiddleSensor(){
	return (PIND & (1 << MIDDLE_MIDDLE_SENSOR)) ? 1 : 0;
}
uint8_t readRightMiddleSensor(){
	return (PINB & (1 << RIGHT_MIDDLE_SENSOR)) ? 1 : 0;
}
uint8_t readLeftBottomSensor(){
	return (PINC & (1 << LEFT_BOTTOM_SENSOR)) ? 1 : 0;
}
uint8_t readRightBottomSensor(){
	return (PINC & (1 << RIGHT_BOTTOM_SENSOR)) ? 1 : 0;
}


#endif /* BOTTOM_SENSOR_HEADER_H_ */