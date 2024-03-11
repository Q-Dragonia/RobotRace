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

#define PWM_TOP 39999    // Period of the PWM signal for the servo (20ms)
#define SERVO_MIN 999    // for 0.5 ms
#define SERVO_MAX 4999   // for 2.5 ms
#define SERVO_PIN PINB1

#define TRIG_PIN PINB5   // PB5 for trigger pin
#define ECHO_PIN PINB4   // PB4 for echo pin

#define WHITE 350
#define BLACK 750
#define X 30
#define Y 20

int driveSpeedFull = 70;
int driveSpeedTruning = 5;
int turningSpeed = 100;
int hardTurningSPeed = 220;

int white_limit = WHITE + 30;
int black_limit = BLACK - 30;

int whiteOuterLimit = WHITE + 30 - Y;
int whiteInnerLimit = WHITE + 30 + X;
int blackOuterLimit = BLACK - 30 + Y;
int blackInnerLimit = BLACK - 30 - X;

char receivedMessage = '\0';

volatile char rxBuffer[2];
volatile uint8_t rxBufferIndex = 0;

volatile char txBuffer[100];
volatile uint8_t txBufferIndex = 0;

volatile static uint8_t update_pwm_ready = 0;

#endif /* DEFINITIONS_H_ */