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
  driver.forward(speed,time_delay);
  driver.full_stop(time_delay);
  driver.turn_right(speed,time_delay);
  driver.full_stop(time_delay);
  driver.turn_left(speed,time_delay);
  driver.full_stop(time_delay);
  driver.backward(speed,time_delay);
}
