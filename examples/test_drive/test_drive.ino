#include <L298N.h>

L298N motors(6,8,7,2,3,4); //motors(ENA,IN1,IN2,IN3,IN4,ENB)

void setup()
{
}

void loop()
{
  forward(200,100);
  full_stop(100);
  turn_right(200,100);
  full_stop(100);
  turn_left(200,100);
  full_stop(100);
  backward(200,100);
}

void forward(int value,int time){
  motors.setup_motors(HIGH,LOW,HIGH,LOW);
  motors.drive_motors(value,time);
}

void turn_right(int value,int time){
  motors.setup_motors(LOW,HIGH,HIGH,LOW);
  motors.drive_motors(value,time);
}

void turn_left(int value,int time){
  motors.setup_motors(HIGH,LOW,LOW,HIGH);
  motors.drive_motors(value,time);
}

void backward(int value,int time){
  motors.setup_motors(LOW,HIGH,LOW,HIGH);
  motors.drive_motors(value,time);
}

void full_stop(int time){
  motors.setup_motors(LOW,LOW,LOW,LOW);
  motors.drive_motors(0,time);
}
