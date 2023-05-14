double twistToRightWheel(double linearVelocity , double angularVelocity){
   return (linearVelocity- angularVelocity * wheelBase / 2.0) / wheelRadius; 
}
double twistToLeftWheel(double linearVelocity ,double angularVelocity){
    return (linearVelocity- angularVelocity * wheelBase / 2.0) / wheelRadius ;
}

int targetTicksRate (unsigned int ticksPerMeter , int targetSpeed , int intervalInMs){
  int targetTicksRate ;

  return targetTicksRate ;
}

int currnetTicksRate(int prevTicks , int currentTicks , int intervalInMs){
  int currentTicksRate ;


  return currentTicksRate ;
}
