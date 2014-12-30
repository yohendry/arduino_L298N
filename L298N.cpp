/*
L298N.cpp - Library for L298N motor driver
Created by Yohendry Hurtado, 28 dec 2014
Released into the public domain.
*/

#include "Arduino.h"
#include "L298N.h"

struct Motor {
  int in1;
  int in2;
  int pwn;
};

Motor motors[2];

L298N::L298N(int ena, int in1, int in2, int in3, int in4, int enb) {
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);

  motors[0].in1 = in1;
  motors[0].in2 = in2;
  motors[0].pwn = ena;

  motors[1].in1 = in3;
  motors[1].in2 = in4;
  motors[1].pwn = enb;
}

void L298N::drive_motors(int speed) {
  this->drive_motor(this->MOTOR_A,speed);
  this->drive_motor(this->MOTOR_B,speed);
}

void L298N::drive_motor(int motor_index, int speed) {
  analogWrite(motors[motor_index].pwn,speed);
}

void L298N::forward(int speed, int delay_time) {
  this->setup_motors(HIGH,LOW,HIGH,LOW);
  this->drive_motors(speed);
  delay(delay_time);
}

void L298N::turn_right(int speed, int delay_time) {
  this->setup_motors(LOW,HIGH,HIGH,LOW);
  this->drive_motors(speed);
  delay(delay_time);
}

void L298N::turn_left(int speed, int delay_time) {
  this->setup_motors(HIGH,LOW,LOW,HIGH);
  this->drive_motors(speed);
  delay(delay_time);
}

void L298N::backward(int speed, int delay_time) {
  this->setup_motors(LOW,HIGH,LOW,HIGH);
  this->drive_motors(speed);
  delay(delay_time);
}

void L298N::full_stop(int delay_time) {
  this->setup_motors(LOW,LOW,LOW,LOW);
  this->drive_motors(0);
  delay(delay_time);
}


void L298N::setup_motors(int state1, int state2, int state3, int state4) {
  L298N::setup_motor(this->MOTOR_A,state1,state2);
  L298N::setup_motor(this->MOTOR_B,state3,state4);
}

void L298N::setup_motor(int motor_index, int state1, int state2) {
  digitalWrite(motors[motor_index].in1, state1);
  digitalWrite(motors[motor_index].in2, state2);
}
