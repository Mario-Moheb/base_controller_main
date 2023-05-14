   #define ENC_LEFT_A 3
  #define ENC_RIGHT_A 2
  #define ENC_LEFT_B 12
  #define ENC_RIGHT_B 11


  void readRightEncoder(){
    int b = digitalRead(ENC_RIGHT_B);
    if(b > 0){
      currentRightTickCount--;
    }
    else{
      currentRightTickCount++;
    }
 
  }
   void readLeftEncoder(){
    int b = digitalRead(ENC_LEFT_B);
    if(b > 0){
      currentLeftTickCount++;
    }
    else{
      currentLeftTickCount--;
    }
 
  }
  void initEncoders(){
         pinMode(ENC_LEFT_A,INPUT);
    pinMode(ENC_RIGHT_A,INPUT);
    pinMode(ENC_LEFT_B,INPUT);
    pinMode(ENC_RIGHT_B,INPUT);
    attachInterrupt(digitalPinToInterrupt(ENC_RIGHT_A),readRightEncoder,RISING);
  attachInterrupt(digitalPinToInterrupt(ENC_LEFT_A),readLeftEncoder,RISING);
  }
