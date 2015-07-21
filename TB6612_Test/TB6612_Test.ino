#include "MotorControl.h"


MotorControl motor1(2, 4, 3);
MotorControl motor2(7, 8, 9);

int buttonRed = 13;
int buttonGreen = 12;
int buttonYellow = 11;
int buttonBlue = 10;

int buttonRedState = HIGH;
int buttonGreenState = HIGH;
int buttonYellowState = HIGH;
int buttonBlueState = HIGH;

void setup()
{
  Serial.begin(115200);

  /* add setup code here */
  motor1.init();
  motor2.init();
}

void loop()
{
  /* add main program code here */

  bool updateState = false;

  if (digitalRead(buttonRed) != buttonRedState)
  {
    buttonRedState = digitalRead(buttonRed);
    updateState = true;
  }
  if (digitalRead(buttonGreen) != buttonGreenState)
  {
    buttonGreenState = digitalRead(buttonGreen);
    updateState = true;
  }
  if (digitalRead(buttonYellow) != buttonYellowState)
  {
    buttonYellowState = digitalRead(buttonYellow);
    updateState = true;
  }
  if (digitalRead(buttonBlue) != buttonBlueState)
  {
    buttonBlueState = digitalRead(buttonBlue);
    updateState = true;
  }

  if (updateState)
  {
    if (LOW == buttonGreenState) {
      motor1.start(HIGH == buttonBlueState, HIGH == buttonYellowState ? 127 : 255);
    }
    else 
    {
      motor1.stop();
    }
    if (LOW == buttonRedState) {
      motor2.start(HIGH == buttonBlueState, HIGH == buttonYellowState ? 127 : 255);
    }
    else
    {
      motor2.stop();
    }
  }
}
