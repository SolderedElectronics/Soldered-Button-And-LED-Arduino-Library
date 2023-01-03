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

class ButtonAndLED : public EasyC
{
  public:
    ButtonAndLED();
    void ledOn();
    void ledOn(byte pwmValue);
    void ledOff();
    bool getBtnState();    

  protected:
    void initializeNative();

  private:
  int pin;
  byte pwm = 128;
};

#endif
