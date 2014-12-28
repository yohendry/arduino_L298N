/*
L298N.cpp - Library for L298N motor driver
Created by Yohendry Hurtado, 28 dec 2014
Released into the public domain.
*/

#include "Arduino.h"
#include "L298N.h"

L298N::L298N(int ena, int in1, int in2, int in3, int in4, int enb) {
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);
  _ena = ena;
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
  _enb = enb;
}

void L298N::drive_motors(int speed, int delay_time) {
  analogWrite(_ena,speed);
  analogWrite(_enb,speed);
  delay(delay_time);
}

void L298N::forward(int speed, int delay_time) {
  this->setup_motors(HIGH,LOW,HIGH,LOW);
  this->drive_motors(speed,delay_time);
}

void L298N::turn_right(int speed, int delay_time) {
  this->setup_motors(LOW,HIGH,HIGH,LOW);
  this->drive_motors(speed,delay_time);
}

void L298N::turn_left(int speed, int delay_time) {
  this->setup_motors(HIGH,LOW,LOW,HIGH);
  this->drive_motors(speed,delay_time);
}

void L298N::backward(int speed, int delay_time) {
  this->setup_motors(LOW,HIGH,LOW,HIGH);
  this->drive_motors(speed,delay_time);
}

void L298N::full_stop(int delay_time) {
  this->setup_motors(LOW,LOW,LOW,LOW);
  this->drive_motors(0,delay_time);
}


void L298N::setup_motors(int state1, int state2, int state3, int state4) {
  digitalWrite (_in1, state1);
  digitalWrite (_in2, state2);
  digitalWrite (_in3, state3);
  digitalWrite (_in4, state4);
}
