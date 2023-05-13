   #define ENC_LEFT_A 3
  #define ENC_RIGHT_A 2
  #define ENC_LEFT_B 12
  #define ENC_RIGHT_B 11
  
  int currentRightTickCount = 0 ;
  int currentLeftTickCount = 0 ;

  int prevRightTickCount = 0;
  int prevLeftTickCount = 0;

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
