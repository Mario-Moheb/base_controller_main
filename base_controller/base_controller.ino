
  #include <ros.h>
  #include <std_msgs/Int16.h>
  #include <geometry_msgs/Twist.h>

  #include "motor_control.h"
#include "midLayer.h" 
  ros::NodeHandle nh;

  std_msgs::Int16 right_wheel_tick_count;
ros::Publisher rightPub("rwheel", &right_wheel_tick_count);
 
std_msgs::Int16 left_wheel_tick_count;
ros::Publisher leftPub("lwheel", &left_wheel_tick_count);


  double linearVelocity ;
double angularVelocity ;

void setTargetVelocity(const geometry_msgs::Twist& cmdVel){
  linearVelocity = cmdVel.linear.x ;
  angularVelocity = cmdVel.angular.z ;
}
 ros::Subscriber<geometry_msgs::Twist> subCmdVel("cmd_vel", &setTargetVelocity );


void setup() {
 initMotors(6,7,5,8,9,10);
 initMidLayer();
 nh.getHardware()->setBaud(115200);

    nh.initNode();

     nh.advertise(rightPub);
  nh.advertise(leftPub);

    nh.subscribe(subCmdVel);
}

void loop() {
  nh.spinOnce();
  midLayerProcess(linearVelocity,angularVelocity);
  setRightMotor(getRPWM());
setLeftMotor(getLPWM());
left_wheel_tick_count.data = getLeftTicks() ;
right_wheel_tick_count.data = getRightTicks() ;
leftPub.publish( &left_wheel_tick_count );
    rightPub.publish( &right_wheel_tick_count );
}
