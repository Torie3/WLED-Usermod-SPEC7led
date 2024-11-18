#include "wled.h"
/*
 * This v1 usermod file allows you to add own functionality to WLED more easily
 * See: https://github.com/Aircoookie/WLED/wiki/Add-own-functionality
 * EEPROM bytes 2750+ are reserved for your custom use case. (if you extend #define EEPSIZE in const.h)
 * If you just need 8 bytes, use 2551-2559 (you do not need to increase EEPSIZE)
 *
 * Consider the v2 usermod API if you need a more advanced feature set!
 */

// Use userVar0 and userVar1 (API calls &U0=,&U1=, uint16_t)

#define RCPin 2 // No semicolon here
volatile long StartTime = 0;
volatile long CurrentTime = 0;
long lastCheck = 0; // Store the last time pulses were checked
int pwm;
int lastpreset = 0;
static void applythispreset(int calledpreset);
static void getPWM();

// gets called once at boot. Do all initialization that doesn't depend on network here
void userSetup()
{
    pinMode(RCPin, INPUT_PULLUP);
}

// gets called every time WiFi is (re-)connected. Initialize own network interfaces here
void userConnected()
{
}

// loop. You can use "if (WLED_CONNECTED)" to check for successful connection
/*void userLoop()
{
    long currentMillis = millis();        // Get current time in milliseconds
    if (currentMillis - lastCheck >= 200) // Check if 1 second has passed
    {
        lastCheck = currentMillis;
        pwm = pulseIn(RCPin, LOW) - 18000;
        DEBUG_PRINTLN(pwm);
        if (pwm >= 20 && pwm <= 100 && lastpreset != 6)
        {
            applythispreset(6);
        }
        if (pwm >= 200 && pwm <= 300 && lastpreset != 5)
        {
            applythispreset(5);
        }
        if (pwm >= 400 && pwm <= 500 && lastpreset != 4)
        {
            applythispreset(4);
        }
        if (pwm >= 600 && pwm <= 700 && lastpreset != 3)
        {
            applythispreset(3);
        }
        if (pwm >= 800 && pwm <= 900 && lastpreset != 2)
        {
            applythispreset(2);
        }
        if (pwm >= 1000 && pwm <= 1100 && lastpreset != 1)
        {
            applythispreset(1);
        }
    }
}
*/
void userLoop()
{
    long currentMillis = millis();
    if (currentMillis - lastCheck >= 200)
    {
        lastCheck = currentMillis;
        getPWM();
        checkPWM();
    }
}

static void applythispreset(int calledpreset)
{
    applyPreset(calledpreset);
    lastpreset = calledpreset;
    DEBUG_PRINT("applied preset ");
    DEBUG_PRINTLN(calledpreset);
}

static void getPWM()
{
    pwm = pulseIn(RCPin, LOW) - 18000;
    DEBUG_PRINTLN(pwm);
}

static void checkPWM()
{
    for (int i = 1; i <= 6; i++)
    {
        if (pwm >= (i*100)-100 && pwm <= i*100 && lastpreset != 7-i){
            applythispreset(7-i);
        }
    }
}
