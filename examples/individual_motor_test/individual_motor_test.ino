#include <L298N.h>
const int ENA = 6;
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 2;
const int IN4 = 4;
const int ENB = 3;
L298N driver(ENA,IN1,IN2,IN3,IN4,ENB); 
int time_delay = 500;
int speed = 150;
void setup()
{
}

void loop()
{
  drive(L298N::MOTOR_A,HIGH,LOW);
  driver.full_stop(10);
  drive(L298N::MOTOR_A,LOW,HIGH);
  driver.full_stop(10);
  drive(L298N::MOTOR_B,HIGH,LOW);
  driver.full_stop(10);
  drive(L298N::MOTOR_B,LOW,HIGH);
  driver.full_stop(10);
  drive(L298N::MOTOR_A,LOW,HIGH);
  drive(L298N::MOTOR_B,LOW,HIGH);
  driver.full_stop(10);
  drive(L298N::MOTOR_A,HIGH,LOW);
  drive(L298N::MOTOR_B,HIGH,LOW);
  driver.full_stop(10);
}

void drive(int motor,int state1,int state2) {
  driver.setup_motor(motor,state1,state2);
  driver.drive_motor(motor,speed);
  delay(time_delay);
}