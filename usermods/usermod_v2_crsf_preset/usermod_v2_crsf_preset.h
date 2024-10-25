#pragma once

#include "wled.h"

#define RCPin 2 // No semicolon here
volatile long StartTime = 0;
volatile long CurrentTime = 0;
long lastCheck = 0; // Store the last time pulses were checked
int pwm;
int lastpreset = 0;

class CrsfUsermod : public Usermod
{
private:
public:
  // Make PulseTimer static so it can be used as a callback

  void setup()
  {
    pinMode(RCPin, INPUT_PULLUP);               
  }

  void loop()
  {
    long currentMillis = millis();         // Get current time in milliseconds
    if (currentMillis - lastCheck >= 1000) // Check if 1 second has passed
    {
      lastCheck = currentMillis;           
      pwm = pulseIn(RCPin, LOW) - 18000;
      DEBUG_PRINTLN(pwm);
      if(pwm >= 20 && pwm <= 100 && lastpreset != 1){
        applythispreset(1);
      }
      if(pwm >= 200 && pwm <= 300 && lastpreset != 2){
        applythispreset(2);
      }
    }
  }

  static void applythispreset(int calledpreset)
  {
    applyPreset(calledpreset);
    lastpreset = calledpreset;
    DEBUG_PRINT("applied preset ");
    DEBUG_PRINTLN(calledpreset);
  }

  uint16_t getId()
  {
    return USERMOD_ID_CRSF_PRESET;
  }
};