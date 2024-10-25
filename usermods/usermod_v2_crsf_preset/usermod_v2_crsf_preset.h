#pragma once

#include "wled.h"

#define RCPin 2 // No semicolon here
volatile long StartTime = 0;
volatile long CurrentTime = 0;
volatile long pulses = 0;
volatile long checkpulses = 0;
long lastCheck = 0; // Store the last time pulses were checked

class CrsfUsermod : public Usermod
{
private:
public:
  // Make PulseTimer static so it can be used as a callback
  static void PulseTimer()
  {
    CurrentTime = micros();
    if (CurrentTime > StartTime)
    {
      checkpulses = CurrentTime - StartTime; // Calculate pulse width
      if (checkpulses < 2010)
      {
        pulses = CurrentTime - StartTime;
      }
      StartTime = CurrentTime; // Update start time
    }
  }

  void setup()
  {
    pinMode(RCPin, INPUT_PULLUP);                                      // Use RCPin here correctly
    attachInterrupt(digitalPinToInterrupt(RCPin), PulseTimer, CHANGE); // Attach the interrupt
  }

  void loop()
  {
    long currentMillis = millis();         // Get current time in milliseconds
    if (currentMillis - lastCheck >= 1000) // Check if 1 second has passed
    {
      lastCheck = currentMillis;           // Update the last check time
      DEBUG_PRINTLN(pulses);               // Print pulses once every second
      if (pulses >= 900 && pulses <= 1100) // Corrected pulse range check
      {
        applythispreset(1);
        DEBUG_PRINTLN("preset one applied");
      }
    }
  }

  static void applythispreset(int calledpreset)
  {
    applyPreset(calledpreset);
    DEBUG_PRINT("applied preset ");
    DEBUG_PRINTLN(calledpreset);
  }

  uint16_t getId()
  {
    return USERMOD_ID_CRSF_PRESET;
  }
};