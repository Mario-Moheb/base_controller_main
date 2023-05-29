
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H
#include <Arduino.h>



void initMotors(char rDP1 ,char  rDP2 ,char  rPWM ,char lDP1
,char  lDP2 ,char  lPWM  );

void setRightMotor (int PWM);

void setLeftMotor (int PWM);
#endif
