   #define ENC_LEFT_A 3
  #define ENC_RIGHT_A 2
  #define ENC_LEFT_B 12
  #define ENC_RIGHT_B 11
  const int enA = 5;
  const int in1 = 6;
  const int in2 = 7;
  const int enB = 10; 
  const int in3 = 8;
  const int in4 = 9;

void setLeftMotor(int pwm){
  if(pwm==0){
     digitalWrite(in4,LOW);
     digitalWrite(in3,LOW);
  }
  else{
    if(pwm>0){
      digitalWrite(in4,HIGH);
      digitalWrite(in3,LOW);
    }
    else{
            digitalWrite(in4,LOW);
      digitalWrite(in3,HIGH);
    }
    analogWrite(enB,abs(pwm));
  }
}

void setRightMotor(int pwm){
   if(pwm==0){
     digitalWrite(in2,LOW);
     digitalWrite(in1,LOW);
  }
  else{
    if(pwm>0){
      digitalWrite(in2,HIGH);
      digitalWrite(in1,LOW);
    }
    else{
            digitalWrite(in2,LOW);
      digitalWrite(in1,HIGH);
    }
    analogWrite(enB,abs(pwm));
  }
}
