// 
// 
// 

#include "MotorControl.h"

void MotorControl::init()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pinPwm, OUTPUT);

  stop();
}

void MotorControl::start(boolean forward, int speed)
{
  analogWrite(pinPwm, speed);
  digitalWrite(pin1, forward ? HIGH : LOW);
  digitalWrite(pin2, forward ? LOW : HIGH);
}

void MotorControl::stop()
{
  analogWrite(pinPwm, 0);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
}
