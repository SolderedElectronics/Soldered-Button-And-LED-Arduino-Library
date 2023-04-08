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

// Define all modes of LED
#define LED_OFF         0
#define LED_ON          1
#define LED_PWM         2
#define LED_FADING      3
#define LED_ON_AND_HOLD 4

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
    void ledFading(uint32_t _delay);
    void turnLedOnAndHold(uint32_t _time);

  protected:
    void initializeNative();

  private:
    void sendValues(uint8_t _mode, uint32_t _parameter);
    int pin;
};

#endif
