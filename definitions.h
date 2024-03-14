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

#define A_DIRECTION_PIN PB2 // Right motor direction pin
#define A_SPEED_PIN PD6     // Right motor speed pin
#define B_DIRECTION_PIN PB3 // Left motor direction pin
#define B_SPEED_PIN PD5     // Left motor speed pin


#define TRIG_PIN PINB5   // PB5 for trigger pin
#define ECHO_PIN PINB4   // PB4 for echo pin

#define PWM_TOP 39999    // Period of the PWM signal for the servo (20ms)
#define SERVO_MIN 999    // for 0.5 ms
#define SERVO_MAX 4999   // for 2.5 ms
#define SERVO_PIN PINB1

#define WHITE 480
#define BLACK 770
#define WHITE_PLUS 65	//65
#define BLACK_MINUS 50	//50
#define X 10	//INNER LIMIT 15
#define Y 40	//OUTER LIMIT 15

int driveSpeedFull = 100;	//65
int driveSpeedTruning = 10;	//10
int turningSpeed = 100;	//120
int hardTurningSPeed = 160;	//200
int Turn = 100;	//150
int Drive = 50;	//25
int regularTruningSpeed = 90; //45

int white_limit = WHITE + WHITE_PLUS;
int black_limit = BLACK - BLACK_MINUS;

int whiteOuterLimit = WHITE + WHITE_PLUS - Y;
int whiteInnerLimit = WHITE + WHITE_PLUS + X;
int blackOuterLimit = BLACK - BLACK_MINUS + Y;
int blackInnerLimit = BLACK - BLACK_MINUS - X;

char receivedMessage = '\0';

volatile char rxBuffer[2];
volatile uint8_t rxBufferIndex = 0;

volatile char txBuffer[100];
volatile uint8_t txBufferIndex = 0;

volatile static uint8_t update_pwm_ready = 0;

#endif /* DEFINITIONS_H_ */