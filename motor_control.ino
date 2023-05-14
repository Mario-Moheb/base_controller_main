

const int enA = 5;
  const int in1 = 6;
  const int in2 = 7;
  const int enB = 10; 
  const int in3 = 8;
  const int in4 = 9;
void initMotors(){
      pinMode(enA,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(enB,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);

}
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
