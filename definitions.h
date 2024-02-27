/*
 * definitions.h
 *
 * Created: 2024-02-26 21:04:00
 *  Author: ARAL0011
 */ 


#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#define LINE_TRACKING_SENSOR_LEFT_CHANNEL 5
#define LINE_TRACKING_SENSOR_MIDDLE_CHANNEL 2
#define LINE_TRACKING_SENSOR_RIGHT_CHANNEL 1
#define SENSOR_LEFT_CHANNEL 0
#define SENSOR_RIGHT_CHANNEL 3

#define PWM_TOP 39999 // Period of the PWM signal for the servo (20ms)
#define SERVO_MIN 999 //for 0.5 ms
#define SERVO_MAX 4999 //for 2.5 ms
#define SERVO_PIN PINB1
#endif /* DEFINITIONS_H_ */