/**
 **************************************************
 *
 * @file        Button-and-LED-easyC-SOLDERED.h
 * @brief       Header file for Button & LED code.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#ifndef __BUTTON_AND_LED__
#define __BUTTON_AND_LED__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

// Define states of the button
#define BUTTON_IDLE      0
#define BTN_CLICK        1
#define BTN_DOUBLE_CLICK 2
#define BTN_LONG_PRESS   3
#define BTN_LONG_RELEASE 4

class ButtonAndLED : public EasyC
{
  public:
    ButtonAndLED();
    void ledOn();
    void ledOn(byte pwmValue);
    void ledOff();
    byte getBtnState();

  protected:
    void initializeNative();

  private:
    int pin;
    byte pwm = 128;
};

#endif
