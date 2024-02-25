/*
 * deffinition_header.h
 *
 * Created: 22.02.2024 03:12:02
 *  Author: quinh
 */ 


#ifndef DEFFINITION_HEADER_H_
#define DEFFINITION_HEADER_H_
//definitions for driving
#define PWM_MAX 255       // Maximum PWM value
#define A_DIRECTION_PIN PD2 //right motors
#define A_SPEED_PIN PD6 //right motors
#define B_DIRECTION_PIN PD4 //left motors
#define B_SPEED_PIN PD5 //left motors
//Pin definitions for line tracking Sensor
#define LEFT_MIDDLE_SENSOR 3
#define MIDDLE_MIDDLE_SENSOR 7
#define RIGHT_MIDDLE_SENSOR 0

//Pin definitions for IR sensor on the bottom- left and right side.
#define LEFT_BOTTOM_SENSOR 7
#define RIGHT_BOTTOM_SENSOR 7

//LED
#define RED 2

//Pin definitions for wheel motors


//Pin definitions for Collision sensor


#endif /* DEFFINITION_HEADER_H_ */