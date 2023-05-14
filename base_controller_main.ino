  #include <ros.h>
    #include <std_msgs/Int16.h>
  #include <geometry_msgs/Twist.h>
     double linearVelocity ;
    double angularVelocity  ;
    
 ros::NodeHandle nh;
   std_msgs::Int16 right_wheel_tick_count;
ros::Publisher rightPub("rwheel", &right_wheel_tick_count);
 
std_msgs::Int16 left_wheel_tick_count;
ros::Publisher leftPub("lwheel", &left_wheel_tick_count);

std_msgs::Int16 right_wheel_pwm;
ros::Publisher rightPubPwm("rpwm", &right_wheel_pwm);

std_msgs::Int16 left_wheel_pwm;
ros::Publisher leftPubPwm("lpwm", &left_wheel_pwm);
  void setTargetVelocity (const geometry_msgs::Twist& cmdVel){
   linearVelocity = cmdVel.linear.x ;
  angularVelocity = cmdVel.angular.z ;
}
  ros::Subscriber<geometry_msgs::Twist> subCmdVel("cmd_vel", &setTargetVelocity );

void initROS(){
     nh.getHardware()->setBaud(115200);

    nh.initNode();
      nh.advertise(rightPubPwm);
  nh.advertise(leftPubPwm);
     nh.advertise(rightPub);
  nh.advertise(leftPub);

    nh.subscribe(subCmdVel);
}


void publishData(){
  leftPub.publish( &left_wheel_tick_count );
    rightPub.publish( &right_wheel_tick_count );
    leftPubPwm.publish( &left_wheel_pwm );
    rightPubPwm.publish( &right_wheel_pwm );
}

#define rTicksPerMeter 1550
#define lTicksPerMeter 1555

#define wheelRadius .04
#define wheelBase .28
#define interval 100
    #include <PID_v1.h>
  int currentRightTickCount = 0 ;
  int currentLeftTickCount = 0 ;

  int prevRightTickCount = 0;
  int prevLeftTickCount = 0;
unsigned long prevMillis = 0;

   double rightPWM = 0;
    double leftPWM = 0;
double leftTargetTicksRate  ;
double rightTargetTicksRate ;

double leftCurrentTicksRate ;
double rightCurrentTicksRate ;
double  Kp = 0,Ki = 0, Kd =0 ;
  PID rightMotorPid (&rightCurrentTicksRate,&rightPWM,(&rightTargetTicksRate),Kp,Ki,Kd,DIRECT);
  PID leftMotorPid (&leftCurrentTicksRate,&leftPWM,(&leftTargetTicksRate),Kp,Ki,Kd,DIRECT);
void setup() {
  initROS();
initMotors();
initEncoders();

}

void loop() {
   nh.spinOnce();
   if((millis()-prevMillis)>=interval){
  double leftWheelTargetVelocity = twistToLeftWheel (linearVelocity,angularVelocity);
 double rightWheelTargetVelocity = twistToRightWheel (linearVelocity,angularVelocity);

double leftTargetTicksRate = targetTicksRate(lTicksPerMeter , leftWheelTargetVelocity ,interval);
double rightTargetTicksRate = targetTicksRate(rTicksPerMeter , rightWheelTargetVelocity ,interval);

double leftCurrentTicksRate = currnetTicksRate(prevLeftTickCount , currentLeftTickCount,interval);
double rightCurrentTicksRate = currnetTicksRate(prevRightTickCount , currentRightTickCount,interval);
leftMotorPid.Compute();
rightMotorPid.Compute();

setLeftMotor(leftPWM);
setRightMotor(rightPWM);

    publishData();
     prevMillis = millis();
   }
}
