extern const float rightEncoderResolution = 1562; 
extern const float leftEncoderResolution = 1562; 
extern const float gearRatio = 1;  
extern const float dt = 0.01; 
extern const float wheelRadius = 0.04;  
extern const float robotRadius = 0.14;  
char rEncoderPinA = 2 , rEcnoderPinB = 11 , lEncoderPinA = 3 ,lEncoderPinB = 12  ;
extern float rCurrentEncoderValue = 0.0;
extern float rPreviousEncoderValue = 0.0;
extern float lCurrentEncoderValue = 0.0;
extern float lPreviousEncoderValue = 0.0;
extern float rFilteredEncoderValue = 0.0;
extern double rFilteredInput = 0.0; 
extern float lFilteredEncoderValue = 0.0;
extern double lFilteredInput = 0.0; 
extern double leftMotorTargetRPM = 0.0 ;
extern double rightMotorTargetRPM = 0.0 ;
extern double leftMotorCurrentRPM = 0.0 ;
extern double rightMotorCurrentRPM = 0.0 ;
const float filterAlpha = 0.2; 
 double rMotorPWM , lMotorPWM ; 
const double Kp = 1.1;  // Proportional gain
const double Ki = 3.4;  // Integral gain
const double Kd = 0.05;
double rightRotations ;
double prevMillis = 0 ;
#include <Encoder.h>
#include <Arduino.h>
#include <PID_v1.h>
 Encoder rEncoder(rEncoderPinA,rEcnoderPinB);
 Encoder lEncoder(lEncoderPinA,lEncoderPinB);
 PID rPID((&rFilteredInput), &rMotorPWM, &rightMotorTargetRPM, Kp, Ki, Kd, DIRECT);
 PID lPID(&lFilteredInput, &lMotorPWM, &leftMotorTargetRPM, Kp, Ki, Kd, DIRECT);

void setCurrentRPM(){


    float rRevolutions = (rFilteredEncoderValue - rPreviousEncoderValue) / rightEncoderResolution;
float lRevolutions = (lFilteredEncoderValue - lPreviousEncoderValue) / leftEncoderResolution;
  
  // Calculate RPM

  
 rightMotorCurrentRPM = (rRevolutions / .0138 ) * 60.0;

 leftMotorCurrentRPM =  (lRevolutions / .0138 ) * 60.0;
rPreviousEncoderValue = rFilteredEncoderValue;
lPreviousEncoderValue = lFilteredEncoderValue;

}
float applyLowPassFilter(float input, float previousValue, float alpha) {
  return (1 - alpha) * previousValue + alpha * input;
}
void setTargetRPM(double linearVelocity , double angularVelocity ){
    float leftWheelVelocity = linearVelocity - (angularVelocity * robotRadius);
  float rightWheelVelocity = linearVelocity + (angularVelocity * robotRadius);

  // Calculate the RPM for each wheel
  leftMotorTargetRPM = (leftWheelVelocity * 60.0) / (2 * M_PI * wheelRadius);
  rightMotorTargetRPM = (rightWheelVelocity * 60.0) / (2 * M_PI * wheelRadius);
}
void getCurrentEncodersValues(){
  rCurrentEncoderValue = (float)rEncoder.read() *-1;
  lCurrentEncoderValue = (float)lEncoder.read() ;
}
void applyFilters1(){
  rFilteredEncoderValue =  applyLowPassFilter(rCurrentEncoderValue, rFilteredEncoderValue, filterAlpha);
  lFilteredEncoderValue =  applyLowPassFilter(lCurrentEncoderValue, lFilteredEncoderValue, filterAlpha);
}
void applyFilters2(){
  rFilteredInput = applyLowPassFilter(rightMotorCurrentRPM,rFilteredInput, filterAlpha);
lFilteredInput = applyLowPassFilter(leftMotorCurrentRPM,lFilteredInput, filterAlpha);
rPID.Compute();
lPID.Compute();
}
void initMidLayer(){
  rPID.SetOutputLimits(0, 255);
  rPID.SetSampleTime(dt * 1000); // Convert to milliseconds
  rPID.SetMode(AUTOMATIC);
 
    lPID.SetOutputLimits(-255, 255);
  lPID.SetSampleTime(dt * 1000); // Convert to milliseconds
  lPID.SetMode(AUTOMATIC);
 // Serial.begin(9600);
}
void midLayerProcess(double linearVelocity , double angularVelocity ){
/* Serial.print(rightMotorCurrentRPM);
  Serial.print(",");
   Serial.println(rightMotorTargetRPM);*/
  setTargetRPM(linearVelocity , angularVelocity );
     prevMillis = millis();
  getCurrentEncodersValues();
  applyFilters1();
  setCurrentRPM();
  applyFilters2();
 
  delay(dt * 1000);

}
int getRPWM(){
  return rMotorPWM ;
  
}
int getLPWM(){
  return lMotorPWM ;
  
}
float getRightTicks(){
  return rFilteredEncoderValue ;
}
float getLeftTicks(){
  return lFilteredEncoderValue ;
}
