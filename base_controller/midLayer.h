#ifndef MIDLAYER_H
#define MIDLAYER_H


void initMidLayer() ;
void applyFilters2();
void applyFilters1();
void getCurrentEncodersValues();
void setTargetRPM(double linearVelocity , double angularVelocity );
float applyLowPassFilter(float input, float previousValue, float alpha);
void setCurrentRPM();
void midLayerProcess(double linearVelocity , double angularVelocity);
int getRPWM();
int getLPWM();
float getRightTicks();
  float getLeftTicks();
#endif
