// MotorControl.h

#ifndef _MOTORCONTROL_h
#define _MOTORCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

class MotorControl
{
  protected:
    int pin1;
    int pin2;
    int pinPwm;

  public:
    MotorControl(int pin1, int pin2, int pinPwm) : 
      pin1(pin1), pin2(pin2), pinPwm(pinPwm)
    {
    }

    void init();
    void start(boolean forward, int speed);
    void stop();
};

#endif

