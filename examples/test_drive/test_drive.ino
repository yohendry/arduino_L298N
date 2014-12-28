#include <L298N.h>

L298N motors(6,8,7,2,3,4); //motors(ENA,IN1,IN2,IN3,IN4,ENB)
int time_delay = 200;
int speed = 150;
void setup()
{
}

void loop()
{
  motors.forward(speed,time_delay);
  motors.full_stop(time_delay);
  motors.turn_right(speed,time_delay);
  motors.full_stop(time_delay);
  motors.turn_left(speed,time_delay);
  motors.full_stop(time_delay);
  motors.backward(speed,time_delay);
}
