#include "motor_control.h"
char rMotorDPin1 , rMotorDPin2 ,rMotorPWMPin, lMotorDPin1
, lMotorDPin2 , lMotorPWMPin ;
void initMotors(char rDP1 ,char  rDP2 ,char  rPWM ,char lDP1
,char  lDP2 ,char  lPWM  ){
  rMotorDPin1 = rDP1 ;
  rMotorDPin2 = rDP2 ;
  rMotorPWMPin = rPWM ;
  lMotorDPin1 = lDP1 ;
  lMotorDPin2 = lDP2 ;
  lMotorPWMPin = lPWM ;

pinMode(rMotorDPin1,OUTPUT);
pinMode(rMotorDPin2,OUTPUT);
pinMode(rMotorPWMPin,OUTPUT);
pinMode(lMotorDPin1,OUTPUT);
pinMode(lMotorDPin2,OUTPUT);
pinMode(lMotorPWMPin,OUTPUT);
  setRightMotor (0);
  setLeftMotor (0);
  
}
void setRightMotor (int PWM){
  if(PWM==0){
    digitalWrite(rMotorDPin1,LOW);
    digitalWrite(rMotorDPin2,LOW);
  }
  else{
    if(PWM>0){
      digitalWrite( rMotorDPin2 ,HIGH);
      digitalWrite( rMotorDPin1 ,LOW);
    }
    else{
      digitalWrite( rMotorDPin2 ,LOW);
      digitalWrite( rMotorDPin1 ,HIGH);
    }
    analogWrite(rMotorPWMPin,abs(PWM));
  }
}
void setLeftMotor(int PWM){
  if(PWM==0){
    digitalWrite(lMotorDPin1,LOW);
    digitalWrite(lMotorDPin2,LOW);
  }
  else{
    if(PWM>0){
      digitalWrite( lMotorDPin2 ,HIGH);
      digitalWrite( lMotorDPin1 ,LOW);
    }
    else{
      digitalWrite( lMotorDPin2 ,LOW);
      digitalWrite( lMotorDPin1 ,HIGH);
    }
    analogWrite(lMotorPWMPin,abs(PWM));
  }
}
